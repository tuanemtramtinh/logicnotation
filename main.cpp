#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPriority(char c){
    if (c == '~') return 5;
    if (c == '&') return 4;
    if (c == '|') return 3;
    if (c == '<') return 0;
    if (c == '-') return 1;
    if (c == '>') return 2;
    return -1;
}

bool alphabetCheck(char c){
    if (c >= 97 && c <= 122) return true;
    return false;
}

bool logicOperatorCheck(char c){
    if (c == '~' || c == '&' || c == '|' || c == '<' || c == '-' || c == '>' || c == '(' || c == ')') return true;
    return false;
}

string LogicInfix2Postfix(string infix){
    stack <char> logicStack;
    string postfix = "";
    int infix_size = infix.size();
    for (int i = 0; i < infix_size; i++){
        if (alphabetCheck(infix[i])) postfix += infix[i];
        if (logicOperatorCheck(infix[i])){
            if (logicStack.empty() && infix[i] != ')') logicStack.push(infix[i]);
            else if (infix[i] == ')'){
                while (logicStack.top() != '('){
                    char temp = logicStack.top();
                    if (temp == '<') temp = '>';
                    else if (temp == '>') temp = '<';
                    postfix += temp;
                    logicStack.pop();
                }
                logicStack.pop();
            }
            else if (infix[i] == '(' || getPriority(infix[i]) > getPriority(logicStack.top())) logicStack.push(infix[i]);
            else{
                if (!logicStack.empty()){
                    while (getPriority(infix[i]) <= getPriority(logicStack.top())){
                        postfix += logicStack.top();
                        logicStack.pop();
                        if (logicStack.empty()) break;
                    }
                    logicStack.push(infix[i]);
                }
            }
        }
        if (i == infix_size - 1 && !logicStack.empty()){
            while (!logicStack.empty()){
                char temp = logicStack.top();
                string s = "";
                while (temp == '>' || temp == '<' || temp == '-')z
                postfix += temp;
                logicStack.pop();
            }
        }
    }
    return postfix;
}

int main() {
    string str;
    getline(cin, str);
    string postfix = LogicInfix2Postfix(str);
    cout << postfix;
    return 0;
}

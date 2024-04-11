#include <iostream>
#include <stack>
#include <string>

using namespace std;

int op(char ch)
{
    switch(ch) {
    case '[': return 0;
    case ']': return 1;
    case '{': return 2;
    case '}': return 3;
    case '(': return 4;
    case ')': return 5;
    case '<': return 6;
    case '>': return 7;
    default: return -1;
    }
}

int main()
{
    string s;
    stack<char> st;

    cin >> s;

    int minCost = 0;
    bool possible = true;

    for(unsigned int i = 0; i < s.size(); i++) {
        int j = op(s[i]);
        if (j == -1) continue;

        if (j & 1) {
            // closing
            if (st.empty()) {
                possible = false;
                break;
            }
            char c = st.top();
            st.pop();
            if ((   op(c) ^ 1) != j) {
                minCost++;
            }
        } else {
            st.push(s[i]);
        }
    }

    if(!st.empty()) {
        possible = false;
    }
    if(possible) {
        cout << minCost << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
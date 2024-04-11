#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> st;
    string s;
    
    cin >> s;
    
    int n = s.length(), m = 0;
    
    for(int i = 0; i < n; ++i) {
            if(s[i] == '(')
                    st.push(s[i]);
            else
                if(st.empty())
                              ++m;
                else
                    st.pop();
    }
    
    cout << n - m - st.size();
    
    cin >> n;
    
    return 0;
}
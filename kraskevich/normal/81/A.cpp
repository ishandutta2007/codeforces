#include <iostream>
#include <deque>
using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    deque<char> st;
    int n = s.length();
    char cur;
    
    for(int i = 0; i < s.length(); ++i) {
            if(st.empty() || st.front() != s[i])
                          st.push_front(s[i]);
            else
                st.pop_front();
    }
    for(int i = st.size() - 1; i >= 0; --i)
            cout << st[i];
    
    cin >> s;
    
    return 0;
}
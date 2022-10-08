
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
int n;

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    int cons = 0;
    set<char> st;
    int previ = 0;
    for(int i = 0; i < n; i++) {
        if(vowel(s[i])) {
            cons = 0;
            st.clear();
        }else {
            cons++;
            st.insert(s[i]);
            if(cons >= 3 && st.size() >= 2) {
                // typo
                cons = 0;
                st.clear();
                i--;
                cout << s.substr(previ, i - previ + 1) << " ";
                previ = i + 1;
            }
        }
    }
    cout << s.substr(previ) << endl;
}
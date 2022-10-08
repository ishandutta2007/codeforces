
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                for(char c : {'a', 'b', 'c'}) {
                    if((i == 0 || s[i - 1] != c) && (i == n - 1 || s[i + 1] != c)) {
                        s[i] = c;
                        break;
                    }
                }
            }else if((i > 0 && s[i - 1] == s[i]) || (i < n - 1 && s[i + 1] == s[i])) {
                cout << -1 << endl;
                goto endloop;
            }
        }
        cout << s << endl;
        endloop:;
    }
}
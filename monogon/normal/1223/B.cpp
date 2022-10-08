
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
string s, t;
int cs[26], ct[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> s >> t;
        fill(cs, cs + 26, 0);
        fill(ct, ct + 26, 0);
        for(int i = 0; i < s.length(); i++) {
            cs[s[i] - 'a']++;
            ct[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cs[i] > 0 && ct[i] > 0) {
                cout << "YES" << endl;
                goto endloop;
            }
        }
        cout << "NO" << endl;
        endloop:;
    }
}
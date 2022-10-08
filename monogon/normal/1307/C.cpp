
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    ll ans = 0;
    for(int k = 0; k < 26; k++) {
        for(int l = 0; l < 26; l++) {
            int cnt = 0;
            ll cnt2 = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'a' + l) {
                    cnt2 += cnt;
                }
                if(s[i] == 'a' + k) {
                    cnt++;
                }
            }
            ans = max(ans, 1LL * cnt);
            ans = max(ans, cnt2);
        }
    }
    cout << ans << endl;
}
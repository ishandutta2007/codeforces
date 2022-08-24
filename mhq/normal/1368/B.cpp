#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s = "codeforces";
ll pw(ll x, int t) {
    ll c = 1;
    for (int i = 1; i <= t; i++) {
        c *= x;
        if (c > 1e17) return c;
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    assert(s.size() == 10);
    ll k;
    cin >> k;
    ll c = 1;
    while (pw(c + 1, 10) < k) c++;
    for (int cnt = 0; cnt <= 10; cnt++) {
        ll f1 = pw(c + 1, cnt);
        ll f2 = pw(c, 10 - cnt);
        if (f1 * f2 >= k) {
            string ans;
            for (int i = 0; i < cnt; i++) {
                ans += string((int)(c + 1), s[i]);
            }
            for (int i = cnt; i < 10; i++) {
                ans += string((int)(c), s[i]);
            }
            cout << ans;
            return 0;
        }
    }
    assert(false);
    return 0;
}
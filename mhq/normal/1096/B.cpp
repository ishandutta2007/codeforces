#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
int n;
string s;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> s;
    int max_pref = 0;
    int max_suf = 0;
    while (s[max_pref] == s[0]) max_pref++;
    while (s[n - 1 - max_suf] == s[n - 1]) max_suf++;
    ll ans = max_pref + max_suf + 1;
    // a|b|a|a
    // abaa
    // a|a [][][] aaa
    if (s[0] == s[n - 1]) {
        ans += 1LL * (max_pref) * (max_suf);
    }
    cout << ans % mod;
    return 0;
}
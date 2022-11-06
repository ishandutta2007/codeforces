#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 2;
const int M = 998244353;

int n, pref[N], pw[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * 10 % M;
    for (int i = 1; i <= n; i++)
        pref[i] = (pref[i - 1] + (i + 1) * pw[i]) % M;
    for (int sz = 1; sz <= n; sz++) {
        int ans = 0;
        if (sz == n) {
            cout << 10;
            return 0;
        }
        ans += 2 * 10 * 9 * pw[n - sz - 1] % M;
        ans %= M;
        if (sz == n - 1) {
            cout << ans << ' ' ;
            continue;
        }
        ans += 10 * 9 * 9 * pw[n - sz - 2] % M * (n - sz - 1) % M;
        ans %= M;
        cout << ans << ' ';

    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int Maxn = 41;
const int Maxm = 20;
 
int n, k;
ll mask[Maxn];
int dp[1 << Maxm];
int res = 1;
 
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; scanf("%d", &num);
            if (num == 1) {
                mask[i] |= 1ll << ll(j);
                mask[j] |= 1ll << ll(i);
            }
        }
        mask[i] |= 1ll << ll(i);
    }
    int a = n / 2;
    for (int i = 1; i < 1 << a; i++) {
        ll tot = (1ll << ll(n)) - 1ll;
        for (int j = 0; j < a; j++) if (i & 1ll << ll(j))
            tot &= mask[j];
        if ((tot & i) == i)
            dp[i] = __builtin_popcount(i);
    }
    for (int j = 0; j < a; j++)
        for (int i = 0; i < 1 << a; i++) if (!(i & 1 << j)) {
            int ni = (i | 1 << j);
            dp[ni] = max(dp[ni], dp[i]);
        }
    int b = n - a;
    for (int i = 0; i < 1 << b; i++) {
        ll tot = (1ll << ll(n)) - 1ll;
        for (int j = a; j < n; j++) if (i & 1ll << ll(j - a))
            tot &= mask[j];
        if (((tot >> ll(a)) & i) == i) {
            ll tmp = (1 << a) - 1;
            res = max(res, dp[tot & tmp] + __builtin_popcount(i));
        }
    }
    ld ans = ld(res - 1) * k * k / 2 / res;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
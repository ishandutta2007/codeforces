#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 300005, MOD = 998244353;

map<pair<int, int>, int> cp;
int n, cf[N], cs[N];
pair<int, int> a[N];
long long t = 1, f = 1, s = 1, p = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        (t *= i) %= MOD;
        (f *= (++cf[a[i].fi])) %= MOD;
        (s *= (++cs[a[i].se])) %= MOD;
        (p *= (++cp[a[i]])) %= MOD;
    }
    t -= f + s - p;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i].se < a[i - 1].se)
        {
            t -= p;
            break;
        }
    cout << ((t % MOD) + MOD) % MOD;
}
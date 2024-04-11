#include <bits/stdc++.h>

using namespace std;

long long f[500005];
int n, m;
long long a[500005];
long long b[500005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    mt19937 rng(1007050321);
    for (int i = 1; i <= 500000; ++i) f[i] = 500001LL * rng() + i;
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) b[i] = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            b[v] ^= f[u];
        }
        map <long long, long long> mp;
        for (int i = 1; i <= n; ++i) if (b[i]) mp[b[i]] += a[i];
        long long ans = 0;
        for (auto x: mp) ans = __gcd(ans, x.second);
        cout << ans << '\n';
    }
    return 0;
}
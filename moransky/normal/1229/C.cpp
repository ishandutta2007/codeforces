#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, m, q, d[N], s[N], top;

LL ans;

vector<int> g[N];

LL inline calc(int x) {
    return 1ll * g[x].size() * (d[x] - g[x].size());
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        d[u]++, d[v]++;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; i++) ans += calc(i);
    printf("%lld\n", ans);
    scanf("%d", &q);
    while (q--) {
        int v; scanf("%d", &v);
        ans -= calc(v);
     
        for (int x: g[v]) {
            ans -= calc(x);
            g[x].pb(v);
            ans += calc(x);
        }
        g[v].clear();
        printf("%lld\n", ans);
    }
    return 0;
}
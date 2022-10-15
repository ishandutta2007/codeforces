#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector <int> deg(n + 1), a(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        vector < pair <int, int> > E;
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++;
            deg[v]++;
            E.push_back({u, v});
        }
        if (m % 2 == 1) {
            int ans = 0x3f3f3f3f;
            for (int i = 1; i<= n; i++) if (deg[i] % 2) ans = min(ans, a[i]);
            for (auto v : E) if (deg[v.first] % 2 == 0 && deg[v.second] % 2 == 0) {
                ans = min(ans, a[v.first] + a[v.second]);
            }
            printf("%d\n", ans);
        } else {
            puts ("0");
        }
    }
}
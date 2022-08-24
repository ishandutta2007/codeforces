#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e5 + 100;
vector < int > g[maxN];
int lst[maxN];
vector < pair < int, int > > ed;
const int BLOCK = sqrt(maxN);
int q;
int hi[maxN], lo[maxN];
bool was[maxN];
int que[maxN];
vector < int > in_blocks[maxN];
bool will[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        ed.emplace_back(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        lst[i] = i;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> que[i];
    }
    for (int i = 0; i <= q; i += BLOCK) {
        int l = i;
        int r = min(i + BLOCK - 1, q - 1);
        memset(hi, 0, sizeof hi);
        memset(lo, 0, sizeof lo);
        memset(was, 0, sizeof was);
        memset(will, 0, sizeof will);
        for (int it = l; it <= r; it++) {
            will[que[it]] = true;
        }
        for (int it = 1; it <= n; it++) in_blocks[it].clear();
        for (auto it : ed) {
            if (will[it.first] && will[it.second]) {
                in_blocks[it.first].push_back(it.second);
                in_blocks[it.second].push_back(it.first);
            }
            if (lst[it.first] > lst[it.second]) {
                lo[it.first]++;
                hi[it.second]++;
            }
            else {
                lo[it.second]++;
                hi[it.first]++;
            }
        }
        ll ans = 0;
        for (int j = 1; j <= n; j++) {
            ans += 1LL * lo[j] * hi[j];
        }
        if (i == 0) cout << ans << '\n';
        if (i == q) return 0;
        for (int it = l; it <= r; it++) {
            int v = que[it];
            ans -= 1LL * lo[v] * hi[v];
            lo[v] = g[v].size();
            hi[v] = 0;
            if (!was[v]) {
                was[v] = true;
                for (int u : g[v]) {
                    if (lst[u] > lst[v]) {
                        ans -= 1LL * lo[u] * hi[u];
                        lo[u]--;
                        hi[u]++;
                        ans += 1LL * lo[u] * hi[u];
                    }
                }
            }
            else {
                for (int u : in_blocks[v]) {
                    if (lst[u] > lst[v]) {
                        ans -= 1LL * lo[u] * hi[u];
                        lo[u]--;
                        hi[u]++;
                        ans += 1LL * lo[u] * hi[u];
                    }
                }
            }
            lst[v] = n + it + 1;
            cout << ans << '\n';
        }
    }
    return 0;
}
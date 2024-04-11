#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 4e5 + 10;
int p[2][maxN];
vector<int> g[maxN];
bool used[maxN];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            used[i] = 0;
        }
        for (int x = 0; x < 2; x++) {
            for (int i = 1; i <= n; i++) {
                cin >> p[x][i];
            }
        }
        for (int i = 1; i <= n; i++) {
            g[p[0][i]].emplace_back(p[1][i]);
            g[p[1][i]].emplace_back(p[0][i]);
        }
        int ans = 1;
        const int mod = (int)1e9 + 7;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                ans = (2LL * ans) % mod;
                dfs(i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
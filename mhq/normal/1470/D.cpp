#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
vector<int> g[maxN];
bool used[maxN];
vector<int> ord;
void dfs(int v) {
    ord.emplace_back(v);
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}
int id[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            used[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        ord.clear();
        dfs(1);
        bool hs = false;
        for (int i = 1; i <= n; i++) {
            hs |= !used[i];
        }
        if (hs) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n";
        }
        for (int i = 1; i <= n; i++) {
            id[ord[i - 1]] = i;
        }
        for (int i = 1; i <= n; i++) used[i] = false;
        vector<int> xx;
        for (int i : ord) {
            bool can = true;
            for (int to : g[i]) {
                if (id[to] < id[i] && used[to]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                used[i] = true;
                xx.emplace_back(i);
            }
        }
        cout << xx.size() << '\n';
        for (int v : xx) cout << v << " ";
        cout << '\n';
    }
    return 0;
}
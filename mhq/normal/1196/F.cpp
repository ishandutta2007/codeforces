#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int add = (int)1e6 + 10;
map < pair < int, int >, ll > mp;
const int maxN = 2 * (int)1e5 + 100;
vector < pair < int, int > > g[maxN];
int n, m, k;
bool used[maxN];
vector < int > ord;
int id[maxN];
void dfs(int v) {
    used[v] = true;
    ord.push_back(v);
    id[v] = ord.size() - 1;
    for (auto it : g[v]) {
        if (used[it.first]) continue;
        dfs(it.first);
    }
}
ll d[405][405];
void solve() {
    cin >> n >> m >> k;
    set < pair < ll, pair < int, int > > > pq;
    vector < pair < int, pair < int, int > > > eds;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        eds.emplace_back(w, make_pair(x, y));
    }
    sort(eds.begin(), eds.end());
    eds.resize(k);
    for (auto it : eds) {
        int x = it.second.first;
        int y = it.second.second;
        g[x].emplace_back(y, it.first);
        g[y].emplace_back(x, it.first);
    }
    vector < ll > all;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        if (!used[i]) {
            ord.clear();
            dfs(i);
        }
        for (int j = 0; j < ord.size(); j++) {
           // cout << ord[j] << " ";
            for (int k = 0; k < ord.size(); k++) {
                d[j][k] = 1e18;
            }
        }
        //cout << endl;
        for (int v : ord) {
            for (auto it : g[v]) {
                d[id[v]][id[it.first]] = it.second;
            }
        }
        for (int it = 0; it < ord.size(); it++) {
            for (int j = 0; j < ord.size(); j++) {
                for (int k = 0; k < ord.size(); k++) {
                    d[j][k] = min(d[j][k], d[j][it] + d[it][k]);
                }
            }
        }
        for (int j = 0; j < ord.size(); j++) {
            for (int k = j + 1; k < ord.size(); k++) {
                all.emplace_back(d[j][k]);
            }
        }
    }
    sort(all.begin(), all.end());
    cout << all[k - 1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    int tst = 1;
    while (tst--) solve();
    return 0;
}
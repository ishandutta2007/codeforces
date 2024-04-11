/*input
10 5
2 4
4 7
7 1
2 5
4 9
1 10
5 8
4 6
4 3
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 2e5 + 5;

vector<vector<int> > a(N);
int n, m;
int par[N], depth[N], child[N], deg[N];

void dfs(int u, int p) {
    par[u] = p;
    child[u] = 1;
    for (auto v : a[u]) {
        if (v == p) continue;
        deg[u]++; depth[v] = depth[u] + 1;
        dfs(v, u);
        child[u] += child[v];
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 1);
    priority_queue<pair<int, int> > pq;
    loop(i, 2, n) {
        if (a[i].size() == 1)
            pq.push({depth[i], i});
    }
    int ans = 0;
    while (!pq.empty() && m > 0) {
        auto [val, u] = pq.top(); pq.pop();
        ans += val;
        if (par[u] != u) {
            deg[par[u]]--;
            if (deg[par[u]] == 0) {
                pq.push({depth[par[u]] - (child[par[u]] - 1), par[u]});
            }
        }
        m--;
    }
    cout << ans << endl;
}
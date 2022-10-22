#include <bits/stdc++.h>
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update
> stat_set;
 
 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
 
const int inf = 1e9;
const ll inf64 = 1e18;
 
const int N = 1e5 + 5;
 
int n, m;
int last_pos[N];
vector<int> gg[N];
vector<int> g[N];
int seq[2 * N];
 
int main() {
 
#ifdef debug
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
 
        if (u > v) {
            swap(u, v);
        }
 
        g[u].push_back(v);
 
        gg[u].push_back(v);
        gg[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++) {
        last_pos[i] = i;
    }
 
    ll total = 0;
 
    for (int v = 1; v <= n; v++) {
//        cout << v << " : " << (int) g[v].size() << " " << (int) gg[v].size() << "\n";
        int hlp = (int) g[v].size();
        total += 1ll * hlp * ((int) gg[v].size() - hlp);
    }
 
    cout << total << "\n";
 
    for (int i = 1; i <= n; i++) {
        seq[i] = i;
    }
 
    int q;
    cin >> q;
 
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int pos = n + i + 1;
        seq[pos] = x;
 
        vector<int> tmp = g[x];
 
        total -= 1ll * (int) g[x].size() * ((int) gg[x].size() - (int) g[x].size());
        for (int to_pos : tmp) {
            int to = seq[to_pos];
            total -= 1ll * (int) g[to].size() * ((int) gg[to].size() - (int) g[to].size());
        }
 
        for (int to_pos : tmp) {
            int to = seq[to_pos];
            g[to].push_back(pos);
        }
 
        g[x].clear();
 
        for (int to_pos : tmp) {
            int to = seq[to_pos];
            total += 1ll * (int) g[to].size() * ((int) gg[to].size() - (int) g[to].size());
        }
 
        cout << total << "\n";
    }
 
    return 0;
}
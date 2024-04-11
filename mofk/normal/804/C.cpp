#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
vi adj[300005];
vi in[300005];
int ans[300005];
int dad[300005];

void dfs(int u) {
    set <int> used;
    ff(i, 0, (int)in[u].size() - 1) {
        int x = in[u][i];
        if (ans[x]) used.insert(ans[x]);
    }
    int cur = 1;
    ff(i, 0, (int)in[u].size() - 1) {
        int x = in[u][i];
        if (!ans[x]) {
            while (used.find(cur) != used.end()) used.erase(cur), ++cur;
            ans[x] = cur; ++cur;
        }
    }
    ff(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs(v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ff(i, 1, N) {
        int sz, x; cin >> sz;
        ff(r, 1, sz) cin >> x, in[i].pb(x);
    }
    int u, v;
    ff(i, 1, N - 1) cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1);
    ff(i, 1, M) if (!ans[i]) ans[i] = 1;
    int mx = 0; ff(i, 1, M) mx = max(mx, ans[i]);
    cout << mx << endl;
    ff(i, 1, M) cout << ans[i] << ' '; cout << endl;
    return 0;
}
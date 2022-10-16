#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

int N, Q;
int dad[300005];
vi child[300005];
int sz[300005];
int ans[300005];
ii opt[300005];
int h[300005];

void dfs(int u) {
    sz[u] = 1;
    ff(i, 0, (int)child[u].size() - 1) {
        int v = child[u][i];
        h[v] = h[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}

void find_ans(int u) {
    ii start = ii(h[u], u);
    ff(i, 0, (int)child[u].size() - 1) {
        int v = child[u][i];
        find_ans(v);
        start = min(start, opt[v]);
    }
    int v = start.second;
    while (v && !ans[v] && 2 * sz[u] >= sz[v]) { ans[v] = u; v = dad[v]; }
    opt[u] = ii(h[v], v);
}

int main(void) {
    cin >> N >> Q;
    ff(i, 2, N) { cin >> dad[i]; child[dad[i]].pb(i); }
    h[1] = 1;
    dfs(1);
    find_ans(1);
    ff(i, 1, Q) {
        int u; cin >> u; cout << ans[u] << "\n";
    }
    return 0;
}
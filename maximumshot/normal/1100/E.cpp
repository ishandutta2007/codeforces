#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, m;
vector< pii > g[N];
int color[N];
int W[N];
pii es[N];

bool dfs(int v, int mx) {
    color[v] = 1;
    for(pii e : g[v]) {
        int to, w;
        tie(to, w) = e;
        if(w <= mx) continue;
        if(color[to] == 1) {
            return 1;
        }else if(!color[to]) {
            if(dfs(to, mx)) return 1;
        }
    }
    color[v] = 2;
    return 0;
}

bool check(int mx) {
    fill(color + 1, color + n + 1, 0);
    for(int v = 1;v <= n;v++) {
        if(!color[v] && dfs(v, mx)) return 0;
    }
    return 1;
}

int used[N];
int tops[N], sz;
int pos[N];

void dfs1(int v, int mx) {
    used[v] = 1;
    for(pii e : g[v]) {
        if(used[e.first] || e.second <= mx) continue;
        dfs1(e.first, mx);
    }
    tops[sz++] = v;
}

void print(int mx) {
    for(int v = 1;v <= n;v++) {
        if(used[v]) continue;
        dfs1(v, mx);
    }
    reverse(tops, tops + sz);
    for(int i = 0;i < sz;i++) {
        pos[tops[i]] = i;
    }
    vector< int > res;
    for(int i = 0;i < m;i++) {
        int u, v;
        tie(u, v) = es[i];
        if(pos[u] > pos[v] && W[i] <= mx) {
            res.push_back(i + 1);
        }
    }
    cout << (int)res.size() << "\n";
    for(int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int w, u, v, i = 0;i < m;i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        W[i] = w;
        es[i] = {u, v};
    }

    if(check(0)) {
        cout << "0 0\n";
        return 0;
    }

    int bl = 0;
    int br = inf + 1;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    cout << br << " ";

    print(br);

    return 0;
}
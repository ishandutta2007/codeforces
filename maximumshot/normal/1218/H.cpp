#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

typedef
tree<
        pair< ll, int >,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update
> stat_set;


const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, q;
int a[N];
int res[N];
vector<int> qs[N];
ll ms[N / 2];
bool on_cycle[N];
int cycle_id;
int used[N];
vector<int> cycle[N];
vector<int> g[N];
int depth[N];
int tin[N], tout[N], timer;
vector<int> depths[N];

void dfs(int v) {
    tin[v] = timer++;
    depths[depth[v]].push_back(tin[v]);
    for (int to : g[v]) {
        depth[to] = depth[v] + 1;
        dfs(to);
    }
    tout[v] = timer;
    if (!on_cycle[v]) {
        for (auto query : qs[v]) {
            if (depth[v] + ms[query] < N) {
                res[query] = lower_bound(depths[depth[v] + ms[query]].begin(), depths[depth[v] + ms[query]].end(),
                        tout[v]) -
                        lower_bound(depths[depth[v] + ms[query]].begin(), depths[depth[v] + ms[query]].end(),
                                    tin[v]);
            }
        }
    }
}

int vertices[2 * N], ptr;
vector<int> values[2 * N], ff[2 * N];

void add_fen(vector<int>& ff, int pos, int val) {
    for (int cur = pos; cur < (int) ff.size(); cur |= (cur + 1)) {
        ff[cur] += val;
    }
}

int get_fen(const vector<int>& ff, int pos) {
    int score = 0;
    for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1) {
        score += ff[cur];
    }
    return score;
}

void write_vertices(int v, int I) {
    vertices[ptr++] = depth[v] - I;
    for (int to : g[v]) {
        write_vertices(to, I);
    }
}

void go(int rt, int I, int type, int L) {
    queue<int> que;
    que.push(rt);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        int md = (depth[v] - I) % L;
        if (md < 0) md += L;
        int pos = lower_bound(values[md].begin(), values[md].end(), depth[v] - I) - values[md].begin();
        add_fen(ff[md], pos, type);
        for (int to : g[v]) {
            que.push(to);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        res[i] = -1;
        ll m;
        int y;
        cin >> m >> y;
        ms[i] = m;
        qs[y].push_back(i);
    }

    int cur_used = 0;
    for (int v = 1; v <= n; v++) {
        if (used[v]) continue;
        int x = v;
        vector<int> path;
        cur_used++;
        while (!used[x]) {
            path.push_back(x);
            used[x] = cur_used;
            x = a[x];
        }
        if (used[x] != cur_used) continue;
        reverse(path.begin(), path.end());
        while (path.back() != x) path.pop_back();
        reverse(path.begin(), path.end());
        cycle_id++;
        for (int u : path) {
            on_cycle[u] = true;
        }
        cycle[cycle_id] = path;
    }

    for (int v = 1; v <= n; v++) {
        if (!on_cycle[v]) {
            g[a[v]].push_back(v);
        }
    }

    for (int v = 1; v <= n; v++) {
        if (on_cycle[v]) {
            dfs(v);
        }
    }

    for (int cid = 1; cid <= cycle_id; cid++) {
        int L = (int) cycle[cid].size();
        ptr = 0;
        for (int it = 0; it < L; it++) {
            write_vertices(cycle[cid][it], it);
        }
        for (int i = 0; i < ptr; i++) {
            vertices[i + ptr] = vertices[i] - L;
        }
        ptr <<= 1;
        sort(vertices, vertices + ptr);
        ptr = unique(vertices, vertices + ptr) - vertices;
        for (int i = 0; i < L; i++) {
            values[i].clear();
            ff[i].clear();
        }
        for (int i = 0; i < ptr; i++) {
            int x = vertices[i];
            x = (x % L + L) % L;
            values[x].push_back(vertices[i]);
        }
        for (int i = 0; i < L; i++) {
            ff[i].resize(values[i].size(), 0);
        }
        for (int it = 0; it < L; it++) {
            go(cycle[cid][it], it, +1, L);
        }
        for (int it = 0; it < L; it++) {
            int y = cycle[cid][(it + L - 1) % L];
            int I = L + it - 1;
            for (auto query : qs[y]) {
                int md = int((ms[query] - I) % ll(L));
                if (md < 0) md += L;
                ll value = ms[query] - I;
                value = min(value, ll(inf));
//                res[query] = values[md].order_of_key(make_pair(value, inf));
                int pos = upper_bound(values[md].begin(), values[md].end(), int(value)) - values[md].begin() - 1;
                res[query] = get_fen(ff[md], pos);
            }
            if (it + 1 == L) break;
            int ny = cycle[cid][it];
            go(ny, I + 1, +1, L);
            go(ny, I + 1 - L, -1, L);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
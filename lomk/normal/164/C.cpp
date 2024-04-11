/*input
10 2
699300217 520863246 750739
158802156 776305466 388177
556239371 900142068 187357
776489007 632844082 238502
361186251 188888255 483934
154509737 958411614 416129
777488390 894434905 348016
558588067 756129429 77163
938486404 462702730 640265
593570035 525346237 888643
*/
#include <bits/stdc++.h>
using namespace std;
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
 
const int INF = numeric_limits<int>::max() - 1;
struct MinCostMaxFlow {
    struct Edge {
        int u, v, cap, f, cost, id; // f is the remaining flow
        Edge (int _u, int _v, int _cap, int _f, int _cost, int _id): u(_u), v(_v), cap(_cap), f(_f), cost(_cost), id(_id) {};
    };
    queue<int> q;
    vector<Edge> e;
    vector<vector<int> > a;
    vector<int> dis, par;
    int n, S, T;
    bool SPFA() {
        fill(dis.begin(), dis.end(), INF); fill(par.begin(), par.end(), -1);
        dis[S] = 0; q.push(S);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto id : a[u]) {
                auto &t = e[id]; auto v = e[id].v;
                if (t.f && dis[v] > dis[u] + t.cost) {
                    dis[v] = dis[u] + t.cost;
                    par[v] = id;
                    q.push(v);
                }
            }
        }
        if (dis[T] != INF) return true;
        return false;
    }
    int dfs() {
        int delta = INF, u = T;
        while (u != S) {
            delta = min(delta, e[par[u]].f);
            u = e[par[u]].u;
        }
        u = T;
        while (u != S) {
            e[par[u]].f -= delta;
            e[par[u] ^ 1].f += delta;
            u = e[par[u]].u;
        }
        return delta;
    }
    void init(int _n, int _S, int _T) {
        n = _n; S = _S; T = _T; e.clear();
        a.assign(n, vector<int>()); dis.assign(n, 0); par.assign(n, 0);
    }
    void addEdge(int u, int v, int cap, int cost, int id) {
        e.push_back({u, v, cap, cap, cost, id});
        e.push_back({v, u, 0, 0, -cost, -1});
        a[u].push_back(e.size() - 2);
        a[v].push_back(e.size() - 1);
    }
    pair<int, int> solve() {
        pair<int, int> ret = {0, 0};
        while (SPFA()) ret.fi += dfs();
        for (auto &rx : e) if (rx.cap > rx.f) ret.se += (rx.cap - rx.f) * rx.cost;
        return ret;
    }
} MCMF;
 
struct Task {
    int l, r, c;
    Task(int _l, int _t, int _c) {
        l = _l;
        r = l + _t - 1;
        c = _c;
    }
};
ostream &operator<<(ostream &os, Task X) {
    os << X.l << sp << X.r << sp << X.c;
    return os;
}
 
int n, m;
int S = 0, T = 1;
vector<Task> tasks;
vector<int> all;
 
int gPiv(int p) {
    return T + p + 1;
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef in1code
    freopen("1test.inp", "r", stdin);
#endif
    cin >> n >> m;
    loop(i, 1, n) {
        int l, r, c;
        cin >> l >> r >> c;
        tasks.push_back(Task(l, r, c));
        all.push_back(tasks.back().l); all.push_back(tasks.back().r);
    }
 
    all.push_back(INF);
    sort(all.begin(), all.end()); all.resize(distance(all.begin(), unique(all.begin(), all.end())));
    for (auto &it : tasks) {
        it.l = lower_bound(all.begin(), all.end(), it.l) - all.begin();
        it.r = lower_bound(all.begin(), all.end(), it.r) - all.begin();
    }
 
    MCMF.init(gPiv(all.size() - 1) + 1, S, T);
    MCMF.addEdge(S, gPiv(0), m, 0, -1);
    loop(i, 0, all.size() - 1) {
        if (i != all.size() - 1)
            MCMF.addEdge(gPiv(i), gPiv(i + 1), INF, 0, -1);
        else
            MCMF.addEdge(gPiv(i), T, INF, 0, -1);
    }
 
    loop(i, 0, n - 1) {
        MCMF.addEdge(gPiv(tasks[i].l), gPiv(tasks[i].r + 1), 1, -tasks[i].c, i);
    }
 
    MCMF.solve();
    vector<bool> ans(n, 0);
    map<int, int> mark;
    for (auto it : MCMF.e) {
        mark[it.id] = it.cap - it.f;
    }
    loop(i, 0, n - 1) {
        if (mark[i] != 0) cout << 1 << sp;
        else cout << 0 << sp;
    }
    cout << endl;
}
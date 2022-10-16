/*input
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
*/
#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second

const int N = 1e5 + 5;

enum EdgeType {
    NONE, // khng cy no cha
    ANY, // tt c cc cy u cha
    ATL // t nht 1 cy cha
};

struct Edge {
    int u, v, c, id;
    Edge(int _u, int _v, int _c, int _id): u(_u), v(_v), c(_c), id(_id) {};
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

vector <pair<int, int>> g[N];
int low[N], num[N], Time = 0;
int n, m;
EdgeType res[N];
vector <Edge> edges;

void dfs(int u, int idx) {
    num[u] = low[u] = ++Time;
    for (auto &e : g[u]) {
        int v = e.fi; int id = e.se;
        if (id == idx) continue;
        if (num[v] == 0) {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                // nu cnh l cu th mi cy u phi cha
                res[id] = EdgeType::ANY;
            }
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
}
void solve(vector<Edge> &pen) { // x l cc nhm cnh c cng trng s
    if (pen.empty()) return;

    // khi to  th ni cc thnh phn lin thng
    for (int i = 0; i < pen.size(); i++) {

        // s dng nh cha trong dsu lm nh i din cho thnh phn lin thng
        pen[i].u = dsu.find(pen[i].u); pen[i].v = dsu.find(pen[i].v);
        g[pen[i].u].clear(); g[pen[i].v].clear();
        num[pen[i].u] = num[pen[i].v] = 0;
    }

    for (auto e : pen) {
        if (e.u == e.v) {
            // nu 2 nh cng thuc 1 thnh phn lin thng
            res[e.id] = EdgeType::NONE;
        }
        else {
            // nu 2 nh ni 2 thnh phn lin thng khc nhau li vi nhau
            res[e.id] = EdgeType::ATL;
            // thm cnh vo  th
            g[e.v].push_back({e.u, e.id});
            g[e.u].push_back({e.v, e.id});
        }
    }

    // tm cnh cu
    for (auto &e : pen) if (num[e.u] == 0) dfs(e.u, -1);
    // sau khi hon thnh, ta thc hin hp cc cnh vo cy khung
    for (auto &e : pen) dsu.join(e.u, e.v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c, i});
    }

    dsu.init(n);

    sort(edges.begin(), edges.end(), [](Edge x, Edge y) {
        return x.c < y.c;
    });

    vector<Edge> pen;
    for (auto &e : edges) {
        if (!pen.empty() && pen.back().c == e.c) {
            pen.push_back(e);
        }
        else {
            solve(pen);
            pen = {e};
        }
    }
    solve(pen);

    // in ra kt qu
    for (int i = 1; i <= m; i++) {
        if (res[i] == EdgeType::NONE) cout << "none\n";
        else if (res[i] == EdgeType::ANY) cout << "any\n";
        else cout << "at least one\n";
    }
}
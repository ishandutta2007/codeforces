#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 305;
const int INF = (int)1e9;
vector < int > g[maxN];
int n;
bool used[maxN];
int mt[maxN];
int par[maxN];
int we[maxN];
bool kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == 0 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) cin >> we[i];
    for (int i = 1; i <= n; i++) {
        memset(used, 0, sizeof used);
        kuhn(i);
    }
    for (int i = 1; i <= n; i++) {
        par[mt[i]] = i;
    }
}
struct edge{
    int to, id, cap, flow;
    edge(int _to, int _id, int _cap, int _flow) {
        to = _to;
        id = _id;
        cap = _cap;
        flow = _flow;
    }
};
vector < edge > edges[2 * maxN];
void addEdge(int from, int to, int cap) {
    edges[from].emplace_back(to, edges[to].size(), cap, 0);
    edges[to].emplace_back(from, edges[from].size() - 1, cap, cap);
}
int s, t;
int sum = 0;
void build() {
    s = 0;
    t = 2 * n + 1;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (we[i] > 0) {
            addEdge(i, t, we[i]);
        }
        else {
            sum += we[i];
            addEdge(s, i, -we[i]);
        }
        for (int to : g[i]) {
            addEdge(i, to + n, INF);
        }
        addEdge(par[i] + n, i, INF);
    }
}
int d[2 * maxN];
void bfs() {
    memset(d, -1, sizeof d);
    queue < int > q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& ed : edges[v]) {
            if (d[ed.to] == -1 && ed.flow < ed.cap) {
                d[ed.to] = d[v] + 1;
                q.push(ed.to);
            }
        }
    }
}
int ptr[2 * maxN];
int dfs(int from, int lim) {
    if (lim == 0) return 0;
    if (from == t) return lim;
    for (; ptr[from] < edges[from].size(); ptr[from]++) {
        auto &ed = edges[from][ptr[from]];
        int to = ed.to;
        if (d[to] != d[from] + 1) continue;
        int add = dfs(to, min(lim, ed.cap - ed.flow));
        if (add != 0) {
            ed.flow += add;
            edges[to][ed.id].flow -= add;
            return add;
        }
    }
    return 0;
}
int goFlow() {
    int flow = 0;
    while (true) {
        bfs();
        if (d[t] == -1) {
            return flow;
        }
        while (true) {
            memset(ptr, 0, sizeof ptr);
            int add = dfs(s, 2 * INF);
            if (add == 0) {
                break;
            }
            flow += add;
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    build();
    //cout << goFlow();
    cout << sum + goFlow();
    return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
// http://e-maxx.ru/algo/dinic
#define y1 gogoggogogojs
int n, m;
const int maxN = 55;
int x1[maxN], y1[maxN], x2[maxN], y2[maxN];
const int MAXN = 550; //  
const ll INF = 1e18; // -

struct edge {
    int a, b;
    ll cap, flow;
};

int s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, ll cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, sizeof d);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

ll dfs (int v, ll flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

ll dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset(ptr, 0, sizeof ptr);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < int > byX, byY;
    byX.push_back(1);
    byX.push_back(n + 1);
    byY.push_back(1);
    byY.push_back(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        byX.push_back(x1[i]);
        byX.push_back(x2[i] + 1);
        byY.push_back(y1[i]);
        byY.push_back(y2[i] + 1);
    }
    sort(byX.begin(), byX.end());
    byX.erase(unique(byX.begin(), byX.end()), byX.end());
    sort(byY.begin(), byY.end());
    byY.erase(unique(byY.begin(), byY.end()), byY.end());
    int Xsz = byX.size();
    int Ysz = byY.size();
    for (int i = 0; i + 1 < byX.size(); i++) {
        for (int j = 0; j + 1 < byY.size(); j++) {
            int xa = byX[i];
            int xb = byX[i + 1] - 1;
            int ya = byY[j];
            int yb = byY[j + 1] - 1;
            for (int k = 1; k <= m; k++) {
                if (x1[k] <= xa && xb <= x2[k] && y1[k] <= ya && yb <= y2[k]) {
                    add_edge(i + 1, Xsz + j + 1, 1e15);
                    break;
                }
            }
        }
    }
    s = 0;
    t = Xsz + Ysz + 1;
    for (int i = 0; i + 1 < Xsz; i++) {
        add_edge(0, i + 1, byX[i + 1] - byX[i]);
    }
    for (int i = 0; i + 1 < Ysz; i++) {
        add_edge(i + Xsz + 1, t, byY[i + 1] - byY[i]);
    }
    cout << dinic();
    return 0;
}
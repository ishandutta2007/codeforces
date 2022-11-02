#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

const int INF = -1U >> 1;

struct MinCostFlow {
    struct edge {
        int n, f, c;
        edge* next, *rev;
        edge(int _n, int _f, int _c, edge* _next) :
            n(_n), f(_f), c(_c), next(_next) {}
    };

    vector<edge*> edges;

    MinCostFlow(int sze) { edges.resize(sze, (edge*) 0); }

    int addV() {
        edges.push_back((edge*) 0);
        return edges.size() - 1;
    }

    edge* makeE(int s, int t, int f, int c) {
        return edges[s] = new edge(t, f, c, edges[s]);
    }

    void addE(int s, int t, int f, int c) {
        edge* e1 = makeE(s, t, f, c), *e2 = makeE(t, s, 0, -c);
        e1->rev = e2, e2->rev = e1;
    }

    pll mcflow(int vs, int vt) {
        int n = edges.size();
        ll cflow = 0, ccost = 0;
        vector<ll> dist(n);
        vector<int> flow(n);
        vector<edge*> from(n);
        vector<bool> in(n);
        queue<int> que;

        while (1) {
            fill(dist.begin(), dist.end(), INF);
            fill(flow.begin(), flow.end(), 0);
            dist[vs] = 0;
            flow[vs] = INF;
            que.push(vs);

            while (!que.empty()) {
                int v = que.front(); que.pop();
                in[v] = 0;
                for (edge* e = edges[v]; e; e = e->next)
                    if (e->f) {
                        int nc = dist[v] + e->c;
                        if (nc < dist[e->n]) {
                            dist[e->n] = nc;
                            flow[e->n] = min(flow[v], e->f);
                            from[e->n] = e;
                            if (!in[e->n]) {
                                que.push(e->n);
                                in[e->n] = 1;
                            }
                        }
                    }
            }

            if (!flow[vt]) break;

            int f = flow[vt];
            cflow += f;
            ccost += f * dist[vt];

            int cur = vt;
            while (cur != vs) {
                edge* e = from[cur];
                e->f -= f;
                e->rev->f += f;
                cur = e->rev->n;
            }
        }

        return pll(cflow, ccost);
    }
};

const int MAXN = 55;

int n, k, cap[MAXN][MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> cap[i][j];

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        MinCostFlow net (n+1);
        net.addE(n, 0, mid, 0);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (cap[i][j])
                    net.addE(i, j, cap[i][j], 0), net.addE(i, j, INF, 1);
        pll p = net.mcflow(n, n-1);
        if (p.fi == mid && p.se <= k) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << '\n';
    return 0;
}
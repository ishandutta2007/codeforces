#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1005;
const int MAXK = 55;
const int INF = -1U >> 1;

bool ans[MAXN];

struct MinCostFlow {
    struct edge {
        int n, f, c;
        int id;
        edge* next, *rev;
        edge(int _n, int _f, int _c, edge* _next, int _id) :
            n(_n), f(_f), c(_c), next(_next), id(_id) {}
    };

    vector<edge*> edges;

    int addV() {
        edges.push_back((edge*) 0);
        return edges.size() - 1;
    }

    edge* makeE(int s, int t, int f, int c, int id) {
        return edges[s] = new edge(t, f, c, edges[s], id);
    }

    void addE(int s, int t, int f, int c, int id) {
        edge* e1 = makeE(s, t, f, c, id), *e2 = makeE(t, s, 0, -c, -1);
        e1->rev = e2, e2->rev = e1;
    }

    pii mcflow(int vs, int vt) {
        int n = edges.size();
        int cflow = 0, ccost = 0;
        vector<int> dist(n);
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

        for (int i=0; i<n; i++)
            for (edge* e = edges[i]; e; e = e->next)
                if (e->id != -1)
                    ans[e->id] = 1 - e->f;

        return pii(cflow, ccost);
    }
};

int n, k;
int s[MAXN], t[MAXN], c[MAXN];

map<int, int> mp;
int cnt;

MinCostFlow net;
int vs, vt;

void makeGraph() {
    for (int i=0; i<cnt; i++) net.addV();
    vs = net.addV(), vt = net.addV();

    net.addE(vs, 0, k, 0, -1);
    net.addE(cnt-1, vt, k, 0, -1);

    for (int i=0; i<cnt-1; i++) net.addE(i, i+1, k, 0, -1);
    for (int i=0; i<n; i++) net.addE(s[i], t[i], 1, -c[i], i);
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> t[i] >> c[i];
        t[i] += s[i];
        mp[s[i]] = 0;
        mp[t[i]] = 0;
    }

    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
        mp[it->fi] = cnt++;

    for (int i=0; i<n; i++)
        s[i] = mp[s[i]], t[i] = mp[t[i]];

    makeGraph();

    pii p = net.mcflow(vs, vt);

    for (int i=0; i<n; i++) cout << ans[i] << ' ';
    return 0;
}
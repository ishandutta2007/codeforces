#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <ios>

using namespace std;

typedef pair<int, int> pii;

const int INF = -1U >> 1;

struct MinCostFlow {
    struct edge {
        int n, f, c;
        edge* next, *rev;
        edge(int _n, int _f, int _c, edge* _next) :
            n(_n), f(_f), c(_c), next(_next) {}
    };

    vector<edge*> edges;

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

        return pii(cflow, ccost);
    }
};

const int MAXN = 105;

int n, m;
bool type[MAXN];
int str1[MAXN], str2[MAXN];
int ans;

void go1() { //kill all
    if (m < n) return;

    MinCostFlow net;
    for (int i=0; i<m+n; i++) net.addV();
    int vs = net.addV(), vt = net.addV(), vr = net.addV();

    for (int i=0; i<m; i++)
        net.addE(vs, i, 1, 0);
    for (int i=0; i<n; i++)
        net.addE(m+i, vt, 1, 0);
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (type[j]) { //attack
                if (str1[i] >= str2[j])
                    net.addE(i, m+j, 1, str2[j] - str1[i]);
            } else { //defense
                if (str1[i] > str2[j])
                    net.addE(i, m+j, 1, 0);
            }
    for (int i=0; i<m; i++)
        net.addE(i, vr, 1, -str1[i]);
    net.addE(vr, vt, m-n, 0);

    pii p = net.mcflow(vs, vt);
    if (p.first != m) return;
    ans = max(ans, -p.second);
}

void go2() { //not kill all
    MinCostFlow net;
    for (int i=0; i<m+n; i++) net.addV();
    int vs = net.addV(), vt = net.addV(), vr = net.addV();

    for (int i=0; i<m; i++)
        net.addE(vs, i, 1, 0);
    for (int i=0; i<n; i++)
        net.addE(m+i, vt, 1, 0);
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (type[j])
                if (str1[i] >= str2[j])
                    net.addE(i, m+j, 1, str2[j] - str1[i]);
    for (int i=0; i<m; i++)
        net.addE(i, vr, 1, 0);
    net.addE(vr, vt, m, 0);

    pii p = net.mcflow(vs, vt);
    ans = max(ans, -p.second);
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s >> str2[i];
        type[i] = s == "ATK";
    }
    for (int i=0; i<m; i++) cin >> str1[i];

    go1();
    go2();

    cout << ans << '\n';
    return 0;
}
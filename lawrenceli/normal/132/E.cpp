#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <ios>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 255;
const int MAXM = 30;
const int MAX = 10000;
const int INF = -1U >> 1;

int arr[MAXN];

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

    void mcflow(int vs, int vt, int vr, int vn, int vm) {
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

        vector<int> var (vn);
        vector<pii> ans;
        for (int i=0; i<vm; i++) {
            int cur = vr;
            while (cur != vt) {
                for (edge* e = edges[cur]; e; e = e->next) {
                    if (!e->f) {
                        e->f ++;
                        if (e->n < vn) var[e->n] = i;
                        cur = e->n;
                        break;
                    }
                }
            }
        }

        vector<int> num (vn, -1);

        for (int i=0; i<vn; i++) {
            if (num[var[i]] != arr[i])
                ans.push_back(pii(var[i], 0)), num[var[i]] = arr[i];
            ans.push_back(pii(var[i], 1));
        }

        cout << ans.size() << ' ' << ccost + MAX*vn << '\n';
        int cnt = 0;
        for (int i=0; i<ans.size(); i++) {
            if (!ans[i].second)
                cout << char(ans[i].first + 'a') << '=' << arr[cnt] << '\n';
            else {
                cout << "print(" << char(ans[i].first + 'a') << ")\n";
                cnt++;
            }
        }
    }
};

int n, m;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];

    MinCostFlow net;
    for (int i=0; i<n+n; i++) net.addV();
    int vs = net.addV(), vt = net.addV(), vr = net.addV();

    net.addE(vs, vr, m, 0);
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (arr[i] == arr[j])
                net.addE(i+n, j, 1, 0);
            else net.addE(i+n, j, 1, __builtin_popcount(arr[j]));

    for (int i=0; i<n; i++) {
        net.addE(vr, i, 1, __builtin_popcount(arr[i]));
        net.addE(i, i+n, 1, -MAX);
    }

    for (int i=0; i<m; i++) net.addE(vr, vt, 1, 0);
    for (int i=0; i<n; i++) net.addE(i+n, vt, 1, 0);

    net.mcflow(vs, vt, vr, n, m);
    return 0;
}
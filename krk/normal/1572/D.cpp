#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 20;
const int Inf = 1000000000;
const int MaxN = 1 << Maxn;
const int Maxm = 2000001;

int bits[MaxN];
int val[MaxN];
vector <ii> edges[Maxm];
vector <int> neigh[MaxN];
int n, k;
int N;

const int INF = 1000*1000*1000;

struct rib {
	int b, u, c, f;
	size_t back;
};

void add_rib (vector < vector<rib> > & g, int a, int b, int u, int c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back (r1);
	g[b].push_back (r2);
}

int Solve()
{
    vector <int> A, B;
    for (int i = 0; i < N; i++) if (!neigh[i].empty())
        if (bits[i] % 2 == 0) A.push_back(i);
        else B.push_back(i);
    n = int(A.size()) + int(B.size()) + 2;
    int s = 0, t = n - 1;
	vector < vector<rib> > g (n);
    for (int i = 0; i < A.size(); i++) {
        add_rib(g, s, i + 1, 1, 0);
        for (int j = 0; j < neigh[A[i]].size(); j++) {
            int ind = lower_bound(B.begin(), B.end(), neigh[A[i]][j]) - B.begin();
            add_rib(g, i + 1, int(A.size()) + 1 + ind, 1, Maxm - (val[A[i]] + val[B[ind]]));
        }
    }
    for (int i = 0; i < B.size(); i++)
        add_rib(g, int(A.size()) + 1 + i, t, 1, 0);
	int flow = 0,  cost = 0;
	while (flow < k) {
		vector<int> id (n, 0);
		vector<int> d (n, INF);
		vector<int> q (n);
		vector<int> p (n);
		vector<size_t> p_rib (n);
		int qh=0, qt=0;
		q[qt++] = s;
		d[s] = 0;
		while (qh != qt) {
			int v = q[qh++];
			id[v] = 2;
			if (qh == n)  qh = 0;
			for (size_t i=0; i<g[v].size(); ++i) {
				rib & r = g[v][i];
				if (r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0) {
						q[qt++] = r.b;
						if (qt == n)  qt = 0;
					}
					else if (id[r.b] == 2) {
						if (--qh == -1)  qh = n-1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}
		if (d[t] == INF)  break;
		int addflow = k - flow;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v];
			addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}
	return flow * Maxm - cost;
}

int main()
{
    scanf("%d %d", &n, &k);
    N = 1 << n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &val[i]);
        bits[i] = i? bits[i - (i & -i)] + 1: 0;
    }
    for (int b = 0; b < n; b++) {
        for (int i = 0; i < N; i++) if (bits[i] % 2 == 0) {
            int j = (i ^ (1 << b));
            edges[val[i] + val[j]].push_back(ii(i, j));
        }
        int nd = 3 * k;
        for (int i = Maxm - 1; i >= 0; i--) {
            for (int j = 0; j < edges[i].size() && nd > 0; j++) {
                int a = edges[i][j].first, b = edges[i][j].second;
                neigh[a].push_back(b);
                neigh[b].push_back(a);
                nd--;
            }
            edges[i].clear();
        }
    }
    cout << Solve() << endl;
    return 0;
}
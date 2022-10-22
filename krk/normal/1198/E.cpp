#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
};

int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
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
	memset (d, -1, N * sizeof d[0]);
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

int dfs (int v, int flow) {
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

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, N * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

const int Maxm = 55;

int n, m;
int r1[Maxm], c1[Maxm], r2[Maxm], c2[Maxm];
vector <int> unR, unC;
bool has[MAXN][MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &r1[i], &c1[i], &r2[i], &c2[i]);
        unR.push_back(r1[i]);
        unR.push_back(r2[i] + 1);
        unC.push_back(c1[i]);
        unC.push_back(c2[i] + 1);
    }
    sort(unR.begin(), unR.end()); unR.erase(unique(unR.begin(), unR.end()), unR.end());
    sort(unC.begin(), unC.end()); unC.erase(unique(unC.begin(), unC.end()), unC.end());
    N = int(unR.size()) + int(unC.size()) + 2;
    s = 0, t = N - 1;
    for (int i = 0; i < m; i++) {
        r1[i] = lower_bound(unR.begin(), unR.end(), r1[i]) - unR.begin();
        r2[i] = lower_bound(unR.begin(), unR.end(), r2[i] + 1) - unR.begin();
        c1[i] = lower_bound(unC.begin(), unC.end(), c1[i]) - unC.begin();
        c2[i] = lower_bound(unC.begin(), unC.end(), c2[i] + 1) - unC.begin();
        for (int r = r1[i]; r < r2[i]; r++)
            for (int c = c1[i]; c < c2[i]; c++)
                has[r][c] = true;
    }
    for (int i = 0; i + 1 < unR.size(); i++)
        add_edge(0, i + 1, unR[i + 1] - unR[i]);
    for (int i = 0; i + 1 < unC.size(); i++)
        add_edge(1 + int(unR.size()) + i, N - 1, unC[i + 1] - unC[i]);
    for (int i = 0; i < unR.size(); i++)
        for (int j = 0; j < unC.size(); j++) if (has[i][j])
            add_edge(i + 1, 1 + int(unR.size()) + j, INF);
    cout << dinic() << endl;
    return 0;
}
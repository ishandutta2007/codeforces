#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int MAXN = 20015;
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

int n, b, Q;
vector <ii> quer;
vector <ii> dif;

int main()
{
    scanf("%d %d %d", &n, &b, &Q);
    for (int i = 0; i < Q; i++) {
        int up, quan; scanf("%d %d", &up, &quan);
        quer.push_back(ii(up, quan));
    }
    quer.push_back(ii(b, n));
    sort(quer.begin(), quer.end());
    for (int i = 0; i < quer.size(); i++) {
        int lst = dif.empty()? 0: dif.back().first;
        int val = dif.empty()? 0: dif.back().second;
        int dlst = quer[i].first - lst;
        int dval = quer[i].second - val;
        if (dval > dlst || dval < 0) { printf("unfair\n"); return 0; }
        if (dlst) dif.push_back(quer[i]);
    }
    N = 2 + 5 + b + int(dif.size());
    s = 0, t = N - 1;
    for (int i = 1; i <= 5; i++)
        add_edge(0, i, n / 5);
    for (int i = 1; i <= b; i++)
        add_edge(i % 5 + 1, 5 + i, 1);
    for (int i = 0; i < dif.size(); i++) {
        int lst = i == 0? 0: dif[i - 1].first;
        int val = i == 0? 0: dif[i - 1].second;
        for (int j = lst + 1; j <= dif[i].first; j++)
            add_edge(5 + j, 6 + b + i, 1);
        add_edge(6 + b + i, N - 1, dif[i].second - val);
    }
    printf("%s\n", dinic() == n? "fair": "unfair");
    return 0;
}
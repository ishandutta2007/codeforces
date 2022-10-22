#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 105;
const int Inf = 1000000000;
const int Maxs = 100005;

int n, m;
int dist[Maxn][Maxn];
int S, B, K;
int ax[Maxs], ay[Maxs], az[Maxs], ap[Maxs];
deque <ii> inbase[Maxn];
bool fall[Maxs];
int gain[Maxs];
vector <int> rneigh[Maxs], neigh[Maxs];
ll res;

const int MAXN = 2005;
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

ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, N * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

bool Less(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) dist[i][j] = Inf;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a != b) dist[a][b] = dist[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    scanf("%d %d %d", &S, &B, &K);
    vector <ii> byattack;
    for (int i = 0; i < S; i++) {
        scanf("%d %d %d %d", &ax[i], &ay[i], &az[i], &ap[i]);
        byattack.push_back(ii(ay[i], i));
    }
    sort(byattack.begin(), byattack.end());
    for (int i = 0; i < B; i++) {
        int x, d, g; scanf("%d %d %d", &x, &d, &g);
        inbase[x].push_back(ii(d, g));
    }
    for (int i = 1; i <= n; i++) {
        sort(inbase[i].begin(), inbase[i].end(), Less);
        deque <ii> tmp;
        int lst = -1;
        for (int j = 0; j < inbase[i].size(); j++) {
            ii p = inbase[i][j];
            if (p.second > lst) {
                tmp.push_back(p);
                lst = p.second;
            }
        }
        inbase[i] = tmp;
    }
    for (int i = 0; i < byattack.size(); i++) {
        int ind = byattack[i].second;
        int tk = -1;
        for (int j = 1; j <= n; j++) if (dist[ax[ind]][j] <= az[ind]) {
            while (inbase[j].size() >= 2 && inbase[j][1].first <= ay[ind])
                inbase[j].pop_front();
            if (inbase[j].empty()) continue;
            if (inbase[j][0].first <= ay[ind])
                tk = max(tk, inbase[j][0].second);
        }
        if (tk == -1) fall[ind] = true;
        else gain[ind] = tk - ap[ind];
    }
    for (int i = 0; i < K; i++) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
    }
    vector <int> Q;
    for (int i = 0; i < S; i++)
        if (fall[i]) Q.push_back(i);
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i];
        for (int j = 0; j < rneigh[v].size(); j++) {
            int u = rneigh[v][j];
            if (!fall[u]) { fall[u] = true; Q.push_back(u); }
        }
    }
    vector <int> un;
    for (int i = 0; i < S; i++) if (!fall[i])
        if (rneigh[i].empty() && neigh[i].empty())
            res += max(gain[i], 0);
        else un.push_back(i);
    N = int(un.size()) + 2;
    s = 0, t = N - 1;
    for (int i = 0; i < un.size(); i++) {
        int v = un[i];
        if (gain[v] >= 0) { res += gain[v]; add_edge(s, i + 1, gain[v]); }
        else add_edge(i + 1, t, -gain[v]);
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            int ind = lower_bound(un.begin(), un.end(), u) - un.begin();
            add_edge(i + 1, ind + 1, INF);
        }
    }
    res -= dinic();
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int MAXN = 100005;
const int INF = 1000000000;
const int Maxb = 15;

int N, M;
vector <int> my[MAXN];

struct edge {
	int a, b, cap, flow;
};

vector <ii> V;
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
int A[MAXN], B[MAXN];
int myA[MAXN], myB[MAXN];
vector <int> seq[MAXN];

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
	memset (d, -1, n * sizeof d[0]);
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
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int getInd(int a, int b)
{
    return lower_bound(V.begin(), V.end(), ii(a, b)) - V.begin() + 1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; 1 << i <= M; i++)
        for (int j = 1; j + (1 << i) <= M + 1; j++)
            V.push_back(ii(i, j));
    sort(V.begin(), V.end());
    n = N + int(V.size()) + 2; s = 0, t = n - 1;
    for (int i = 0; i < N; i++) {
        int typ; scanf("%d", &typ);
        if (typ == 0) {
            int k; scanf("%d", &k);
            while (k--) {
                int a; scanf("%d", &a);
                my[i].push_back(getInd(0, a));
            }
            add_edge(0, i + 1, 1);
        } else if (typ == 1) {
            int l, r; scanf("%d %d", &l, &r);
            for (int j = Maxb - 1; j >= 0; j--)
                if (l + (1 << j) <= r + 1) {
                    my[i].push_back(getInd(j, l));
                    l += 1 << j;
                }
            add_edge(0, i + 1, 1);
        } else {
            int a, b, c; scanf("%d %d %d", &a, &b, &c);
            add_edge(i + 1, N + getInd(0, a), 1);
            add_edge(i + 1, N + getInd(0, b), 1);
            add_edge(i + 1, N + getInd(0, c), 1);
            add_edge(0, i + 1, 2);
        }
    }
    for (int i = 0; i < V.size(); i++)
        if (V[i].first == 0) add_edge(N + i + 1, t, 1);
        else {
            A[i] = getInd(V[i].first - 1, V[i].second);
            B[i] = getInd(V[i].first - 1, V[i].second + (1 << V[i].first - 1));
            add_edge(N + i + 1, N + A[i], 1 << V[i].first - 1);
            add_edge(N + i + 1, N + B[i], 1 << V[i].first - 1);
            A[i]--; B[i]--;
        }
    int res = dinic();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < my[i].size(); j++)
            add_edge(i + 1, N + my[i][j], 1);
    res += dinic();
    printf("%d\n", res);
    for (int i = 0; i < e.size(); i++)
        if (e[i].flow > 0 && 1 <= e[i].a && e[i].a <= N && N < e[i].b && e[i].b <= N + V.size())
            seq[e[i].b - N - 1].push_back(e[i].a);
        else if (e[i].flow > 0 && N < e[i].a && e[i].a <= N + V.size() &&
                                  N < e[i].b && e[i].b <= N + V.size() &&
                                  e[i].a > e[i].b) {
            int myind = e[i].a - N - 1;
            int ind = e[i].b - N - 1;
            if (A[myind] == ind) myA[myind] += e[i].flow;
            else if (B[myind] == ind) myB[myind] += e[i].flow;
        }
    for (int i = int(V.size()) - 1; i >= 0; i--)
        if (V[i].first == 0)
            for (int j = 0; j < seq[i].size(); j++)
                printf("%d %d\n", seq[i][j], V[i].second);
        else {
            assert(myA[i] + myB[i] == int(seq[i].size()));
            while (myA[i]--) {
                seq[A[i]].push_back(seq[i].back());
                seq[i].pop_back();
            }
            while (myB[i]--) {
                seq[B[i]].push_back(seq[i].back());
                seq[i].pop_back();
            }
        }
    return 0;
}
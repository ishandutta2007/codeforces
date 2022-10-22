#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000000;
const int lim = 314000000;

int m, n;
int mon[Maxn];
vector <int> split[Maxn];
int diam[Maxn], cost[Maxn];
int splitout[Maxn];
vector <int> insplits[Maxn];
int mn[Maxn];
vector <int> mysplits[Maxn];
vector <int> neigh[Maxn], rneigh[Maxn];
int tk[Maxn];
int bfstk[Maxn];
queue <int> bfsQ;
int mx[Maxn];

void DFS(int v)
{
	tk[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (tk[u] == 0) DFS(u);
		else if (tk[u] == 1 && !bfstk[v]) { bfstk[v] = true; bfsQ.push(v); }
	}
	tk[v] = 2;
}

int Get(int v)
{
	if (mx[v] == -1) {
		mx[v] = 0;
		for (int i = 0; i < mysplits[v].size(); i++) {
			int s = mysplits[v][i];
			int cur = diam[s];
			for (int j = 0; j < split[s].size(); j++)
				cur = min(lim, cur + Get(split[s][j]));
			mx[v] = max(mx[v], cur);
		}
	}
	return mx[v];
}

bool goodSplit(int s)
{
	if (mn[mon[s]] == Inf) return false;
	for (int i = 0; i < split[s].size(); i++)
		if (mn[split[s][i]] == Inf) return false;
	return true;
}

int main()
{
	scanf("%d %d", &m, &n);
	fill(mn + 1, mn + n + 1, Inf);
	priority_queue <ii> Q;
	for (int i = 0; i < m; i++) {
		scanf("%d", &mon[i]);
		int l; scanf("%d", &l);
		while (l--) {
			int id; scanf("%d", &id);
			if (id == -1) { diam[i]++; cost[i]++; }
			else { split[i].push_back(id); insplits[id].push_back(i); }
		}
		splitout[i] = split[i].size();
		if (split[i].empty() && cost[i] < mn[mon[i]]) {
			mn[mon[i]] = cost[i]; Q.push(ii(-cost[i], mon[i]));
		}
	}
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (d != mn[v]) continue;
		for (int i = 0; i < insplits[v].size(); i++) {
			int s = insplits[v][i];
			cost[s] = min(lim, cost[s] + d);
			if (--splitout[s] == 0 && cost[s] < mn[mon[s]]) {
				mn[mon[s]] = cost[s]; Q.push(ii(-cost[s], mon[s]));
			}
		}
	}
	for (int i = 0; i < m; i++) if (goodSplit(i)) {
		mysplits[mon[i]].push_back(i);
		for (int j = 0; j < split[i].size(); j++) {
			int u = split[i][j];
			neigh[mon[i]].push_back(u); rneigh[u].push_back(mon[i]);
		}
	}
	for (int i = 1; i <= n; i++) if (!tk[i] && mn[i] != Inf)
		DFS(i);
	while (!bfsQ.empty()) {
		int v = bfsQ.front(); bfsQ.pop();
		for (int i = 0; i < rneigh[v].size(); i++) {
			int u = rneigh[v][i];
			if (!bfstk[u]) { bfstk[u] = true; bfsQ.push(u); }
		}
	}
	fill(mx + 1, mx + n + 1, -1);
	for (int i = 1; i <= n; i++) if (!bfstk[i] && mn[i] != Inf)
		Get(i);
	for (int i = 1; i <= n; i++)
		if (mn[i] == Inf) printf("-1 -1\n");
		else printf("%d %d\n", mn[i], bfstk[i]? -2: mx[i]);
	return 0;
}
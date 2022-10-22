#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int A[Maxn], B[Maxn], C[Maxn];
vector <ii> neigh[Maxn];
int cur, tim[Maxn], low[Maxn];
bool onStack[Maxn];
vector <int> S;
int sccs, my[Maxn];
vector <int> res;
bool in[Maxn];
vector <ii> tneigh[Maxn];
bool vis[Maxn];

void SCC(int v)
{
	tim[v] = low[v] = ++cur;
	S.push_back(v);
	onStack[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		if (C[neigh[v][i].second]) continue;
		int u = neigh[v][i].first;
		if (!tim[u]) {
			SCC(u);
			low[v] = min(low[v], low[u]);
		} else if (onStack[u]) low[v] = min(low[v], tim[u]);
	}
	if (tim[v] == low[v]) {
		sccs++;
		int u;
		do {
			u = S.back(); S.pop_back();
			onStack[u] = false;
			my[u] = sccs;
		} while (u != v);
	}
}

void Solve(int v)
{
	if (vis[v]) return;
	vis[v] = true;
	for (int i = 0; i < tneigh[v].size(); i++) {
		int u = tneigh[v][i].first;
		int ind = tneigh[v][i].second;
		if (C[ind]) {
			if (!in[u]) {
				in[u] = true;
				res.push_back(ind);
				Solve(u);
			}
		} else Solve(u);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
		neigh[A[i]].push_back(ii(B[i], i));
	}
	for (int i = 1; i <= n; i++) if (!tim[i])
		SCC(i);
	in[my[1]] = true;
	for (int i = 0; i < m; i++)
		if (my[A[i]] != my[B[i]]) {
			tneigh[my[A[i]]].push_back(ii(my[B[i]], i));
			if (!C[i]) in[my[B[i]]] = true;
		}
	Solve(my[1]);
	for (int i = 1; i <= sccs; i++)
		if (!in[i]) { printf("-1\n"); return 0; }
	printf("%d\n", int(res.size()));
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i] + 1, i + 1 < res.size()? ' ': '\n');
    return 0;
}
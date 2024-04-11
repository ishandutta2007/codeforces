#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 3005;
const int Maxq = 500005;
const int Maxm = 7;

int n, m, q;
vector <int> neigh[Maxn], rneigh[Maxn];
int vis[Maxn];
bool reach[Maxn][Maxn];
int S[Maxq], T[Maxq], K[Maxq];
vector <int> my[Maxn][Maxn];
int res[Maxq];
vector <int> seq;

void DFS(int v, int wh)
{
	if (vis[v]) return;
	vis[v] = true; reach[v][wh] = true;
	for (int i = 0; i < rneigh[v].size(); i++)
		DFS(rneigh[v][i], wh);
}

void Traverse(int s, int t)
{
	seq.push_back(s);
	for (int i = 0; i < my[s][t].size(); i++) {
		int ind = my[s][t][i];
		if (K[ind] <= seq.size()) res[ind] = seq[int(seq.size()) - K[ind]];
	}
	for (int i = 0; i < rneigh[s].size(); i++)
		Traverse(rneigh[s][i], t);
	seq.pop_back();
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		neigh[x].push_back(y);
		rneigh[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(neigh[i].begin(), neigh[i].end());
		fill(vis, vis + n + 1, false);
		DFS(i, i);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &S[i], &T[i], &K[i]);
		res[i] = -1;
		my[S[i]][T[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			rneigh[j].clear();
		for (int j = 1; j <= n; j++) if (i != j)
			for (int k = 0; k < neigh[j].size(); k++) {
				int u = neigh[j][k];
				if (reach[u][i]) { rneigh[u].push_back(j); break; }
			}
		Traverse(i, i);
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", res[i]);
	return 0;
}
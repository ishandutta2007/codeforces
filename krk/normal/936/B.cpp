#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int s;
bool tk[Maxn][2];
int par[Maxn][2];
int vis[Maxn];

bool getLoop(int v)
{
	if (vis[v] == 1) return true;
	if (vis[v] == 2) return false;
	vis[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++)
		if (getLoop(neigh[v][i])) return true;
	vis[v] = 2;
	return false;
}

int Solve(int v, int col)
{
	tk[v][col] = true;
	if (neigh[v].size() == 0 && col == 1) return v;
	if (neigh[v].size() == 0) return -1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		int oc = 1 - col;
		if (!tk[u][oc]) {
			par[u][oc] = v;
			int g = Solve(u, oc);
			if (g != -1) return g;
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int c; scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			int a; scanf("%d", &a);
			neigh[i].push_back(a);
		}
	}
	scanf("%d", &s);
	int r = Solve(s, 0);
	if (r != -1) {
		vector <int> res; res.push_back(r);
		int v = r, c = 1;
		do {
			v = par[v][c]; c = 1 - c;
			res.push_back(v);
		} while (v != s || c != 0);
		printf("Win\n");
		for (int i = int(res.size()) - 1; i >= 0; i--)
			printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
	} else if (getLoop(s)) printf("Draw\n");
		   else printf("Lose\n");
	return 0;
}
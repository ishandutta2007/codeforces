#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;
const int Maxm = 100005;

int n, m;
int U[Maxm], V[Maxm];
vector <ii> neigh[Maxn];
int tk[Maxn], par[Maxn];
vector <int> spec;

bool findLoop(int v, int p)
{
	if (tk[v] == 1) {
		spec.push_back(p); int u = U[p];
		while (u != v) {
			spec.push_back(par[u]); u = U[par[u]];
		}
		return true;
	}
	if (tk[v] == 2) return false;
	tk[v] = 1; par[v] = p;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (findLoop(u.first, u.second)) return true;
	}
	tk[v] = 2;
	return false;
}

bool Ok(int v, int forb)
{
	if (tk[v] == 1) return false;
	if (tk[v] == 2) return true;
	tk[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.second == forb) continue;
		if (!Ok(u.first, forb)) return false;
	}
	tk[v] = 2;
	return true;
}

bool Check(int forb)
{
	fill(tk, tk + n + 1, 0);
	for (int i = 1; i <= n; i++) if (!tk[i])
		if (!Ok(i, forb)) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		U[i] = u; V[i] = v;
		neigh[u].push_back(ii(v, i));
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		if (findLoop(i, -1)) break;
	if (spec.empty()) printf("YES\n");
	else {
		for (int i = 0; i < spec.size(); i++)
			if (Check(spec[i])) { printf("YES\n"); return 0; }
		printf("NO\n");
	}
	return 0;
}
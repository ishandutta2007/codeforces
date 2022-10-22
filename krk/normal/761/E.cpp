#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 32;
const ll Maxb = 30;
const int Maxd = 4;
const int dy[Maxd] = {0, 1, 0, -1};
const int dx[Maxd] = {-1, 0, 1, 0};

int n;
vector <int> neigh[Maxn];
ll x[Maxn], y[Maxn];
int root = 1;

bool Traverse(int v, int st, ll lvl, int p = 0)
{
	int ind = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (ind >= Maxd || ind == Maxd - 1 && p != 0) return false;
		int nw = (st + ind) % Maxd;
		x[u] = x[v] + ll(dx[nw]) * (1ll << lvl); y[u] = y[v] + ll(dy[nw]) * (1ll << lvl);
		if (!Traverse(u, (nw - 1 + Maxd) % Maxd, lvl - 1, v)) return false;
		ind++;
	}
	return true;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 2; i <= n; i++)
		if (neigh[i].size() > neigh[root].size()) root = i;
	if (Traverse(root, 0, Maxb)) {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			printf("%I64d %I64d\n", x[i], y[i]);
	} else printf("NO\n");
    return 0;
}
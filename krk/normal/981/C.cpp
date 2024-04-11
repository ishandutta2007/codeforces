#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
vector <int> res;

bool Okay(int v, int p)
{
	int ch = int(neigh[v].size()) - 1;
	if (ch > 1) return false;
	if (ch == 0) {
		res.push_back(v);
		return true;
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		return Okay(u, v);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	int bi = 1;
	for (int i = 2; i <= n; i++)
		if (neigh[i].size() > neigh[bi].size())
			bi = i;
	for (int i = 0; i < neigh[bi].size(); i++)
		if (!Okay(neigh[bi][i], bi)) { printf("No\n"); return 0; }
	printf("Yes\n");
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", bi, res[i]);
	return 0;
}
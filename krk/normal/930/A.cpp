#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int L[Maxn];
int res;

void Solve(int v, int p, int lvl)
{
	L[lvl]++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v, lvl + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	Solve(1, 0, 0);
	for (int i = 0; i < Maxn; i++)
		res += L[i] % 2;
	printf("%d\n", res);
	return 0;
}
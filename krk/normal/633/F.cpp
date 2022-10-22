#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
ll best1[Maxn][3], best2[Maxn][3];
ll dp1[Maxn], dp2[Maxn], dp3[Maxn], dp4[Maxn];

void Insert(ll best[], ll val)
{
	if (val > best[0]) best[2] = best[1], best[1] = best[0], best[0] = val;
	else if (val > best[1]) best[2] = best[1], best[1] = val;
	else if (val > best[2]) best[2] = val;
}

ll Get(ll best[], ll val)
{
	return best[0] == val? best[1]: best[0];
}

ll getSum(ll best[], ll val)
{
	if (best[0] == val) return best[1] + best[2];
	if (best[1] == val) return best[0] + best[2];
	return best[0] + best[1];
}

void Traverse(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		Insert(best1[v], dp1[u]);
		Insert(best2[v], dp2[u]);
	}
	dp1[v] = best1[v][0] + a[v];
	dp2[v] = best1[v][0] + best1[v][1] + a[v];
	dp4[v] = best2[v][0] + best2[v][1];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		dp2[v] = max(dp2[v], dp2[u]);
		dp3[v] = max(dp3[v], dp3[u] + a[v]);
		dp3[v] = max(dp3[v], Get(best2[v], dp2[u]) + dp1[u] + a[v]);
		dp4[v] = max(dp4[v], dp4[u]);
		dp4[v] = max(dp4[v], dp2[u] + getSum(best1[v], dp1[u]) + a[v]);
		dp4[v] = max(dp4[v], dp3[u] + Get(best1[v], dp1[u]) + a[v]);
	}
	dp2[v] = max(dp1[v], dp2[v]);
	dp3[v] = max(dp2[v], dp3[v]);
	dp4[v] = max(dp3[v], dp4[v]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	printf("%I64d\n", dp4[1]);
	return 0;
}
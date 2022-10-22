#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m, k;
vector <int> neigh[Maxn];
int v[Maxn], col[Maxn];
int mx;
int res;

int Get(int v, int c)
{
	if (col[v]) return 0;
	col[v] = c; int res = 1;
	for (int i = 0; i < neigh[v].size(); i++)
		res += Get(neigh[v][i], c);
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= k; i++) {
		int g = Get(v[i], i);
		res += g * (g - 1) / 2;
		mx = max(mx, g);
	}
	res -= mx * (mx - 1) / 2;
	int cur = k;
	for (int i = 1; i <= n; i++) if (!col[i])
		mx++;
	res += mx * (mx - 1) / 2;
	printf("%d\n", res - m);
	return 0;
}
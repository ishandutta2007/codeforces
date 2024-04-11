#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
ll st[Maxn];
ll res;

ii getRes(int v, int p)
{
	ii res = ii(0ll, 0ll);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		ii tmp = getRes(u, v);
		res = ii(max(res.first, tmp.first), max(res.second, tmp.second));
	}
	st[v] += res.first - res.second;
	if (st[v] < 0) res.first += abs(st[v]);
	else res.second += abs(st[v]);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &st[i]);
	ii res = getRes(1, 0);
	printf("%I64d\n", res.first + res.second);
	return 0;
}
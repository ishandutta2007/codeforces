#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;

int n;
int a[Maxn];
vector <ii> neigh[Maxn];
int cnt[Maxn];

void Traverse1(int v, int p = 0)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == p) continue;
		Traverse1(u, v);
		cnt[v] += cnt[u];
	}
}

int Traverse2(int v, int p, ll col)
{
	if (a[v] < col) return cnt[v];
	int res = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		ll c = neigh[v][i].second;
		if (u == p) continue;
		res += Traverse2(u, v, max(col + c, c));
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		int b, c; scanf("%d %d", &b, &c);
		neigh[i].push_back(ii(b, c));
		neigh[b].push_back(ii(i, c));
	}
	Traverse1(1);
	printf("%d\n", Traverse2(1, 0, 0));
	return 0;
}
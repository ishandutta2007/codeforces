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

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;

int n, m;
iii E[Maxn];
int par[Maxn], siz[Maxn];
int norm[Maxn], add[Maxn];
int res;

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

void unionSet(int a, int b, int c)
{
	a = getPar(a), b = getPar(b);
	if (a == b) add[a] = max(add[a], c);
	else {
		if (siz[a] < siz[b]) swap(a, b);
		siz[a] += siz[b]; par[b] = a;
		norm[a] += norm[b] + c;
		add[a] = max(max(add[a], add[b]), add[a] + add[b] - c);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &E[i].second.first, &E[i].second.second, &E[i].first);
	}
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	sort(E, E + m);
	for (int i = m - 1; i >= 0; i--)
		unionSet(E[i].second.first, E[i].second.second, E[i].first);
	for (int i = 1; i <= n; i++)
		if (getPar(i) == i) res += max(norm[i], norm[i] + add[i]);
	printf("%d\n", res);
	return 0;
}
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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n, m;
int d[Maxn];
vector <ii> neigh[Maxn];
bool tk[Maxn];
bool res[Maxn];

int Solve(int v)
{
	tk[v] = true;
	int cnt = d[v] == 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (tk[u.first]) continue;
		int got = Solve(u.first);
		if (got % 2) res[u.second] = true;
		cnt += got;
	}
	return cnt;
}

int main()
{
	scanf("%d %d", &n, &m);
	bool was = false; int odd = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		if (d[i] == -1) was = true;
		else if (d[i] == 1) odd++;
	}
	if (odd % 2 && !was) { printf("-1\n"); return 0; }
	if (odd % 2)
		for (int i = 1; i <= n; i++)
			if (d[i] == -1) { d[i] = 1; break; }
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, i));
		neigh[b].push_back(ii(a, i));
	}
	Solve(1);
	int r = 0;
	for (int i = 1; i <= m; i++)
		r += res[i];
	printf("%d\n", r);
	for (int i = 1; i <= m; i++) if (res[i])
		printf("%d\n", i);
	return 0;
}
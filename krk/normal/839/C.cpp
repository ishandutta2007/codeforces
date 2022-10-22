#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
ld res[Maxn];

void Solve(int v, int p)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v);
		res[v] += res[u] + 1;
	}
	if (int(neigh[v].size()) - (p != 0) != 0)
		res[v] /= ld(int(neigh[v].size()) - (p != 0));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Solve(1, 0);
	cout << fixed << setprecision(10) << res[1] << endl;
	return 0;
}
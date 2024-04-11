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

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
ii mx[Maxn];

void Traverse(int v, int l = 0, int p = 0)
{
	mx[v] = ii(l, v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, l + 1, v);
		mx[v] = max(mx[v], mx[u]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	int r = mx[1].second;
	Traverse(r);
	printf("%d\n", mx[r].first);
	return 0;
}
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

typedef long long ll;

const int Maxn = 1000005;

int n, m;
int deg[Maxn];
vector <int> neigh[Maxn];
bool mark[Maxn];
bool tk[Maxn];
ll res;

int Traverse(int v)
{
	if (tk[v]) return 0;
	int res = 1; tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		res += Traverse(u);
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	int loops = 0, oth = 0;
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
		mark[a] = mark[b] = true;
		if (a == b) loops++;
		else { oth++; deg[a]++; deg[b]++; }
	}
	int root = 1;
	while (!mark[root]) root++;
	int tot = 0;
	for (int i = 1; i <= n; i++)
		tot += mark[i];
	if (Traverse(root) != tot) printf("0\n");
	else {
		res = ll(loops) * (loops - 1) / 2 + ll(loops) * oth;
		for (int i = 1; i <= n; i++)
			res += ll(deg[i]) * (deg[i] - 1) / 2;
		printf("%I64d\n", res);
	}
	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int dpmax[Maxn], dpmin[Maxn];
int has[Maxn];

void Traverse(int v, bool mx, int p = 0)
{
	int ch = neigh[v].size() - bool(p);
	if (ch == 0)
		dpmax[v] = dpmin[v] = has[v] = 1;
	else {
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (u == p) continue;
			Traverse(u, !mx, v);
			has[v] += has[u];
		}
		if (mx) {
			dpmax[v] = dpmin[v] = 0;
			for (int i = 0; i < neigh[v].size(); i++) {
				int u = neigh[v][i];
				if (u == p) continue;
				dpmax[v] = max(dpmax[v], has[v] - has[u] + dpmax[u]);
				dpmin[v] += dpmin[u];
			}
		} else {
			dpmax[v] = 1; dpmin[v] = Maxn;
			for (int i = 0; i < neigh[v].size(); i++) {
				int u = neigh[v][i];
				if (u == p) continue;
				dpmax[v] += dpmax[u] - 1;
				dpmin[v] = min(dpmin[v], dpmin[u]);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1, true);
	printf("%d %d\n", dpmax[1], dpmin[1]);
	return 0;
}
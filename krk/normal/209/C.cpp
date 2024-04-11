#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1000005;

int n, m;
vector <int> neigh[Maxn];
int deg[Maxn];
bool taken[Maxn];
int comp;
int res1, res2;

int Get(int v)
{
	if (taken[v]) return 0;
	int res = deg[v] % 2; taken[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		res += Get(neigh[v][i]);
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
		deg[a]++; deg[b]++;
	}
	for (int i = 1; i <= n; i++) if (!taken[i] && (deg[i] || i == 1)) {
		comp++;
		int g = Get(i);
		res1 += max(g, 2) / 2;
		res2 += g / 2;
	}
	printf("%d\n", comp <= 1? res2: res1);
	return 0;
}
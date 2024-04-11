#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
int a[Maxn];
vector <int> neigh[Maxn];
int res;

void Traverse(int v, int p, int con, bool flag)
{
	bool was = false;
	if (a[v] == 0) con = 0;
	else {
		con++;
		if (con > m) { con = 0; flag = true; }
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (p == u) continue;
		was = true;
		Traverse(u, v, con, flag);
	}
	if (!was && !flag) res++;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		neigh[u].push_back(v);
		neigh[v].push_back(u);
	}
	Traverse(1, 0, 0, false);
	printf("%d\n", res);
	return 0;
}
#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int in[Maxn], go[Maxn];
vector <int> res;

void Traverse(int v, int p, bool my, bool oth)
{
	in[v] ^= my;
	bool gv = my ^ (in[v] != go[v]);
	if (in[v] != go[v]) res.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, oth, gv);
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
	for (int i = 1; i <= n; i++)
		scanf("%d", &in[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &go[i]);
	Traverse(1, 0, false, false);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);
	return 0;
}
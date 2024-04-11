#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxm = 20;

int n;
vector <int> neigh[Maxn];
int P[Maxn][Maxm], L[Maxn];
int cnt[Maxn];
int q;

void Traverse(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] != u) { 
			P[u][0] = v; L[u] = L[v] + 1; 
			Traverse(u); 
			cnt[v] += cnt[u];
		}
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
	return P[a][0];
}

int goUp(int v, int hm)
{
	for (int j = Maxm - 1; j >= 0; j--)
		if ((1 << j) <= hm) { v = P[v][j]; hm -= 1 << j; }
	return v;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	scanf("%d", &q);
	while (q--) {
		int a, b; scanf("%d %d", &a, &b);
		int lca = getLCA(a, b);
		int dist = L[a] + L[b] - 2 * L[lca];
		if (dist == 0) printf("%d\n", n);
		else if (dist % 2) printf("0\n");
		else if (L[a] - L[lca] == dist / 2) {
			a = goUp(a, dist / 2 - 1), b = goUp(b, dist / 2 - 1);
			printf("%d\n", n - cnt[a] - cnt[b]);
		} else if (L[a] - L[lca] > dist / 2) {
			a = goUp(a, dist / 2 - 1);
			printf("%d\n", cnt[P[a][0]] - cnt[a]);
		} else {
			b = goUp(b, dist / 2 - 1);
			printf("%d\n", cnt[P[b][0]] - cnt[b]);
		}
	}
	return 0;
}
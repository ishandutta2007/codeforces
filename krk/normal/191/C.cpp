#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 20;

int n;
vector <ii> neigh[Maxn];
int k;
int P[Maxn][Maxm], L[Maxn], Id[Maxn], B[Maxn];
int res[Maxn];

void Build(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v][0] != u.first) {
			P[u.first][0] = v; L[u.first] = L[v] + 1; Id[u.first] = u.second;
			Build(u.first);
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

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v][0] != u.first) {
			Traverse(u.first);
			res[Id[u.first]] = B[u.first];
			B[v] += B[u.first];
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, i)); neigh[b].push_back(ii(a, i));
	}
	Build(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	scanf("%d", &k);
	while (k--) {
		int a, b; scanf("%d %d", &a, &b);
		int lca = getLCA(a, b);
		B[a]++; B[b]++; B[lca] -= 2;
	}
	Traverse(1);
	for (int i = 0; i < n - 1; i++)
		printf("%d%c", res[i], i + 1 < n - 1? ' ': '\n');
	return 0;
}
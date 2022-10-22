#include <cstdio>
#include <set>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxm = 505;
const int Inf = 1000000007;

int n, m, k;
int col[Maxn], cur;
int D[Maxm][Maxm];
vector <int> neigh[Maxn];
int id, tk[Maxn];
set <int> has[Maxm];

void Take(int v, int cl)
{
	if (tk[v]) return;
	tk[v] = cl; has[col[v]].insert(cl);
	for (int i = 0; i < neigh[v].size(); i++)
		Take(neigh[v][i], cl);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int c; scanf("%d", &c);
		while (c--) col[++cur] = i;
	}
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			D[i][j] = (i != j) * Inf;
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (c == 0) { neigh[a].push_back(b); neigh[b].push_back(a); }
		D[col[a]][col[b]] = D[col[b]][col[a]] = min(D[col[a]][col[b]], c);
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		Take(i, ++id);
	for (int i = 1; i <= k; i++) 
		if (has[i].size() > 1) { printf("No\n"); return 0; }
	printf("Yes\n");
	for (int l = 1; l <= k; l++)
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				D[i][j] = min(D[i][j], D[i][l] + D[l][j]);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			printf("%d%c", D[i][j] == Inf? -1: D[i][j], j + 1 <= k? ' ': '\n');
	return 0;
}
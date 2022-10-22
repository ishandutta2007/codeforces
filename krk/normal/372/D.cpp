#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 20;

int n, k;
vector <int> neigh[Maxn];
int id[Maxn], seq[Maxn], cur;
int P[Maxn][Maxm], L[Maxn];
set <int> S;
int res;

void Traverse(int v)
{
	id[v] = cur; seq[cur] = v; cur++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] != u) { P[u][0] = v; L[u] = L[v] + 1; Traverse(u); }
	}
}

int Dist(int a, int b)
{
	int res = 0;
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) { res += 1 << i; a = P[a][i]; }
	if (a == b) return res;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) { res += 2 * (1 << i); a = P[a][i]; b = P[b][i]; }
	res += 2;
	return res;
}

int Calc(int v)
{
	if (S.empty()) return 1;
	set <int>::iterator it = S.lower_bound(id[v]);
	int a = seq[it == S.end()? *S.begin(): *it];
	int b = seq[it == S.begin()? *S.rbegin(): *--it];
	return (Dist(a, v) + Dist(v, b) - Dist(a, b)) / 2;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	int siz = 0;
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= n && siz <= k) { siz += Calc(j); S.insert(id[j]); j++; }
		if (siz <= k) res = max(res, j - i);
		else res = max(res, j - 1 - i);
		S.erase(id[i]); siz -= Calc(i);
	}
	printf("%d\n", res);
	return 0;
}
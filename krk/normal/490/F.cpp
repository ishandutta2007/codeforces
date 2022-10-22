#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 6005;

int n;
int r[Maxn];
vector <int> neigh[Maxn];
int V[Maxn][Maxn], Vrlen[Maxn], Vlen;
int my[Maxn];
int res;

int getIndex(int val)
{
	int l = 0, r = Vlen - 1;
	int res = Vlen;
	while (l <= r) {
		int m = l + r >> 1;
		if (val <= V[m][Vrlen[m] - 1]) { res = m; r = m - 1; }
		else l = m + 1;
	}
	return res;
}

void Add(int v)
{
	int ind = getIndex(r[v]);
	if (ind == Vlen) Vlen++;
	V[ind][Vrlen[ind]++] = r[v];
	my[v] = ind;
}

void Rem(int v)
{
	int ind = my[v];
	Vrlen[ind]--;
	if (Vrlen[Vlen - 1] == 0) Vlen--;
}

void Traverse(int v, int p)
{
	Add(v);
	res = max(res, Vlen);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
	}
	Rem(v);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		Traverse(i, 0);
	printf("%d\n", res);
	return 0;
}
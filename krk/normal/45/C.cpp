#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 200005;
const int Maxm = 1048576;

int n;
char typ[Maxn];
int a[Maxn];
int L[Maxm], R[Maxm], I[Maxm];
int lef[Maxm], rig[Maxm];
vector <ii> res;

int Best(int v) { return min(min(L[v], R[v]), I[v]); }

void Union(int v)
{
	L[v] = Best(2 * v); R[v] = Best(2 * v + 1);
	int l = rig[2 * v], r = lef[2 * v + 1];
	I[v] = l != -1 && r != -1 && typ[l] != typ[r]? abs(a[l] - a[r]): Inf;
	lef[v] = lef[2 * v] != -1? lef[2 * v]: lef[2 * v + 1];
	rig[v] = rig[2 * v + 1] != -1? rig[2 * v + 1]: rig[2 * v];
}

void Create(int v, int l, int r)
{
	if (l == r) { L[v] = R[v] = I[v] = Inf; lef[v] = rig[v] = l; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Find(int v, int l, int r, int &a, int &b)
{
	int m = l + r >> 1;
	if (L[v] <= I[v] && L[v] <= R[v]) Find(2 * v, l, m, a, b);
	else if (I[v] <= R[v]) { a = rig[2 * v]; b = lef[2 * v + 1]; }
	else Find(2 * v + 1, m + 1, r, a, b);
}

void Erase(int v, int l, int r, int x)
{
	if (l == r) { L[v] = R[v] = I[v] = Inf; lef[v] = rig[v] = -1; }
	else {
		int m = l + r >> 1;
		if (x <= m) Erase(2 * v, l, m, x);
		else Erase(2 * v + 1, m + 1, r, x);
		Union(v);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf(" %c", &typ[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	while (Best(1) != Inf) {
		int a, b; Find(1, 1, n, a, b);
		res.push_back(ii(a, b));
		Erase(1, 1, n, a); Erase(1, 1, n, b);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}
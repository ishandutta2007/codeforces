#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 500005;
const int Maxm = 2097152;

int n;
vector <int> neigh[Maxn];
int L[Maxn], R[Maxn], cur;
int wt[Maxm], et[Maxm];
int q;

void Traverse(int v, int p)
{
	L[v] = cur++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u != p) Traverse(u, v);
	}
	R[v] = cur - 1;
}

void Create(int v, int l, int r)
{
	wt[v] = -2; et[v] = -1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void wUpdate(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) wt[v] = val;
	else {
		int m = l + r >> 1;
		if (a <= m) wUpdate(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) wUpdate(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int wQuery(int v, int l, int r, int x)
{
	if (l == r) return wt[v];
	else {
		int m = l + r >> 1;
		return max(wt[v], x <= m? wQuery(2 * v, l, m, x): wQuery(2 * v + 1, m + 1, r, x));
	}
}

void eUpdate(int v, int l, int r, int x, int val)
{
	et[v] = val;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) eUpdate(2 * v, l, m, x, val);
		else eUpdate(2 * v + 1, m + 1, r, x, val);
	}
}

int eQuery(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return et[v];
	else {
		int res = -3;
		int m = l + r >> 1;
		if (a <= m) res = max(res, eQuery(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, eQuery(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Traverse(1, 0);
	Create(1, 0, cur - 1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int c, v; scanf("%d %d", &c, &v);
		if (c == 1) wUpdate(1, 0, cur - 1, L[v], R[v], i);
		else if (c == 2) eUpdate(1, 0, cur - 1, L[v], i);
		else printf("%d\n", wQuery(1, 0, cur - 1, L[v]) > eQuery(1, 0, cur - 1, L[v], R[v]));
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

int n, m;
int a[Maxn], b[Maxn];
int ind[Maxm];

void Copy(int v, int l, int r, int a, int b, int from)
{
	if (l == a && r == b) ind[v] = from;
	else {
		int m = l + r >> 1;
		if (ind[v]) { ind[2 * v] = ind[v]; ind[2 * v + 1] = ind[v] + (m + 1) - l; ind[v] = 0; }
		if (a <= m) Copy(2 * v, l, m, a, min(m, b), from);
		if (m + 1 <= b)
			if (a < m + 1) Copy(2 * v + 1, m + 1, r, m + 1, b, from + (m + 1) - a);
			else Copy(2 * v + 1, m + 1, r, a, b, from);
	}
}

int Get(int v, int l, int r, int x)
{
	if (ind[v]) return a[ind[v] + x - l];
	if (l == r) return b[l];
	else {
		int m = l + r >> 1;
		if (x <= m) return Get(2 * v, l, m, x);
		return Get(2 * v + 1, m + 1, r, x);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	while (m--) {
		int t, x, y, k;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &x, &y, &k);
			Copy(1, 1, n, y, y + k - 1, x);
		} else {
			scanf("%d", &x);
			printf("%d\n", Get(1, 1, n, x));
		}
	}
	return 0;
}
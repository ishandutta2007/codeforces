#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 300005;
const int Maxm = 2097152;

int n, m;
int st[Maxm];

void Set(int v, int l, int r, int a, int b, int x)
{
	if (st[v]) return;
	if (l == a && r == b) st[v] = x;
	else {
		int m = l + r >> 1;
		if (a <= m) Set(2 * v, l, m, a, min(m, b), x);
		if (m + 1 <= b) Set(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
	}
}

int Get(int v, int l, int r, int x)
{
	if (l == r) return st[v];
	else {
		int m = l + r >> 1;
		int res;
		if (x <= m) res = Get(2 * v, l, m, x);
		else res = Get(2 * v + 1, m + 1, r, x);
		if (!res) return st[v];
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int l, r, x; scanf("%d %d %d", &l, &r, &x);
		if (l < x) Set(1, 1, n, l, x - 1, x);
		if (x < r) Set(1, 1, n, x + 1, r, x);
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", Get(1, 1, n, i), i + 1 <= n? ' ': '\n');
	return 0;
}
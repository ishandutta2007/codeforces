#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
	ll mxl, mxr, my;
	ll sum, lst;
};

int n, m, N;
int d[Maxn];
int h[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
	node c;
	c.mxl = max(a.mxl, a.sum + b.mxl);
	c.mxr = max(b.mxr, a.mxr + a.lst + b.sum - b.lst);
	c.my = max(max(a.my, b.my), a.mxr + a.lst + b.mxl);
	c.sum = a.sum + b.sum; c.lst = b.lst;
	return c;
}

void Create(int v, int l, int r)
{
	if (l == r) { st[v].mxl = st[v].mxr = 2 * h[l]; st[v].my = 0; st[v].sum = st[v].lst = d[l]; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

node getNode(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return getNode(2 * v, l, m, a, b);
		if (m + 1 <= a) return getNode(2 * v + 1, m + 1, r, a, b);
		return Union(getNode(2 * v, l, m, a, m), getNode(2 * v + 1, m + 1, r, m + 1, b));
	}
}

int main()
{
	scanf("%d %d", &n, &m); N = n + n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]); d[n + i] = d[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]); h[n + i] = h[i];
	}
	Create(1, 1, N);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		if (a <= b) printf("%I64d\n", getNode(1, 1, N, b + 1, a + n - 1).my);
		else printf("%I64d\n", getNode(1, 1, N, b + 1, a - 1).my);
	}
	return 0;
}
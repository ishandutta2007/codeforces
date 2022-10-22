#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxz = 7;
const int Maxo = 11;

int n;
int a[Maxn];
ll st[Maxz - 2][Maxm][Maxo];
int m;

int Get(int z, int off) { return off < z? off + 1: 2 * z - off - 1; }

void Create(int t, int off, int v, int l, int r)
{
	if (l == r)
		for (int i = 0; i < off; i++)
			st[t][v][i] = ll(Get(t + 2, i)) * ll(a[l]);
	else {
		int m = l + r >> 1;
		Create(t, off, 2 * v, l, m); Create(t, off, 2 * v + 1, m + 1, r);
		for (int i = 0; i < off; i++)
			st[t][v][i] = st[t][2 * v][i] + st[t][2 * v + 1][(i + m - l + 1) % off];
	}
}

void Update(int t, int off, int v, int l, int r, int x)
{
	if (l == r)
		for (int i = 0; i < off; i++)
			st[t][v][i] = ll(Get(t + 2, i)) * ll(a[l]);
	else {
		int m = l + r >> 1;
		if (x <= m) Update(t, off, 2 * v, l, m, x);
		else Update(t, off, 2 * v + 1, m + 1, r, x);
		for (int i = 0; i < off; i++)
			st[t][v][i] = st[t][2 * v][i] + st[t][2 * v + 1][(i + m - l + 1) % off];
	}
}

ll Get(int t, int off, int v, int l, int r, int a, int b, int nd)
{
	if (l == a && r == b) return st[t][v][nd];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(t, off, 2 * v, l, m, a, b, nd);
		if (m + 1 <= a) return Get(t, off, 2 * v + 1, m + 1, r, a, b, nd);
		return Get(t, off, 2 * v, l, m, a, m, nd) + Get(t, off, 2 * v + 1, m + 1, r, m + 1, b, (nd + m - a + 1) % off);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i < Maxz; i++)
		Create(i - 2, 2 * (i - 1), 1, 1, n);
	scanf("%d", &m);
	while (m--) {
		int t, b, c, d; scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d", &b, &c);
			a[b] = c;
			for (int i = 2; i < Maxz; i++)
				Update(i - 2, 2 * (i - 1), 1, 1, n, b);
		} else {
			scanf("%d %d %d", &b, &c, &d);
			printf("%I64d\n", Get(d - 2, 2 * (d - 1), 1, 1, n, b, c, 0));
		}
	}
	return 0;
}
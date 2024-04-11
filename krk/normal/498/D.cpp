#include <cstdio>
using namespace std;

const int Maxd = 60;
const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
int st[Maxm][Maxd];
int q;

void Union(int v)
{
	for (int j = 0; j < Maxd; j++) {
		int t1 = st[2 * v][j];
		int t2 = st[2 * v + 1][(j + t1) % Maxd];
		st[v][j] = t1 + t2;
	}
}

void Create(int v, int l, int r)
{
	if (l == r)
		for (int j = 0; j < Maxd; j++)
			st[v][j] = j % a[l] == 0? 2: 1;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int x)
{
	if (l == r)
		for (int j = 0; j < Maxd; j++)
			st[v][j] = j % a[l] == 0? 2: 1;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x);
		else Update(2 * v + 1, m + 1, r, x);
		Union(v);
	}
}

int Calc(int v, int l, int r, int a, int b, int cur = 0)
{
	if (l == a && r == b) return st[v][cur];
	else {
		int m = l + r >> 1;
		if (b <= m) return Calc(2 * v, l, m, a, b, cur);
		if (m + 1 <= a) return Calc(2 * v + 1, m + 1, r, a, b, cur);
		int t1 = Calc(2 * v, l, m, a, m, cur);
		cur = (cur + t1) % Maxd;
		int t2 = Calc(2 * v + 1, m + 1, r, m + 1, b, cur);
		return t1 + t2;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	scanf("%d", &q);
	char ch;
	int x, y;
	while (q--) {
		scanf(" %c %d %d", &ch, &x, &y);
		if (ch == 'C') { a[x] = y; Update(1, 1, n, x); }
		else { y--; printf("%d\n", Calc(1, 1, n, x, y)); }
	}
	return 0;
}
#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxb = 18;

int n, m;
int a[Maxn];
int BIT[Maxb][Maxn], ST[Maxb][Maxm];
ll res;

void Create(int b, int v, int l, int r)
{
	if (l == r) ST[b][v] = 1;
	else {
		int m = l + r >> 1;
		Create(b, 2 * v, l, m); Create(b, 2 * v + 1, m + 1, r);
		ST[b][v] = ST[b][2 * v] + ST[b][2 * v + 1];
	}
}

void Update(int b, int v, int l, int r, int x, int val)
{
	ST[b][v] += val;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Update(b, 2 * v, l, m, x, val);
		else Update(b, 2 * v + 1, m + 1, r, x, val);
	}
}

int getInd(int b, int v, int l, int r, int need)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if (ST[b][2 * v] >= need) return getInd(b, 2 * v, l, m, need);
		else return getInd(b, 2 * v + 1, m + 1, r, need - ST[b][2 * v]);
	}
}

void Insert(int b, int x, int val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[b][i] += val;
}

int Get(int b, int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[b][i];
	return res;
}

void Change1(int b, int p)
{
	int cur = p - Get(b, p);
	int l = cur == 1? 0: getInd(b, 1, 1, n, cur - 1);
	int r = cur == ST[b][1]? n + 1: getInd(b, 1, 1, n, cur + 1);
	res += ll(p - l) * (r - p) * (1 << b);
	Insert(b, p, 1); Update(b, 1, 1, n, p, -1);
}

void Change0(int b, int p)
{
	int lef = p - Get(b, p);
	int l = lef == 0? 0: getInd(b, 1, 1, n, lef);
	int r = lef == ST[b][1]? n + 1: getInd(b, 1, 1, n, lef + 1);
	res -= ll(p - l) * (r - p) * (1 << b);
	Insert(b, p, -1); Update(b, 1, 1, n, p, 1);
}

void Change(int p, int na)
{
	for (int i = 0; i < Maxb; i++)
		if ((a[p] & 1 << i) != (na & 1 << i))
			if (na & 1 << i) Change1(i, p);
			else Change0(i, p);
	a[p] = na;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < Maxb; i++)
		Create(i, 1, 1, n);
	for (int i = 1; i <= n; i++) {
		int na; scanf("%d", &na);
		Change(i, na);
	}
	while (m--) {
		int p, v; scanf("%d %d", &p, &v);
		Change(p, v);
		printf("%I64d\n", res);
	}
	return 0;
}
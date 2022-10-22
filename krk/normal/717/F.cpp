#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;
const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
	ll min_odd, min_even, sum, x, flag;
	int zers;
	bool odd;
};

int n;
int a[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
	node c;
	c.min_odd = min(a.min_odd, a.odd? b.min_even + a.sum: b.min_odd - a.sum);
	c.min_even = min(a.min_even, a.odd? b.min_odd - a.sum: b.min_even + a.sum);
	c.sum = b.odd? b.sum - a.sum: b.sum + a.sum;
	c.flag = 0;
	c.odd = a.odd ^ b.odd;
	c.x = c.odd? c.sum: -c.sum;
	c.zers = a.zers + b.zers;
	return c;
}

void downOn(node &a, ll val)
{
	a.min_odd += val;
	if (a.odd) a.sum += val;
	a.flag += val;
	a.x = a.odd? a.sum: -a.sum;
	if (val > 0) a.zers = 0;
}

void Down(int v)
{
	if (st[v].flag) {
		downOn(st[2 * v], st[v].flag);
		downOn(st[2 * v + 1], st[v].flag);
		st[v].flag = 0;
	}
}

void Create(int v, int l, int r)
{
	if (l == r) {
		st[v].min_odd = a[l];
		st[v].min_even = Inf;
		st[v].sum = a[l];
		st[v].x = -st[v].sum;
		st[v].flag = 0;
		st[v].odd = true;
		st[v].zers = a[l] < 0;
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

void Add(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) downOn(st[v], val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

node Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		Down(v);
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i]--;
	}
	Create(1, 0, n - 1);
	int q; scanf("%d", &q);
	while (q--) {
		int typ, a, b; scanf("%d %d %d", &typ, &a, &b);
		if (typ == 1) {
			int val; scanf("%d", &val);
			Add(1, 0, n - 1, a, b, val);
		} else {
			node res = Get(1, 0, n - 1, a, b);
			printf("%d\n", bool(res.zers == 0 && res.x == 0 && res.min_odd >= 0 && res.min_even >= 0));
		}
	}
	return 0;
}
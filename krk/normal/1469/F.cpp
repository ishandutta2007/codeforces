#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 4194304;

int n, k;
int a[Maxn];
ll st[Maxm];
ll fl[Maxm];
int res = Maxn + 1;

void downOn(int v, int sz, ll f)
{
	st[v] += ll(sz) * f;
	fl[v] += f;
}

void Down(int v, int l, int m, int r)
{
	if (fl[v]) {
		downOn(2 * v, m + 1 - l, fl[v]);
		downOn(2 * v + 1, r - m, fl[v]);
		fl[v] = 0;
	}
}

void Union(int v)
{
	st[v] = st[2 * v] + st[2 * v + 1];
}

void Add(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(v, r - l + 1, val);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

int Get(int v, int l, int r, ll ind)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (ind <= st[2 * v]) return Get(2 * v, l, m, ind);
		else return Get(2 * v + 1, m + 1, r, ind - st[2 * v]); 
	}
}

int getMin(int v, int l, int r)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (st[2 * v] > 0) return getMin(2 * v, l, m);
		else return getMin(2 * v + 1, m + 1, r);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	Add(1, 0, Maxn, 0, 0, 1);
	for (int i = n - 1; i >= 0; i--) {
		if (st[1] == 0) break;
		int mn = getMin(1, 0, Maxn);
		Add(1, 0, Maxn, mn, mn, -1);
		if (a[i] >= 3)
			Add(1, 0, Maxn, mn + 2, mn + 1 + (a[i] - 1) / 2, 1);
		if (a[i] >= 2)
			Add(1, 0, Maxn, mn + 2, mn + 1 + a[i] / 2, 1);
		if (st[1] >= k) res = min(res, Get(1, 0, Maxn, k));
	}
	printf("%d\n", res <= Maxn? res: -1);
    return 0;
}
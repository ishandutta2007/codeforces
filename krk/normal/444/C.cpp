#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

struct pos {
	int l, r, c;
	pos(int l = 0, int r = 0, int c = 0): l(l), r(r), c(c) {}
	bool operator <(const pos &p) const {
		if (l != p.l) return l < p.l;
		if (r != p.r) return r < p.r;
	}
};

int n, m;
set <pos> S;
ll sum[Maxm], flag[Maxm];

void Down(int v, int l, int m, int r)
{
	if (flag[v]) {
		sum[2 * v] += ll(m - l + 1) * flag[v]; flag[2 * v] += flag[v];
		sum[2 * v + 1] += ll(r - m) * flag[v]; flag[2 * v + 1] += flag[v];
		flag[v] = 0;
	}
}

void Add(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) { sum[v] += ll(r - l + 1) * val; flag[v] += val; }
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		sum[v] = sum[2 * v] + sum[2 * v + 1];
	}
}

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		ll res = 0;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		sum[v] = sum[2 * v] + sum[2 * v + 1];
		return res;
	}
}

void Change(int l, int r, int x)
{
	set <pos>::iterator it = S.upper_bound(pos(l, n + 1)); it--;
	pos beg = *it;
	set <pos>::iterator it2 = S.upper_bound(pos(r, n + 1)); it2--;
	pos en = *it2; it2++;
	for (set <pos>::iterator it3 = it; it3 != it2; ) {
		int L = max(l, it3->l), R = min(r, it3->r);
		Add(1, 1, n, L, R, abs(it3->c - x));
		S.erase(it3++);
	}
	if (beg.l < l) S.insert(pos(beg.l, l - 1, beg.c));
	S.insert(pos(l, r, x));
	if (r < en.r) S.insert(pos(r + 1, en.r, en.c));
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		S.insert(pos(i, i, i));
	while (m--) {
		int typ, l, r, x;
		scanf("%d %d %d", &typ, &l, &r);
		if (typ == 1) {
			scanf("%d", &x);
			Change(l, r, x);
		} else printf("%I64d\n", Get(1, 1, n, l, r));
	}
	return 0;
}
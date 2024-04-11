#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, q;
int a[Maxn];
map <int, int> M;
ll fl[Maxm], sum[Maxm];
int mn[Maxm];

void downOn(int v, int siz, ll f)
{
	fl[v] = f;
	sum[v] = ll(siz) * f;
	mn[v] = f;
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
	sum[v] = sum[2 * v] + sum[2 * v + 1];
	mn[v] = min(mn[2 * v], mn[2 * v + 1]); 
}

void Create(int v, int l, int r)
{
	if (l == r) { sum[v] = a[l]; mn[v] = a[l]; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(v, r - l + 1, val);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
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
		return res;
	}
}

int Solve(int v, int l, int r, ll &rem)
{
	if (l == r)
		if (rem >= sum[v]) { rem -= sum[v]; return 1; }
		else return 0;
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (rem >= sum[2 * v]) {
			rem -= sum[2 * v];
			return m + 1 - l + Solve(2 * v + 1, m + 1, r, rem);
		} else if (rem < mn[2 * v])
			return Solve(2 * v + 1, m + 1, r, rem);
		else {
			int res = Solve(2 * v, l, m, rem);
			res += Solve(2 * v + 1, m + 1, r, rem);
			return res;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		M[i] = a[i];
	}
	Create(1, 1, n);
	while (q--) {
		int t, x, y; scanf("%d %d %d", &t, &x, &y);
		if (t == 1) {
			auto it = M.lower_bound(x);
			if (y <= it->second) continue;
			int lst = 0;
			it = M.upper_bound(x);
			while (it != M.begin()) {
				it--;
				if (it->second <= y) M.erase(it++);
				else { lst = it->first; break; }
			}
			Update(1, 1, n, lst + 1, x, y);
			M[x] = y;
		} else {
			ll got = (x > 1? Get(1, 1, n, 1, x - 1): 0ll) + y;
			printf("%d\n", Solve(1, 1, n, got) - (x - 1));
		}
	}
    return 0;
}
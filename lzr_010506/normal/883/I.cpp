#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 3e5 + 10;
const int inf = 1e9 + 17;
int n,k;
int a[N],f[N];

struct tree
{
	int l, r, mn;
}T[N << 2];

void build(int rt,int l,int r)
{
	T[rt].l = l;
	T[rt].r = r;
	if (l == r) {T[rt].mn = inf; return;}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	T[rt].mn = min(T[ls].mn, T[rs].mn);
}

void update(int rt, int k)
{
	T[rt].mn = min(T[rt].mn, f[k]);
	if (T[rt].l == T[rt].r)return;
	int mid = T[rt].l + T[rt].r >> 1;
	if (k <= mid) update(ls, k);
	else update(rs, k);
}

int query(int rt,int l,int r)
{
	if (l <= T[rt].l && T[rt].r <= r) return T[rt].mn;
	int mid = T[rt].l + T[rt].r >> 1, ret = inf;
	if (l <= mid) ret = min(ret,query(ls, l, r));
	if (r > mid) ret = min(ret,query(rs, l, r));
	return ret;
}

bool check(int i, int x)
{
	int l = 0, r = i - k;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (a[i] - a[mid + 1] <= x) r = mid;
		else l = mid + 1;
	}
	int ret = 0;
	if (l) ret = query(1, l, i - k);
	return ret <= x;
}

int main()
{
	n = read();
	k = read();
	build(1, 1, n);
	rep(i, 1, n)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	rep(i, 1, k - 1) f[i] = inf;
	rep(i, k, n)
	{
		int l = a[i] - a[i - k + 1], r = a[i];
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(i, mid)) r = mid;
			else l = mid + 1;
		}
		f[i] = l;
		update(1, i);
	}
	printf("%d\n",f[n]);
	return 0;
}
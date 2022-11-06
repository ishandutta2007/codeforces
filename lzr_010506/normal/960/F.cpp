#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
//#define ls rt << 1
//#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 10;
int n, m, tot, ans, rt[N];
struct Node
{
	int ls, rs, mx;
}t[2000010];

void update(int &rt, int l, int r, int pt, int val)
{
	if (!rt) t[++ tot] = t[rt], rt = tot;
	if (l == r)
	{
		t[rt].mx = max(t[rt].mx, val);
		return;
	}
	int mid = l + r >> 1;
	if (pt <= mid) update(t[rt].ls, l, mid, pt, val);
	else update(t[rt].rs, mid + 1, r, pt, val);
	t[rt].mx = max(t[t[rt].ls].mx, t[t[rt].rs].mx);
}

int query(int rt, int l, int r, int L, int R)
{
	if (!rt) return 0;
	if (L <= l && r <= R) return t[rt].mx;
	int mid = l + r >> 1;
	int res = 0;
	if (L <= mid) res = max(res, query(t[rt].ls, l, mid, L, R));
	if (R > mid) res = max(res, query(t[rt].rs, mid + 1, r, L, R));
	return res;
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		int w = read();
		if (!w)
		{
			update(rt[v], 0, 100000, 0, 1);
			ans = max(ans, 1);
		}
		else
		{
			int U = query(rt[u], 0, 100000, 0, w - 1) + 1;
			ans = max(ans, U);
			update(rt[v], 0, 100000, w, U);
		}
	}
	printf("%d\n", ans);
	return 0;
}
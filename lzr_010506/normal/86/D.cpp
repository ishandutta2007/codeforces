#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
#define ls rt << 1
#define rs rt << 1 | 1
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

struct Query
{
	int l, r, id;
}q[200010];
int n, t, a[200010], vis[1000010];
int blk;
ll num, ans[200010];

bool cmp(Query a, Query b)
{
	if(a.l / blk == b.l / blk) return a.r < b.r;
	return a.l < b.l;
}

void remove(int x)
{
	vis[a[x]] --;
	num -= a[x] * ((vis[a[x]] + 1) * (vis[a[x]] + 1) - vis[a[x]] * vis[a[x]]);
}

void add(int x)
{
	vis[a[x]] ++;
	num += a[x] * (vis[a[x]] * vis[a[x]] - (vis[a[x]] - 1) * (vis[a[x]] - 1));
}

int main()
{
	n = read();
	t = read();
	blk = (int)sqrt(n);
	rep(i, 1, n)
		a[i] = read();
	rep(i, 1, t)
		q[i].l = read(), q[i].r = read(), q[i].id = i;
	sort(q + 1, q + 1 + t, cmp);
	int l = 1, r = 0;
	rep(i, 1, t)
	{
		int L = q[i].l;
		int R = q[i].r;
		while(l < L) remove(l ++);
		while(l > L) add(-- l);
		while(r < R) add(++ r);
		while(r > R) remove(r --);
		ans[q[i].id] = num;
	}
	rep(i, 1, t) cout << ans[i] << endl;
	return 0;
}
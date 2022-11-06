#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define lson (p << 1)
#define rson (p << 1 | 1)
#define vi vector<int>
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
const int N = 1e5 + 10, inf = 2e5 + 10, K = 110;

template <class T> void mini(T &l, T r) {l = min(l, r);}
int n, k;
int l[K], r[K];

struct Seg
{
	int tr[N * 2 * 4];
	void clear()
	{
		fill_n(tr, N * 2 * 4, inf);
	}

	void push_down(int p, int l, int r)
	{
		if (tr[p] != inf)
		{
			mini(tr[lson], tr[p]);
			mini(tr[rson], tr[p]);
			tr[p] = inf;
		}
	}

	void update(int p, int l, int r, int L, int R, int v)
	{
		if (L <= l && R >= r)
		{
			mini(tr[p], v);
			return;
		}
		int mid = l + r >> 1;
		push_down(p, l, r);
		if (L <= mid) update(lson, l, mid, L, R, v);
		if (R >= mid + 1) update(rson, mid + 1, r, L, R, v);
	}

	int query(int p, int l, int r, int x)
	{
		if (l == r)  return tr[p];
		push_down(p, l, r);
		int mid = l + r >> 1;
		if (x <= mid) return query(lson, l, mid, x);
		return query(rson, mid + 1, r, x);
	}

} dp[2][2];

void chg(int &x)
{
	if (x <= -n) x = -n;
	if (x >= n) x = n;
}

int main()
{
	n = read();
	k = read();
	rep(i, 1, k)
		l[i] = read(), r[i] = read();
	rep(i, 0, 1) dp[0][i].clear();

	dp[0][0].update(1, 0, 2 * n, n + 0, n + 0, 0);
	rep(i, 1, k)
	{
		int d = l[i] - r[i - 1];
		rep(x, 0, 1) dp[i & 1][x].clear();
		rep(t, 0, 1)
		{
			for (int j = -n; j <= n; ++j)
			{
				int used = dp[(i - 1) & 1][t].query(1, 0, 2 * n, n + j);
				int od = j;
				int L, rr;
				if (!t) od += d;
				else od -= d;
				if (!t) L = od + (r[i] - l[i]);
				else L = od - (r[i] - l[i]);
				chg(L);
				dp[i & 1][t].update(1, 0, 2 * n, L + n, L + n, used);

				od = j;
				if (t == 0) od += d;
				else od -= d;
				L = od - (r[i] - l[i]); chg(L);
				rr = od + (r[i] - l[i]); chg(rr);
				dp[i & 1][!t].update(1, 0, 2 * n, L + n, rr + n, used + 1);
				od = j;
				if (t == 0) od += d;
				else od -= d;
				L = od - (r[i] - l[i]);
				chg(L);
				rr = od + (r[i] - l[i]);
				chg(rr);
				dp[i & 1][t].update(1, 0, 2 * n, L + n, rr + n, used + 2);

			}
		}
	}

	int ans = inf;
	rep(t, 0, 1)
	{
		int nd;
		if (!t) nd = 0 - (2 * n - r[k]);
		else nd = 0 + (2 * n - r[k]);
		if (nd >= -n && nd <= n)
		{
			int x = dp[k & 1][t].query(1, 0, 2 * n, nd + n);
			mini(ans, x);
		}
	}
	if (ans == inf) puts("Hungry");
	else
	{
		puts("Full");
		cout << ans << endl;
	}
	return 0;
}
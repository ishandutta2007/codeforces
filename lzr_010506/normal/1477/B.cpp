#include <bits/stdc++.h>
#define ull unsigned long long
//#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
char a[N], b[N];
struct Node
{
    int tag, w, lc, rc;
}t[N << 2];
inline void build (int rt, int l, int r)
{
	t[rt].tag = -1;
	if (l == r)
	{
		t[rt].w = b[l] - '0';
		return;
	}
	int mid = l + r >> 1;
	t[rt].lc = rt * 2;
	build(t[rt].lc, l, mid);
	t[rt].rc = rt * 2 + 1;
	build(t[rt].rc, mid + 1, r);
	t[rt].w = t[t[rt].rc].w + t[t[rt].lc].w;
}

inline void pushdown(int rt, int l, int r)
{
	int le = t[rt].lc, ri = t[rt].rc, mid = l + r >> 1;
	t[le].w = t[rt].tag * (mid - l + 1);
	t[le].tag = t[rt].tag;
	t[ri].w = t[rt].tag * (r - mid);
	t[ri].tag = t[rt].tag;
	t[rt].tag = -1;
}

inline void update(int rt, int l, int r, int ll, int rr, int v)
{
	if (l == ll && r == rr)
	{
		t[rt].w = v * (r - l + 1);
		t[rt].tag = v;
		return;
	}
	if (t[rt].tag != -1) pushdown(rt, l, r);
	int mid = l + r >> 1;
	if (rr <= mid) update(t[rt].lc, l, mid, ll, rr, v);
	else if (ll > mid) update(t[rt].rc, mid + 1, r, ll, rr, v);
	else
	{
		update(t[rt].lc, l, mid, ll, mid, v);
		update(t[rt].rc, mid + 1, r, mid + 1, rr, v);
	}
	t[rt].w = t[t[rt].lc].w + t[t[rt].rc].w;
}

inline int  query(int rt, int l, int r, int ll, int rr)
{
	int ans = 0;
	if (l == ll && r == rr)
	{
		return t[rt].w;
	}
	if (t[rt].tag != -1) pushdown(rt, l, r);
	int mid = l + r >> 1;
	if (rr <= mid) ans += query(t[rt].lc, l, mid, ll, rr);
	else if (ll > mid) ans += query(t[rt].rc, mid + 1, r, ll, rr);
	else
	{
		ans += query(t[rt].lc, l, mid, ll, mid);
		ans += query(t[rt].rc, mid + 1, r, mid + 1, rr);
	}
	return ans;
}
pair<int, int> Q[N];
int main()
{
	int T = read();
	while (T --)
	{
		int n = read();
		int q = read();
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		build(1, 1, n);
		rep(i, 1, q)
		{
			int x, y;
			x = read();
			y = read();
			Q[i] = mp(x, y);
		}
		rrep(i, q, 1)
		{
			int sum = query(1, 1, n, Q[i].X, Q[i].Y);
			int len = Q[i].Y - Q[i].X + 1;
			if(len % 2 == 1)
			{
				if(sum > len / 2) update(1, 1, n, Q[i].X, Q[i].Y, 1);
				else update(1, 1, n, Q[i].X, Q[i].Y, 0);
			}
			else
			{
				if(sum == len / 2) {puts("NO"); goto L1;}
				else if(sum < len / 2) update(1, 1, n, Q[i].X, Q[i].Y, 0);
				else update(1, 1, n, Q[i].X, Q[i].Y, 1);
			}
		}
		rep(i, 1, n) if(query(1, 1, n, i, i) != a[i] - '0') {puts("NO"); goto L1;}
		puts("YES");
		L1:;
	}

	return 0;
}
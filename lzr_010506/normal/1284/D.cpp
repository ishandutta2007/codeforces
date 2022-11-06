#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define LD long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 1000010;
struct Seg 
{
	int sa, sb, ea, eb;
} s[N];
int sa[N];
struct SegT 
{
	int mx[N << 2], mn[N << 2];
	void modify (int pos, int val, int l, int r, int rt) 
	{
		if(l != r);
		if (l == r) 
		{
			mn[rt] = mx[rt] = val;
			return;
		}
		int mid = l + r >> 1;
		if (pos <= mid) modify (pos, val, l, mid, ls);
		else modify (pos, val, mid + 1, r, rs);
		mn[rt] = min (mn[ls], mn[rs]);
		mx[rt] = max (mx[ls], mx[rs]);
	}
	pii ask (int L, int R, int l, int r, int rt) 
	{
		if (L <= l && r <= R) return mp (mx[rt],mn[rt]);
		int mid = l + r >> 1;
		if (R <= mid) return ask (L, R, l, mid, ls);
		else if (L >= mid + 1) return ask (L, R, mid + 1, r, rs);
		else 
		{
			pii ans1 = ask (L, mid, l, mid, ls);
			pii ans2 = ask (mid + 1, R, mid + 1, r, rs);
			return mp (max(ans1.X, ans2.X), min (ans1.Y, ans2.Y));
		}
	}
}Ts, Te;
bool cmp(Seg a, Seg b)
{
	return a.sa < b.sa;
}
bool cmp1(Seg a, Seg b)
{
	return a.sb < b.sb;
}
int main () 
{
    int n = read();
    rep(i, 1, n) s[i].sa = read(), s[i].ea = read(), s[i].sb = read(), s[i].eb = read();
	sort (s + 1, s + 1 + n, cmp);
	rep(i, 1, n)
	{
		Ts.modify (i, s[i].sb, 1, n, 1);
		Te.modify (i, s[i].eb, 1, n, 1);
	}
	bool flag = 0;
	rep(i, 1, n) 
	{
		int l = i + 1, r = n, mid, p = -1;
		while (l <= r) 
		{
			mid = l + r >> 1;
			if (s[mid].sa <= s[i].ea) p = max(p, mid), l = mid + 1;
			else r = mid - 1;
		}
		if (i + 1 > p) continue;
		pii ans1 = Ts.ask (i + 1, p, 1, n, 1);
		pii ans2 = Te.ask (i + 1, p, 1, n, 1);
		if (ans1.X > s[i].eb || ans2.Y < s[i].sb) flag = 1;
		else continue;
	}
	sort (s + 1, s + 1 + n, cmp1);
	memset(Ts.mn, 0, sizeof(Ts.mn));
	memset(Ts.mx, 0, sizeof(Ts.mx));
	memset(Te.mn, 0, sizeof(Te.mn));
	memset(Te.mx, 0, sizeof(Te.mx));
	rep(i, 1, n)
	{
		Ts.modify (i, s[i].sa, 1, n, 1);
		Te.modify (i, s[i].ea, 1, n, 1);
	}
	rep(i, 1, n) 
	{
		int l = i + 1, r = n, mid, p = -1;
		while (l <= r) 
		{
			mid = l + r >> 1;
			if (s[mid].sb <= s[i].eb) p = max(p, mid), l = mid + 1;
			else r = mid-1;
		}
		if (i + 1 > p) continue;
		pii ans1 = Ts.ask (i + 1, p, 1, n, 1);
		pii ans2 = Te.ask (i + 1, p, 1, n, 1);
		if (ans1.X > s[i].ea || ans2.Y < s[i].sa) flag = 1;
		else continue;
	}
	if(!flag) puts("YES");
	else puts("NO");
    return 0;
}
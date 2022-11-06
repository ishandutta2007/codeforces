#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
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
struct P
{
	int x, y;
} p[N];
struct Rec
{
	int x1, y1, x2, y2, z;
	Rec(){}
	Rec( P q ):x1(q.x),y1(q.y),x2(q.x),y2(q.y){}
	inline bool cover( const Rec &r ) const
	{
		return x1 <= r.x1 && r.x2 <= x2 && y1 <= r.y1 && r.y2 <= y2;
	}
	inline bool jiao( const Rec &r ) const
	{
		return !(x2 < r.x1 || x1 > r.x2) && !(y2 < r.y1 || y1 > r.y2);
	}
} R[N];
inline bool cpx(int a, int b)
{
	return p[a].x != p[b].x ? p[a].x < p[b].x : p[a].y < p[b].y;
}
inline bool cpy(int a, int b)
{
	return p[a].y != p[b].y ? p[a].y < p[b].y : p[a].x < p[b].x;
}
inline bool cpz(int a, int b)
{
	return R[a].z < R[b].z;
}

struct KD_T
{
	Rec val[8 * N];
	bool flag[8 * N];
	void pull(int rt)
	{
		val[rt].x1 = min(val[ls].x1, val[rs].x1);
		val[rt].y1 = min(val[ls].y1, val[rs].y1);
		val[rt].x2 = max(val[ls].x2, val[rs].x2);
		val[rt].y2 = max(val[ls].y2, val[rs].y2);
		val[rt].z = min(val[ls].z, val[rs].z);
	}
	void init(int rt, int n, int *lst, int lv)
	{
		if (n == 1)
		{
			val[rt] = p[lst[0]];
			val[rt].z = lst[0];
			flag[rt] = 1;
			return;
		}
		sort(lst, lst + n, lv % 2 == 0 ? cpx : cpy);
		init(ls, n / 2, lst, lv + 1);
		init(rs, n - n / 2, lst + n / 2, lv + 1);
		pull(rt);
	}
	void del_min( int rt )
	{
		if (flag[rt])
		{
			val[rt].z = INF;
			return;
		}
		if (val[ls].z == val[rt].z) del_min(rt * 2);
		else del_min(rt * 2 + 1);
		pull(rt);
	}
	void up( int rt )
	{
		do pull(rt);
		while (rt /= 2);
	}
	pii Q(int rt, const Rec &r)
	{
		if (!r.jiao(val[rt])) return mp(INF, -1);
		if (r.cover(val[rt])) return mp(val[rt].z, rt);
		return min(Q(rt * 2, r), Q(rt * 2 + 1, r));
	}
} kdt;

int n,m;
int ans[N],lst[N],srt[N];

int main()
{
	n = read();
	rep(i, 0, n - 1)
	{
	    R[i].x1 = read();
	    R[i].x2 = read();
	    R[i].y1 = read();
	    R[i].y2 = read();
	    R[i].z = read();
	}
	m = read();
	rep(i, 0, m - 1) p[i].x = read(), p[i].y = read();
	rep(i, 0, m - 1) lst[i] = i;
	kdt.init(1, m, lst, 0);
	rep(i, 0, n - 1) srt[i] = i;
	sort(srt, srt + n, cpz);
	rep(i, 0, n - 1)
	{
		pii ret = kdt.Q(1, R[srt[i]]);
		if (ret.X == INF) continue;
		kdt.del_min(ret.Y);
		kdt.up(ret.Y / 2);
		ans[ret.X] = srt[i] + 1;
	}
	rep(i, 0, m - 1) printf("%d\n", ans[i]);
}
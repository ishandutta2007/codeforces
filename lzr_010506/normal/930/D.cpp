#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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
#define N 1000010
#define M 1000010
#define INF 1000000000
vi pt[N];
int n, X[N], Y[N];
bool blk[N], flag1, flag0;
ll ans;
int lq[N],le[N],lz[N],lc[N];
void work(int x)
{
	int i,j;
	int tq=-INF,te=-INF,tz=INF,tc=INF;
	rep(i, 1, N - 1)
	{
		rep(j, 0, sz(pt[i]) - 1)
		{
			tq = max(tq, pt[i][j]);
			tz = min(tz, pt[i][j]);
		}
		lq[i] = tq;
		lz[i] = tz;
	}
	rrep(i, N - 1, 0)
	{
		rep(j, 0, sz(pt[i]) - 1)
		{
			te = max(te, pt[i][j]);
			tc = min(tc, pt[i][j]);
		}
		le[i] = te;
		lc[i] = tc;
		if((i & 1) == x)
			if(min(lq[i], le[i]) >= max(lz[i], lc[i]))
				ans += (min(lq[i], le[i]) - max(lz[i], lc[i])) / 2;
	}
}
int main()
{
	n = read();
	rep(i, 1, n)
	{
		int x = read();
		int y = read();
		X[i] = x - y;
		Y[i] = x + y;
		X[i] += 500000;
		Y[i] += 500000;
		if(x + y & 1) blk[i] = 1, flag1 = 1;
		else flag0 = 1;
	}
	if(flag0)
	{
		rep(i, 1, n)
			if(!blk[i])
				pt[X[i]].pb(Y[i]);
		work(1);
	}
	rep(i, 0, N - 1)
 		pt[i].clear();

	if(flag1)
	{
		rep(i, 1, n)
			if(blk[i])
				pt[X[i]].pb(Y[i]);
		work(0);
	}
	printf("%lld\n",ans);
	return 0;
}
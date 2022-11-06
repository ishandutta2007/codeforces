#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
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
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ite iterator
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
using namespace std;
const int N = 1000010;
int n, b[N];
ll a[N];
vector<ll> v[65];
ll ans[N], tot, now[N];
int z[N];
int log2(ll x)
{
	if(x == 1) return 0;
	return log2(x >> 1) + 1;
}
int main()
{
	n = read();
	rep(i, 1, n)
	{
		a[i] = read1();
		b[i] = log2(a[i]);
		v[b[i]].pb(a[i]);
	}
	int nw = 0;
	rrep(i, 59, 0)
	{
		if(v[i].size() > nw + 1)
		{
			puts("No");
			return 0;
		}
		int l = 0;
		rep0(j, v[i].size())
		{
			int T = 0;
			if(l)
				rep(r, l, tot)
				{
					T ^= (ans[r] >> i) & 1;
					if(T == 1)
					{
						z[j] = r;
						l = r + 1;
						break;
					}
				}
			else z[j] = 0, l ++;
		}
		int cnt1 = 0;
		int A = 1, B = 0;
		while(A <= tot || B + 1 <= v[i].size())
		{
			if(B == v[i].size() || (A <= tot && z[B] >= A))
			{
				now[++ cnt1] = ans[A ++];
				continue;
			}
			now[++ cnt1] = v[i][B ++];
		}
		tot = cnt1;
		rep(j, 1, tot) ans[j] = now[j];
		nw = 0;
		if(i)
			rep(j, 1, tot)
				nw += (ans[j] >> (i - 1)) & 1;
	}
	puts("Yes");
	rep(i, 1, n)
		printf("%lld ",ans[i]);
}
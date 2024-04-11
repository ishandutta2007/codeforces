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
const int N = 2e6 + 10;
#define int long long
 
signed main() 
{
	ll kk = read1();
	ll lll = read1();
	ll rr = read1();
	ll tt = read1();
	ll xx = read1();
	ll yy = read1();
	__int128 k = kk, l = lll, r = rr, t = tt, x = xx, y = yy;
	if(x >= y)
	{
		if(k + y > r)
		{
			if((__int128)k + (__int128)y * (t - 1) < (__int128)l + (__int128)x * t) puts("No");
			else puts("Yes");
		}
		else 
		{
			if((__int128)k + (__int128)y * t < (__int128)l + (__int128)x * t) puts("No");
			else puts("Yes");
		}
		return 0;
	}

	if(r - l - x >= y) {puts("Yes"); return 0;}
	__int128 i = 1;
	__int128  L = ((l - k + i * x) % y + y) % y;
	set<__int128 > S;
	while(i <= t)
	{
		S.insert(L);
		if(L && L + r - l - x < y) {puts("No"); return 0;}
		__int128  d;
		if(L == 0) d = 1;
		else d = (y + x - 1 - L) / x;
		i += d;
		L = (L + x * d) % y;
		if(S.count(L)) {puts("Yes"); return 0;}
	}
	puts("Yes");
	return 0;
}
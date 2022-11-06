#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
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
const int N = 1010;
pii a[N];
int main()
{
	int n = read();
	rep(i, 1, n) 
	{
		int x, y;
		x = read();
		y = read();
		a[i] = mp(x, y);
	}
	while(1)
	{
		ll x = 0;
		rep(i, 1, n) x |= 1 << ((a[i].X + a[i].Y) & 1);
		if(x == 3)
		{
			int cnt1 = 0;
			rep(i, 1, n)
				if((a[i].X + a[i].Y) & 1) cnt1 ++;
			printf("%d\n", cnt1);
			rep(i, 1, n)
				if((a[i].X + a[i].Y) & 1) 
					printf("%d ", i);
			return 0;
		}
		rep(i, 1, n)
		{
			int x = a[i].X, y = a[i].Y;
			a[i].X = (x + y) >> 1;
			a[i].Y = (x - y) >> 1;
		}
		//rep(i, 1, n) {printf("%d %d\n", a[i].X, a[i].Y);}
		//puts("asd");
	}
	

	return 0;
}
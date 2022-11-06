#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define pb push_back
#define mp make_pair
#define db double
#define sz(x) (int)(x).size()
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

using namespace std;
const db eps = 1e-9;
int n;
ll x,s;
ll w[200010],h[200010],c[200010];
map<ll,ll>cnt1,cnt2;
ll gcd(ll a, ll b)
{
	while(a)
	{
		ll c = a;
		a = b % a;
		b = c;
	}
	return b;
}
int main()
{
	n = read();
	rep(i, 1, n)
	{
		w[i] = read1();
		h[i] = read1();
		c[i] = read1();
		x = gcd(x, c[i]);
	}
	rep(i, 1, n)
	{
		c[i] /= x;
		s += c[i];
		cnt1[w[i]] += c[i];
		cnt2[h[i]] += c[i];
	}
	rep(i, 1, n)
	{
		db t1 = (db)cnt1[w[i]] / s;
		db t2 = (db)c[i] / cnt2[h[i]];
		if (!(t1 - t2 < eps && t1 - t2 > -eps))
		{
			printf("%d\n",0);
			return 0;
		}
	}
	ll ans = 0;
	for (int i = 1; 1LL * i * i <= x; i ++)
		if (x % i == 0)
		{
			ans ++;
			if (1LL * i * i != x) ans ++;
		}
	printf("%lld\n",ans);
	return 0;
}
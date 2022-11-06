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
const int N = 1e6 + 10; 
ll n, m, lim;
ll b[N];
ll k, gnm, lnm;
int p1[N], p2[N];

int gcd(int a, int b)
{
	while(a)
	{
		int c = a;
		a = b % a;
		b = c;
	}
	return b;
}

void exgcd(ll &x, ll &y, ll a, ll b) 
{
	if (!b) 
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(x, y, b, a % b);
	ll t = x;
	x = y;
	y = t - a / b * y;
}

bool check(ll day) 
{
	ll tot = day;
	rep(i, 1, lim)
	{
		if (b[i] == -1 || day < b[i]) continue;
		tot -= (day - b[i]) / lnm + 1;
	}
	return tot >= k;
}

int main() 
{
	n = read1();
	m = read1();
	k = read1();
	lim = max(n, m) * 2;
	gnm = gcd(n, m);
	lnm = n / gnm * m;
	rep(i, 1, n)
	{
		int a = read();
		p1[a] = i;
	}
	rep(i, 1, m)
	{
		int b = read();
		p2[b] = i;
	}
	ll bx, by, mod = m / gnm;
	exgcd(bx, by, n, m);
	rep(i, 1, lim)
		if (p1[i] && p2[i] && p1[i] % gnm == p2[i] % gnm) 
		{
			ll d = p2[i] - p1[i];
			ll r = d / gnm;
			ll x = bx * r;
			x = (x % mod + mod) % mod;
			b[i] = x * n + p1[i];
		} 
		else b[i] = -1;
	
	ll l = 0, r = 1e18, mid;
	while (l <= r) 
	{
		mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", l);
}
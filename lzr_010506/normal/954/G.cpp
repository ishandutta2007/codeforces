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
#define sz(x) (x).size()
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
const int N = 1010000;
int n, m;
ll k, a[N], b[N];
bool check(ll t) 
{
	rep(i, 1, n) b[i] = 0;
	ll A = 0, s = k;
	rep(i, 1, m + 1) A += a[i];
	rep(i, 1, n)
	{
		if (A < t)
		{
			s -= t - A;
			if (s < 0) return 0;
			b[min(n, i + m)] += t - A;
			A = t;
		}
		if (i >= m) A -= a[i - m] + b[i - m];
		if (i + 1 + m <= n) A += a[i + 1 + m];
	}
	return s >= 0;
}
int main() 
{
	n = read();
	m = read();
	k = read1();
	ll ans = 0, l = 0, r = k;
	rep(i, 1, n)
	{
		a[i] = read1();
		r += a[i];
	}
	while (l <= r) 
	{
		ll mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
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
#define Alsls(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
int n, m, k, p, h[N], a[N];
int now[N];
bool check(ll mid) 
{
	priority_queue<pii> q;
	rep(i, 1, n)
	{
		now[i] = 0;
		if (m > mid / a[i]) q.push(mp(m - mid / a[i], i));
	}
	rrep(i, m, 1)
		rep(j, 1, k)
		{
			if (q.empty()) 
			{
				ll res = 0;
				rep(x, 1, n) res += (max(0ll, h[x] - (mid + 1LL * now[x] * p - 1LL * a[x] * m)) + p - 1) / p;
				return res <= (i - 1) * k + k - j + 1;
			} 
			else
			{
				pii t = q.top(); 
				q.pop();
				if (t.X >= i) return false;
				now[t.Y] ++;
				ll tmp = m - (mid + 1LL * now[t.Y] * p) / a[t.Y];
				if (tmp >= i) return false;
				if (tmp > 0) t.X = tmp, q.push(t);
			}
		}
	if (!q.empty()) return false;
	rep(x, 1, n) 
		if (mid + 1LL * now[x] * p - 1LL * a[x] * m < h[x]) return false;
	return true;
}
 
int main() 
{
	n = read();
	m = read();
	k = read();
	p = read();
	rep(i, 1, n)
	{
		h[i] = read();
		a[i] = read();
	}
	ll l = 0, r = 100000000000000ll, ans = 1;
	while (l <= r) 
	{
		ll mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}
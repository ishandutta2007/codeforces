#include <bits/stdc++.h>
#include <algorithm>
#include <set>
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
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
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
const int N = 2010;
int a[N], b[N];
pii ans1, ans21, ans22;
pair<ll, pii> two[N * N];
int main()
{
	ll s = 0;
	int n = read();
	rep(i, 1, n) a[i] = read(), s += a[i];
	int m = read();
	rep(i, 1, m) b[i] = read(), s -= b[i];
	ll s2 = 1e18;
	rep(i, 1, n)
		rep(j, 1, m)
		{
			ll cur = abs(s + 2 * b[j] - 2 * a[i]);
			if(cur < s2) s2 = cur, ans1 = mp(i, j);
		}

	int tot = 0;
	rep(i, 1, m)
		rep(j, i + 1, m)
			two[++ tot] = mp(2LL * b[i] + 2LL * b[j], mp(i, j));
	sort(two + 1, two + tot + 1);
	ll s3 = 1e18;
	rep(i, 1, n)
		rep(j, i + 1, n)
		{
			ll tmp = 2LL * a[i] + 2LL * a[j] - s;
			int p = lower_bound(two + 1, two + tot + 1, mp(tmp, mp(0, 0))) - two;
			rep(t, max(1, p - 2), min(p + 2, tot))
			{
				ll cur = abs(s + two[t].X - 2LL * a[i] - 2LL * a[j]);
				if(cur < s3)
				{
					s3 = cur;
					ans21 = mp(i, two[t].Y.X);
					ans22 = mp(j, two[t].Y.Y);
				}
			}
		}

	ll ans = min(min(abs(s), abs(s2)), abs(s3));
	printf("%lld\n", ans);
	if(ans == s) printf("0\n");
	else if(abs(s2) == ans) {printf("1\n"); printf("%d %d\n", ans1.X, ans1.Y);}
	else {printf("2\n"); printf("%d %d\n%d %d\n", ans21.X, ans21.Y, ans22.X, ans22.Y);}
	return 0;
}
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
#define dep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 2e5 + 10;
ll ans;
void Do(int n, int m, int k, int a[N], int b[N], int c[N])
{
	rep(i, 1, n)
		if(a[i] >= c[1] && a[i] <= b[m])
		{
			int q = upper_bound(c + 1, c + k + 1, a[i]) - c - 1;
			int j = lower_bound(b + 1, b + m + 1, a[i]) - b;
			ans = min(ans, 1LL * (a[i] - b[j]) * (a[i] - b[j]) + 1ll * (b[j] - c[q]) * (b[j] - c[q]) + 1ll * (c[q] - a[i]) * (c[q] - a[i]));
		}
	rep(i, 1, n)
		if(a[i] >= b[1] && a[i] <= c[k])
		{
			int j = upper_bound(b + 1, b + m + 1, a[i]) - b - 1;
			int q = lower_bound(c + 1, c + k + 1, a[i]) - c;
			ans = min(ans, 1ll * (a[i] - b[j]) * (a[i] - b[j]) + 1ll * (b[j] - c[q]) * (b[j] - c[q]) + 1ll * (c[q] - a[i]) * (c[q] - a[i]));
		}
}

int n, m, k, a[N], b[N], c[N];

int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		m = read();
		k = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, m) b[i] = read();
		rep(i, 1, k) c[i] = read();
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		sort(c + 1, c + k + 1);
		ans = 1ll * (a[1] - b[1]) * (a[1] - b[1]) + 1ll * (b[1] - c[1]) * (b[1] - c[1]) + 1ll * (c[1] - a[1]) * (c[1] - a[1]);
		Do(n, m, k, a, b, c);
		Do(m, k, n, b, c, a);
		Do(k, n, m, c, a, b);
		cout << ans << endl;
	}
	return 0;
}
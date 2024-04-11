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
const int M = 40;
const int K = 18;
const int mod = 998244353;
const int maxn = 111;
int n, q1, q2, ans[N];
vector<pii> a;
void ask(int x)
{
	printf("+ %d\n", x);
	fflush(stdout);
	int xx = read();
	int yy = read();
	a.pb(mp(xx, yy));
}
int main()
{
	n = read();
	int x = read();
	int y = read();
	a.pb(mp(x, y));
	rep(i, 1, n - 1) ask(i);
	ask(1);
	rrep(i, n, 1) a[i].X -= a[i - 1].X, a[i].Y -= a[i - 1].Y;
	memset(ans, -1, sizeof(ans));
	ans[1] = (a[n].X - a[1].X);
	rep(i, 2, n - 1)
		if(a[i].X)
		{
			ans[i] = 0;
			while(ans[i] * (ans[i] - 1) / 2 < a[i].X) ans[i] ++;
		}
	if(ans[3] == -1) ans[3] = (a[2].Y > 0);
	if(ans[2] == -1) ans[2] = a[n].Y / (ans[3] + 1) - 1;
	rep(i, 3, n - 2)
	{
		a[i].Y -= (ans[i - 1] + 1) * (ans[i - 2] + 1);
		if(ans[i + 1] == -1) if(a[i].Y > 0) ans[i + 1] = 1; else ans[i + 1] = 0;
	}
	ans[n] = (a[n - 1].Y - (ans[n - 2] + 1) * (ans[n - 3] + 1)) / (ans[n - 2] + 1);
	printf("!");
	rep(i, 1, n) printf(" %d", ans[i]); puts("");
	return 0;
}
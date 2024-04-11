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
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 5010;
pair<int, int> a[N];
int vis[N];
vector<int> ans;
int main()
{
	int n = read();
	rep(i, 1, n)
	{
		int x = read();
		int y = read();
		a[i] = mp(x, y);
	}
	int now = 1;
	ans.pb(1);
	rep(i, 2, n)
	{
		ll D = 0;
		int id;
		rep(j, 2, n)
		{
			if(vis[j] == 1) continue;
			ll dis = 1LL * (a[now].X - a[j].X) * (a[now].X - a[j].X) + 1LL * (a[now].Y - a[j].Y) * (a[now].Y - a[j].Y);
			if(dis > D) D = dis, id = j;
		}
		vis[id] = 1;
		ans.pb(id);
		now = id;
	}
	rep0(i, n) printf("%d ", ans[i]);

	return 0;
}
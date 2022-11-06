#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_Rck
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
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
const int N = 10010;
int a[N];
int pre[N], now[N], v[N];
pair<int, int> ans[N];
int main()
{
	int n = read();
	int k = read();
	rep(i, 1, n * k) a[i] = read();
	int nw = 1;
	
	rep(i, 1, n * k)
	{
		int col = a[i];
		pre[i] = now[col];
		now[col] = i;
		if(ans[col].X == 0 && pre[i])
		{
			int mx = 0;
			rep(j, pre[i], i) mx = max(v[j], mx);
			if(mx < ceil((double)n / (k - 1)))
			{
				ans[col] = mp(pre[i], i);
				rep(j, pre[i], i) v[j] ++;
			}
		}
	}
	rep(i, 1, n) printf("%d %d\n", ans[i].X, ans[i].Y);

	return 0;
}
//if(mx <= ceil((double)n / (k - 1)))
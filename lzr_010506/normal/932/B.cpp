#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int sum[1000010][10], l, r, k, g[1000010];
int id(int x)
{
	int ans = 1;
	while(x)
	{
		if(x % 10) ans *= x % 10;
		x /= 10;
	}
	return ans;
}
int main()
{
	rep(i, 1, 9) g[i] = i;
	rep(i, 10, 1000000) g[i] = g[id(i)];
	rep(i, 1, 1000000)
	{
		rep(j, 1, 9) sum[i][j] = sum[i - 1][j];
		sum[i][g[i]] ++;
	}
	int T = read();
	while(T --)
	{
		l = read();
		r = read();
		k = read();
		printf("%d\n", sum[r][k] - sum[l - 1][k]);
	}
	return 0;
}
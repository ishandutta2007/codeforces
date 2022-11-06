#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
#define cmax(u,v) (u)<(v)?(u)=(v):0;
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
const int mod = 1e9 + 7;
int a[50][50], b[50][50], n, m, k, g[50][50];
ll ans;
bool check(int x,int y)
{
	b[x][y] = b[x][y - 1] | b[x - 1][y];
	if(b[x][y] & (1 << a[x][y])) return 0;
	b[x][y] |= (1 << a[x][y]);
	return 1;
}
int p[50];

void dfs(int x, int y ,int cur)
{
	if(x == n + 1)
	{
		memset(p, 0, sizeof(p));
		int A = k, B = 0;
		rep(i, 1, n)
			rep(j, 1, m)
			{
				B = max(B, a[i][j]);
				if(g[i][j])
				{
					if(p[a[i][j]] && p[a[i][j]] != g[i][j]) return;
					else p[a[i][j]] = g[i][j];
				}
			}
		rep(i, 1, k)
			if(p[i])
				rep(j, 1, k)
					if(i != j && p[i] == p[j]) return;
		rep(i, 1, k)
			if(p[i]) A --, B --;
		ll sum = 1;
		for(int i = A; i >= (A - B + 1); i --)
			sum *= i, sum %= mod;
		ans += sum;
		ans %= mod;
		return;
	}
	if(y == m + 1)
	{
		dfs(x + 1, 1, cur);
		return;
	}
	rep(i, 1, cur)
		if(i <= k)
		{
			a[x][y] = i;
			if(check(x, y)) dfs(x, y + 1, max(i + 1, cur));
		}
}
int main()
{
	n = read();
	m = read();
	k = read();
	if(k < n + m - 1)
	{
		cout << 0;
		return 0;
	}
	rep(i, 1, n)
		rep(j, 1, m)
			g[i][j] = read();
	dfs(1, 1, 1);
	cout << ans;
	return 0;
}
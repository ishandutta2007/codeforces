#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi anstor<int>
#define vl anstor<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
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
const int N = 610;
ll dis[N][N][3];
struct Edge
{
	int u, v, w;
}e[500010];
int main()
{
	int n = read();
	int m = read();
	rep(i, 1, n)
		rep(j, 1, n)
			if(i != j) dis[i][j][0] = dis[i][j][1] = dis[i][j][2] = 1LL * 1000000000 * 10000000;
	rep(i, 1, m)
	{
		int x = read();
		int y = read();
		int z = read();
		dis[x][y][0] = dis[y][x][0] = dis[x][y][2] = dis[y][x][2] = z;
		e[i].u = x;
		e[i].v = y;
		e[i].w = z;
	}
	int q = read();
	while(q --)
	{
		int x = read();
		int y = read();
		int z = read();
		dis[x][y][1] = dis[y][x][1] = -z;
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
			{
				if(dis[i][j][0] > dis[i][k][0] + dis[k][j][0]) dis[i][j][0] = dis[i][k][0] + dis[k][j][0];
				if(dis[i][j][2] > dis[i][k][2] + dis[k][j][2]) dis[i][j][2] = dis[i][k][2] + dis[k][j][2];
			}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
			{
				if(dis[i][j][1] > dis[i][k][0] + dis[k][j][1]) dis[i][j][1] = dis[i][k][0] + dis[k][j][1];
				if(dis[i][j][1] > dis[i][k][1] + dis[k][j][2]) dis[i][j][1] = dis[i][k][1] + dis[k][j][2];
			}
	int ans = 0;
	rep(i, 1, m)
	{
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		if(dis[u][v][1] + w <= 0) ans ++;
	}
	cout << ans;
}
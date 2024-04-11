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
const int N = 2e5 + 10;
const int M = 60;
int n, m, dis[N][M];
bool vis[N][M];
vi b[N], c[N];
priority_queue< pair<int, pii> > q;
int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
		rep0(j, 60)
			dis[i][j] = INF;
	rep(i, 1, m)
	{
		int x = read();
		int y = read();
		int z = read();
		b[x].pb(y);
		b[y].pb(x);
		c[x].pb(z);
		c[y].pb(z);
	}
	dis[1][0] = 0;
	q.push(mp(-dis[1][0], mp(1, 0)));
	while(!q.empty())
	{
		int now1 = q.top().Y.X;
		int now2 = q.top().Y.Y;
		q.pop();
		if(vis[now1][now2]) continue;
		vis[now1][now2] = 1;
		rep0(i, sz(b[now1]))
		{
			int to1 = b[now1][i];
			int to2 = c[now1][i];
			if(now2 == 0)
			{
				if(dis[now1][now2] < dis[to1][to2])
				{
					dis[to1][to2] = dis[now1][now2];
					q.push(mp(-dis[to1][to2], mp(to1, to2)));
				}
			}
			else
			{
				if(dis[now1][now2] + (now2 + to2) * (now2 + to2) < dis[to1][0])
				{
					dis[to1][0] = dis[now1][now2] + (now2 + to2) * (now2 + to2);
					q.push(mp(-dis[to1][0], mp(to1, 0)));
				}				
			}
		}
	}
	rep(i, 1, n)
	{
		if(dis[i][0] == INF) printf("-1 ");
		else printf("%d ", dis[i][0]);
	}
	printf("\n");
	return 0;
}
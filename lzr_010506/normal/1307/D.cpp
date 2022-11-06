#include <bits/stdc++.h>
#include <ctime>
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
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
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
const int N = 4e5 + 10;
int n, m, k, a[N], dis1[N], dis2[N];
vector<int> G[N];
bool cmp(int x,int y)
{
	return dis1[x] < dis1[y];
}

void bfs(int st, int* dis)
{
	queue<int> Q;
	Q.push(st);
	rep(i, 1, n) dis[i] = -1;
	dis[st] = 0;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for(auto v : G[x])
			if (dis[v] == -1)
			{
				dis[v] = dis[x] + 1;
				Q.push(v);
			}
	}
}
int main()
{
	n = read();
	m = read();
	k = read();
	rep(i, 1, k) a[i] = read();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		G[u].pb(v);
		G[v].pb(u);
	}
	bfs(1, dis1);
	bfs(n, dis2);
	sort(a + 1, a + 1 + k, cmp);
	rep(i, 1, k - 1)
		if (dis1[a[i]] == dis1[a[i + 1]])
		{
			printf("%d\n",dis1[n]);
			return 0;
		}
	int ans = 0;
	rep(i, 1, k - 1)
		ans = max(ans, dis1[a[i]] + 1 + dis2[a[i + 1]]);
	ans = min(ans, dis1[n]);
	printf("%d\n", ans);
	return 0;
}
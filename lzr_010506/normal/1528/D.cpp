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
int cn[N][N], dis[N];
priority_queue<pii> q;

int main()
{
	int n = read();
	int m = read();
	rep0(i, n)
		rep0(j, n)
			cn[i][j] = 2e9;
	rep0(i, m)
	{
		int a = read();
		int b = read();
		int c = read();
		cn[a][b] = c;
	}
	rep0(i, n)
		rep0(j, 2 * n)
		{
			int mid = j % n;
			int to = (mid + 1) % n;
			cn[i][to] = min(cn[i][to], cn[i][mid] + 1);
		}

	rep0(st, n)
	{
		rep0(i, n) dis[i] = 2e9;
		dis[st] = 0;
		q.push(mp(0, st));
		while(!q.empty())
		{
			int now = q.top().Y;
			int d = -q.top().X;
			q.pop();
			if(dis[now] < d) continue;
			int to = d % n;
			rep0(i, n)
			{
				if(dis[to] > d + cn[now][i])
				{
					dis[to] = d + cn[now][i];
					q.push(mp(-dis[to], to));
				}
				to = (to + 1) % n;
			} 
		}
		rep0(i, n) printf("%d ", dis[i]);
		puts("");
	}
}
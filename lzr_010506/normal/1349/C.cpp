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
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define per0(i, n) for (int i = (n)-1; i >= 0; i--)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
#define vi vector<int>
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

const int N = 1111;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, Dis[N][N];
char ch[N][N];
queue<pii> q;

void update(int x, int y, int d)
{
	if(x == 0 || y == 0 || x > n || y > m) return;
	if(Dis[x][y] > d)
	{
		Dis[x][y] = d;
		q.push(mp(x, y));
	}
}

int t;
int main()
{
	n = read();
	m = read();
	t = read();
	rep(i, 1, n) scanf("%s", ch[i] + 1);
	
	memset(Dis, INF, sizeof(Dis));
	rep(i, 1, n)
		rep(j, 1, m)
		{
			bool flag = 0;
			rep0(k, 4)
				if(ch[i + dx[k]][j + dy[k]] == ch[i][j]) flag = 1;
			if(flag)
			{
				q.push(mp(i, j));
				Dis[i][j] = 0;
			}
		}
	while(!q.empty())
	{
		int x = q.front().X, y = q.front().Y;
		q.pop();
		rep0(k, 4)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			if(xx == 0 || yy == 0 || xx > n || yy > m) continue;
			if(Dis[xx][yy] > Dis[x][y] + 1)
			{
				Dis[xx][yy] = Dis[x][y] + 1;
				q.push(mp(xx, yy));
			}
		}
	}
	rep(i, 1, t)
	{
		int x = read();
		int y = read();
		ll p = read1();
		if(Dis[x][y] != INF && p >= Dis[x][y]) printf("%d\n", (ch[x][y] - '0') ^ ((p - Dis[x][y]) & 1));
		else printf("%d\n", ch[x][y] - '0');
	}
	return 0;
}
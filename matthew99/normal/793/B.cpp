#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int maxn = 1010;

int n, m;

int Min[maxn + 5][maxn + 5][4];

char s[maxn + 5][maxn + 5];

struct data
{
	int x, y, t;

	data() { }
	data(int _x, int _y, int _t): x(_x), y(_y), t(_t) { }

};

bool vis[maxn + 5][maxn + 5][4];

queue<data> q;

void extend(int x, int y, int t)
{
	vis[x][y][t] = 0;
	REP(i, 0, 4)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 0 || u >= n || v < 0 || v >= m) continue;
		if (s[u][v] == '*') continue;
		if (chkmin(Min[u][v][i], Min[x][y][t] + (i != t))) 
		{
			if (!vis[u][v][i]) q.push(data(u, v, i)), vis[u][v][i] = 1;
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(Min, oo, sizeof Min);
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", s[i]);
	REP(i, 0, n) REP(j, 0, m) if (s[i][j] == 'S')
	{
		REP(k, 0, 4) 
		{
			Min[i][j][k] = 0;
			vis[i][j][k] = 1;
			q.push(data(i, j, k));
		}
	}
	while (!q.empty())
	{
		auto x = q.front(); q.pop();
		extend(x.x, x.y, x.t);
	}
	REP(i, 0, n) REP(j, 0, m) if (s[i][j] == 'T')
	{
		REP(k, 0, 4) if (Min[i][j][k] <= 2)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
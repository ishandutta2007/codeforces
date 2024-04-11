#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <vector>
#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxn = 2000;

pair<pair<int, int>, pair<int, int> > q[maxn + 5];
int n;

int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int id[256];

bool print[maxn + 5][maxn + 5], vis[maxn + 5][maxn + 5];

LL ans = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int curx = 0, cury = 0;
	id[int('L')] = 0;
	id[int('R')] = 1;
	id[int('U')] = 2;
	id[int('D')] = 3;
	vector<int> X, Y;
	X.pb(curx), Y.pb(cury);
	X.pb(curx + 1), Y.pb(cury + 1);
	REP(i, 0, n)
	{
		char s[3];
		static int x;
		scanf("%s%d", s, &x);
		int tmp = id[(int)s[0]];
		int lstx = curx, lsty = cury;
		curx = lstx + walk[tmp][0] * x, cury = lsty + walk[tmp][1] * x;
		q[i] = mp(mp(lstx, lsty), mp(curx, cury));
		X.pb(curx), Y.pb(cury);
		X.pb(curx + 1), Y.pb(cury + 1);
	}
	sort(ALL(X));
	sort(ALL(Y));
	X.resize(unique(ALL(X)) - X.begin());
	Y.resize(unique(ALL(Y)) - Y.begin());
	REP(i, 0, n)
	{
		q[i].x.x = lower_bound(ALL(X), q[i].x.x) - X.begin();
		q[i].y.x = lower_bound(ALL(X), q[i].y.x) - X.begin();
		q[i].x.y = lower_bound(ALL(Y), q[i].x.y) - Y.begin();
		q[i].y.y = lower_bound(ALL(Y), q[i].y.y) - Y.begin();
		REP(j, min(q[i].x.x, q[i].y.x), max(q[i].x.x, q[i].y.x) + 1)
			REP(k, min(q[i].x.y, q[i].y.y), max(q[i].x.y, q[i].y.y) + 1)
				print[j][k] = 1;
	}
	static pair<int, int> q[maxn * maxn + 5];
	int nn = SZ(X), mm = SZ(Y);
	REP(i, 0, nn)
		REP(j, 0, mm)
		{
			if (print[i][j]) continue;
			if (vis[i][j]) continue;
			int tot = 0;
			q[tot++] = mp(i, j);
			bool flag = 0;
			for (int k = 0; k < tot; ++k)
			{
				const pair<int, int> &x = q[k];
				if (!x.x || x.x == nn - 1 || !x.y || x.y == mm - 1) flag = 1;
				REP(l, 0, 4)
				{
					pair<int, int> y = mp(x.x + walk[l][0], x.y + walk[l][1]);
					if (y.x < 0 || y.x >= nn || y.y < 0 || y.y >= mm) continue;
					if (print[y.x][y.y]) continue;
					if (vis[y.x][y.y]) continue;
					vis[y.x][y.y] = 1;
					q[tot++] = y;
				}
			}
			if (flag) continue;
			REP(i, 0, tot) print[q[i].x][q[i].y] = 1;
		}
	ans = 0;
	REP(i, 0, nn - 1)
		REP(j, 0, mm - 1)
			if (print[i][j]) 
				ans += (LL)(X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
	cout << ans << endl;
	return 0;
}
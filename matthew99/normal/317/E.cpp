#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define EXIT(...) printf(__VA_ARGS__), exit(0)

using namespace std;

const int oo = 0x3f3f3f3f;

const int max0 = 1e7;

const int maxm = 400;
const int maxabs = 101;
const int max1 = 1e3;

bool a[(maxabs << 1) + 5][(maxabs << 1) + 5] = {{0}};
int pre[(max1 << 1) + 5][(max1 << 1) + 5] = {{0}};

int n, ax, ay, bx, by;

int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char cr[4] = {'U', 'D', 'R', 'L'};

bool go(const int &x)
{
	putchar(cr[x]);
	ax += walk[x][0], ay += walk[x][1];
	int ux = bx + walk[x][0], uy = by + walk[x][1];
	if (ux >= 0 && ux <= maxabs << 1 && uy >= 0 && uy <= maxabs << 1 && a[ux][uy]) return 0;
	bx = ux, by = uy;
	return 1;
}

void bfs(const int &ax, const int &ay)
{
	static pair<int, int> q[max0 + 5];
	memset(pre, -1, sizeof pre);
	pre[ax + max1][ay + max1] = 4;
	int tot = 0;
	q[tot++] = mp(ax, ay);
	for (int i = 0; i != tot; ++i)
	{
		const pair<int, int> &x = q[i];
		REP(j, 0, 4)
		{
			int ux = x.x + walk[j][0], uy = x.y + walk[j][1];
			if (ux < -max1 || uy < -max1 || ux >= max1 << 1 || uy >= max1 << 1 || pre[ux + max1][uy + max1] != -1) continue;
			if (ux >= 0 && ux <= maxabs << 1 && uy >= 0 && uy <= maxabs << 1 && a[ux][uy]) continue;
			pre[ux + max1][uy + max1] = j;
			q[tot++] = mp(ux, uy);
		}
	}
}

void trace_path(const int &x, const int &y, const int &bx, const int &by, const bool &flag = 0)
{	
	static int qq[max0 + 5];
	int ux = x, uy = y;
	int tot = 0;
	while (ux != bx || uy != by)
	{
		int tmp = pre[ux + max1][uy + max1];
		qq[tot++] = tmp;
		ux -= walk[tmp][0], uy -= walk[tmp][1];
	}
	reverse(qq, qq + tot);
	for (int i = 0; i != tot; ++i)
	{
		if (go(qq[i]) && flag) qq[tot++] = qq[i];
		if (ax == ::bx && ay == ::by) break;
	}
}

void solve_inf()
{
	memset(pre, -1, sizeof pre);
	if (ay > by)
	{
		swap(cr[0], cr[1]);
		REP(i, 0, maxabs)
			FOR(j, 0, maxabs << 1)
				swap(a[j][i], a[j][(maxabs << 1) - i]);
		ay = (maxabs << 1) - ay, by = (maxabs << 1) - by;
	}
	if (ax > bx)
	{
		swap(cr[2], cr[3]);
		REP(i, 0, maxabs)
			FOR(j, 0, maxabs << 1)
				swap(a[i][j], a[(maxabs << 1) - i][j]);
		ax = (maxabs << 1) - ax, bx = (maxabs << 1) - bx;
	}
	bfs(ax, ay), trace_path(0, 0, ax, ay);
	REP(i, 0, maxabs * 3) go(1);
	bfs(bx, by), trace_path(0, 0, bx, by);
	pair<int, int> yyt = mp(oo, oo);
	FOR(i, 0, maxabs << 1)
		FOR(j, 0, maxabs << 1)
			if (a[i][j]) yyt = min(yyt, mp(j, i));
	swap(yyt.x, yyt.y);
	while (bx != yyt.x) go(2);
	while (ay != by || by != yyt.y - 1) go(0);
	go(3), go(0);
	while (ax != bx) go(2);
	exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &ax, &ay, &bx, &by, &n), ax += maxabs, ay += maxabs, bx += maxabs, by += maxabs;
	if (!n) EXIT("-1\n");
	REP(i, 0, n)
	{
		static int x, y;
		scanf("%d%d", &x, &y);
		a[x + maxabs][y + maxabs] = 1;
	}
	bfs(ax, ay);
	if (pre[bx + max1][by + max1] == -1) EXIT("-1\n");
	if (pre[max1][max1] != -1) solve_inf();
	trace_path(bx, by, ax, ay, 1);
	return 0;
}
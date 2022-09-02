#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <stack>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define x first
#define y second

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 3000;

int n, m, nq;
int fa[(maxn << 1) * maxn + 5];
int rank[(maxn << 1) * maxn + 5] = {0};

inline int get_id(const int &x, const int &y)
{
	return x * (m << 1) + y;
}

int get(int x)
{
	static int tmp[(maxn << 1) * maxn + 5];
	int top = 0;
	while (fa[x] != x) tmp[top++] = x, x = fa[x];
	while (top) fa[tmp[--top]] = x;
	return x;
}

bool same(const int &x0, const int &y0, const int &x1, const int &y1)
{
	return get(get_id(x0, y0)) == get(get_id(x1, y1));
}

void Union(const int &x0, const int &y0, const int &x1, const int &y1)
{
	int a = get(get_id(x0, y0)), b = get(get_id(x1, y1));
	if (a == b) return;
	if (rank[a] < rank[b]) swap(a, b);
	fa[b] = a;
	rank[a] += rank[a] == rank[b];
}

bool del[maxn + 5][(maxn << 1) + 5];

int walk[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &nq);
	REP(i, 0, n * m << 1) fa[i] = i;
	if (m == 1) EXIT("0\n");
	int cnt = 0;
	REP(i, 0, nq)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		if (del[x][y]) continue;
		REP(i, 0, 8)
		{
			int ux = x + walk[i][0], uy = y + walk[i][1];
			if (ux < 0 || ux >= n) continue;
			if (uy < 0) uy += m << 1;
			if (uy >= m << 1) uy -= m << 1;
			if (!del[ux][uy]) continue;
			REP(j, 0, 8)
			{
				int vx = x + walk[j][0], vy = y + m + walk[j][1];
				if (vx < 0 || vx >= n) continue;
				if (vy < 0) vy += m << 1;
				if (vy >= m << 1) vy -= m << 1;
				if (!del[vx][vy]) continue;
				if (same(ux, uy, vx, vy)) goto yyt;
			}
		}
		del[x][y] = del[x][y + m] = 1;
		++cnt;
		REP(i, 0, 8)
		{
			int ux = x + walk[i][0], uy = y + walk[i][1];
			if (ux < 0 || ux >= n) continue;
			if (uy < 0) uy += m << 1;
			if (uy >= m << 1) uy -= m << 1;
			if (del[ux][uy]) Union(x, y, ux, uy);
			int vx = x + walk[i][0], vy = y + m + walk[i][1];
			if (vx < 0 || vx >= n) continue;
			if (vy < 0) vy += m << 1;
			if (vy >= m << 1) vy -= m << 1;
			if (del[vx][vy]) Union(x, y + m, vx, vy);
		}
yyt:;
	}
	printf("%d\n", cnt);
	return 0;
}
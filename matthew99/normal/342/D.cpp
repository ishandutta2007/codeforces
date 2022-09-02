#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxn = 10000, max0 = 1000;

const int Mod = 1e9 + 7;

pair<int, int> f[max0 + 5];

int fn = 0;

int g[maxn + 5][3];

int n;

int xx, yy;

void init()
{
	scanf("%d", &n);
	REP(i, 0, 3)
	{
		scanf("\n");
		REP(j, 0, n)
		{
			static char c;
			scanf("%c", &c);
			g[j][i] = c == 'X' ? 1 : 0;
			if (c == 'O') g[j][i] = 1, xx = j, yy = i;
		}
	}
}

int get(int S, const int &x, const int &y, const int &kind)
{
	if (g[x][y] && kind > 0) return -1;
	if (!g[x][y] && !kind) return -1;
	bool deg[3];
	REP(i, 0, 3) deg[i] = S & 1, S >>= 1;
	if (kind == -1)
	{
		REP(i, 0, 3) if (deg[i]) return 0;
		return 1;
	}
	if (kind == 1)
	{
		if (!deg[y]) return -1;
		deg[y] = 0;
	}
	else if (deg[y]) return -1;
	if (kind == 2)
	{
		if (!y || !deg[y - 1]) return -1;
		deg[y - 1] = deg[y] = 0;
	}
	if (kind == 3) deg[y] = 1;
	S = 0;
	for (int i = 2; i >= 0; --i) (S <<= 1) |= deg[i];
	return S;
}

int work()
{
	int ret = 0;
	fn = 0;
	f[fn++] = mp(0, 1);
	REP(i, 0, n)
	{
		REP(j, 0, 3)
		{
			static pair<int, int> ff[max0 + 5];
			int ffn = 0;
			REP(k, 0, fn)
			{
				REP(l, 0, 4)
				{
					int tmp = get(f[k].x, i, j, l);
					if (tmp == -1) continue;
					ff[ffn++] = mp(tmp, f[k].y);
				}
			}
			sort(ff, ff + ffn);
			fn = 0;
			for (int i = 0; i < ffn; )
			{
				f[fn].x = ff[i].x, f[fn].y = 0;
				while (i < ffn && ff[i].x == f[fn].x) (f[fn].y += ff[i++].y) %= Mod;
				++fn;
			}
		}
	}
	REP(k, 0, fn)
		if (get(f[k].x, n, -1, -1)) (ret += f[k].y) %= Mod;
	return ret;
}

int walk[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	int jcvb = 0;
	static int gg[maxn + 5][3];
	memcpy(gg, g, sizeof gg);
	REP(i, 1, 16)
	{
		int cnt = -1;
		memcpy(g, gg, sizeof g);
		REP(j, 0, 4)
		{
			if ((i >> j) & 1)
			{
				cnt *= -1;
				REP(k, 1, 3)
				{
					int x = xx + walk[j][0] * k, y = yy + walk[j][1] * k;
					if (x < 0 || y < 0 || x >= n || y >= 3 || g[x][y]) goto lyc;
					g[x][y] = 1;
				}
			}
		}
		(jcvb += cnt * work() % Mod) %= Mod;
lyc:;
	}
	(jcvb += Mod) %= Mod;
	printf("%d\n", jcvb);
	return 0;
}
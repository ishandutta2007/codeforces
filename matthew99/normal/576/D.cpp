#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 150, maxm = 150, max0 = 30;

bitset<maxn + 5> f[maxn + 5], f0[maxn + 5]; 
bitset<maxn + 5> g[maxn + 5];
int dis[maxn + 5][maxn + 5];

int ans = -1;

int n, m;
pair<int, pair<int, int> > ed[maxm + 5];

void mul(bitset<maxn + 5> *f0, bitset<maxn + 5> *f1)
{
	bitset<maxn + 5> ans[maxn + 5];
	REP(i, 0, n)
		REP(j, 0, n)
			if (f0[i][j]) ans[i] |= f1[j];
	REP(i, 0, n) f0[i] = ans[i];
}

void pm(bitset<maxn + 5> *b, int e)
{
	bitset<maxn + 5> t[maxn + 5];
	REP(i, 0, n) t[i][i] = 1;
	for ( ; e; e >>= 1, mul(b, b)) if (e & 1) mul(t, b);
	REP(i, 0, n) b[i] = t[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	memset(dis, oo, sizeof dis);
	REP(i, 0, n) dis[i][i] = 0, g[i][i] = 1;
	REP(i, 0, m)
	{
		scanf("%d%d%d", &ed[i].y.x, &ed[i].y.y, &ed[i].x);
		--ed[i].y.x;
		--ed[i].y.y;
	}
	sort(ed, ed + m);
	int lst = 0;
	REP(i, 0, m)
	{
		int x = ed[i].y.x, y = ed[i].y.y, d = ed[i].x;
		REP(j, 0, n)
			REP(k, 0, n)
				chkmin(dis[j][k], dis[j][x] + 1 + dis[y][k]);
		REP(i, 0, n) f0[i] = f[i];
		pm(f0, d - lst);
		mul(g, f0);
		REP(j, 0, n)
			if (g[0][j])
			{
				if (dis[j][n - 1] < oo)
				{
					if (ans == -1) ans = d + dis[j][n - 1];
					else chkmin(ans, d + dis[j][n - 1]);
				}
			}
		lst = d;
		f[x][y] = 1;
	}
	if (ans == -1) printf("Impossible\n");
	else printf("%d\n", ans);
	return 0;
}
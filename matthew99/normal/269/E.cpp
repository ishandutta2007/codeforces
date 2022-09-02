#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, max0 = 10000000;

int n, m;
pair<int, int> link[4][maxn + 5];
int cnt[4][4];
int id[256];
int ans[2][maxn + 5];
bool has[2];

int len[4];

int Mod0, Mod1, lucky;

pair<pair<int, int>, vector<pair<int, int> > > yyt[maxn + 5];
int pos0[maxn + 5];
int pig = 0;
pair<pair<int, int>, vector<pair<int, int> > > lyc[maxn + 5];
int pos1[maxn + 5];
int orz = 0;

bool vis[4][maxn + 5] = {{0}};

int find_prime(const int &x, const int &y)
{
pmxm:;
	static int tmp;
	tmp = x + ((LL)rand() * (RAND_MAX + 1) + rand()) % y;
	for (int i = 2; i * i <= tmp; ++i)
		if (!(tmp % i)) goto pmxm;
	return tmp;	
}

bool cmp0(const int &x, const int &y)
{
	return yyt[x].x < yyt[y].x;
}

bool cmp1(const int &x, const int &y)
{
	return lyc[x].x < lyc[y].x;
}

int main()
{
	srand(time(NULL));
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Mod0 = find_prime(1e9, 1e8), Mod1 = find_prime(Mod0 + 1, 1e8), lucky = find_prime(Mod1 + 1, 1e8);
	scanf("%d%d", &n, &m);
	id['L'] = 0, id['B'] = 1, id['R'] = 2, id['T'] = 3;
	len[0] = len[2] = n, len[1] = len[3] = m;
	REP(i, 0, n + m)
	{
		char from[2], to[2];
		scanf("%s%s", from, to);
		int x = id[(int)from[0]], y = id[(int)to[0]];
		int a, b;
		scanf("%d%d", &a, &b);
		if (x >= 2) a = len[x] - a;
		else --a;
		if (y >= 2) b = len[y] - b;
		else --b;
		link[x][a] = mp(y, b);
		link[y][b] = mp(x, a);
		if (((x - y) & 3) == 2) has[x & 1] = 1;
	}
	if (has[0] && has[1]) EXIT("No solution\n");
	REP(i, 0, 4)
		REP(j, 0, len[i]) 
			++cnt[i][(link[i][j].x - i) & 3];
	static pair<int, int> all[max0 + 5];
	REP(i, 0, 4)
		REP(j, 0, len[i])
			if (!vis[i][j])
			{
				int u = i, v = j;
				int tot = 0;
				do
				{
					vis[u][v] = 1;
					all[tot++] = mp(u, v);
					pair<int, int> tmp = link[u][v];
					vis[tmp.x][tmp.y] = 1;
					all[tot++] = mp(tmp.x, tmp.y);
					u = (tmp.x + 2) & 3, v = len[u] - tmp.y - 1;
				}while (u != i || v != j);
				int oril = tot;
				REP(i, 0, tot) all[tot++] = all[i];
				all[tot++] = mp(oo, 0);
				for (int i = tot - 1; i >= 0; --i) all[tot++] = all[i];
				all[tot++] = mp(oo, 0);
				const int &l = tot;
				int i = 0, j = 1, k = 0;  
				while (i < l && j < l && k < l) 
				{
					int t = (all[(i + k) >= l ? i + k - l : i + k].x) - (all[(j + k) >= l ? j + k - l : j + k].x);
					if(!t) ++k;
					else
					{
						if (t > 0) i = max(j + 1, i + k + 1);
						else j = max(i + 1, j + k + 1);
						k = 0;
					}
				}
				int t = i < j ? i : j;  
				LL t0 = 0, t1 = 0;
				REP(i, 0, oril)
				{
					yyt[pig].y.pb(all[t]);
					((t0 *= lucky) += all[t].x) %= Mod0;
					((t1 *= lucky) += all[t].x) %= Mod1;
					if (++t >= tot) t -= tot;
				}
				yyt[pig].x = mp(t0, t1);
				++pig;
			}
	memset(vis, 0, sizeof vis);
	REP(i, 0, 4)
		REP(j, 0, len[i])
			if (!vis[i][j])
			{
				int u = i, v = j;
				int tot = 0;
				do
				{
					vis[u][v] = 1;
					all[tot++] = mp(u, v);
					static pair<int, int> tmp;
					if (v < cnt[u][3]) tmp.x = (u - 1) & 3, tmp.y = len[tmp.x] - v - 1;
					else if (v < cnt[u][3] + cnt[u][2]) 
					{
						tmp.x = (u - 2) & 3;
						tmp.y = len[tmp.x] - (v - cnt[u][3] + cnt[tmp.x][1]) - 1;
					}
					else tmp.x = (u + 1) & 3, tmp.y = len[u] - v - 1;
					vis[tmp.x][tmp.y] = 1;
					all[tot++] = mp(tmp.x, tmp.y);
					u = (tmp.x + 2) & 3, v = len[u] - tmp.y - 1;
				}while (u != i || v != j);
				int oril = tot;
				REP(i, 0, tot) all[tot++] = all[i];
				all[tot++] = mp(oo, 0);
				for (int i = tot - 1; i >= 0; --i) all[tot++] = all[i];
				all[tot++] = mp(oo, 0);
				const int &l = tot;
				int i = 0, j = 1, k = 0;  
				while (i < l && j < l && k < l) 
				{
					int t = (all[(i + k) >= l ? i + k - l : i + k].x) - (all[(j + k) >= l ? j + k - l : j + k].x);
					if(!t) ++k;
					else
					{
						if (t > 0) i = max(j + 1, i + k + 1);
						else j = max(i + 1, j + k + 1);
						k = 0;
					}
				}
				int t = i < j ? i : j;  
				LL t0 = 0, t1 = 0;
				REP(i, 0, oril)
				{
					lyc[orz].y.pb(all[t]);
					((t0 *= lucky) += all[t].x) %= Mod0;
					((t1 *= lucky) += all[t].x) %= Mod1;
					if (++t >= tot) t -= tot;
				}
				lyc[orz].x = mp(t0, t1);
				++orz;
			}
	if (orz != pig) EXIT("No solution\n");
	REP(i, 0, pig) pos0[i] = pos1[i] = i;
	sort(pos0, pos0 + pig, cmp0);
	sort(pos1, pos1 + orz, cmp1);
	REP(i, 0, pig)
	{
		if (yyt[pos0[i]].x != lyc[pos1[i]].x || SZ(yyt[pos0[i]].y) != SZ(lyc[pos1[i]].y)) EXIT("No solution\n");
		REP(j, 0, SZ(yyt[pos0[i]].y))
		{
			int u = yyt[pos0[i]].y[j].x, v = yyt[pos0[i]].y[j].y;
			int u0 = lyc[pos1[i]].y[j].x, v0 = lyc[pos1[i]].y[j].y;
			ans[u0 & 1][u0 >= 2 ? len[u0] - v0 - 1 : v0] = u >= 2 ? len[u] - v - 1 : v;
		}
	}
	REP(i, 0, 2)
	{
		REP(j, 0, len[i])
			printf("%d ", ans[i][j] + 1);
		printf("\n");
	}
	return 0;
}
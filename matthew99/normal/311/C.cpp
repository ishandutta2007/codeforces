#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>
#include <functional>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, maxm = 100000, maxk = 10000;

int n, m, K;
LL pos[maxn + 5];
int val[maxn + 5];
vector<int> all[maxm + 5];
pair<int, LL> yyt[maxm + 5];
bool be[maxn + 5];
bool used[maxn + 5];

int gcd(int x, int y) { while (y) y ^= x ^= y ^= x %= y; return x; }

vector<pair<int, LL> > e[maxk + 5];
LL dis[maxk + 5];

void dij(const int &S)
{
	static const int max0 = 1e6;
	static pair<LL, int> q[max0 + 5];
	static bool vis[maxk + 5];
	memset(vis, 0, sizeof vis);
	int tot = 0;
	memset(dis, oo, sizeof dis);
	dis[S] = 0;
	q[tot++] = mp(dis[S], S);
	while (tot)
	{
		int x = q[0].y;
		pop_heap(q, q + (tot--), greater<pair<LL, int> >());
		if (vis[x]) continue;
		vis[x] = 1;
		REP(i, 0, SZ(e[x]))
		{
			const int &y = e[x][i].x;
			const LL &z = e[x][i].y;
			if (dis[y] > dis[x] + z ? dis[y] = dis[x] + z, 1 : 0)
			{
				q[tot++] = mp(dis[y], y);
				push_heap(q, q + tot, greater<pair<LL, int> >());
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%*I64d%d%d%d", &n, &m, &K);
	REP(i, 0, n)
		scanf("%I64d%d", pos + i, val + i), --pos[i];
	REP(i, 0, m)
	{
		static int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%I64d", &yyt[i].y);
			yyt[i].x = -2;
		}
		else if (ty == 2) scanf("%d%I64d", &yyt[i].x, &yyt[i].y), --yyt[i].x;
		else yyt[i].x = -1;
	}
	static pair<int, int> q[maxn + maxm + 5];
	int tot = 0;
	REP(i, 0, n) 
		if (!(pos[i] % K)) be[i] = 1, q[tot++] = mp(val[i], -i);
	make_heap(q, q + tot);
	REP(i, 0, m)
	{
		if (yyt[i].x == -1)
		{
			while (tot)
			{
				if (!used[-q[0].y] && val[-q[0].y] == q[0].x) break;
				pop_heap(q, q + (tot--));
			}
			if (!tot) printf("0\n");
			else used[-q[0].y] = 1, printf("%d\n", q[0].x), pop_heap(q, q + (tot--));
		}
		else if (yyt[i].x >= 0) 
		{
			val[yyt[i].x] -= yyt[i].y;
			if (be[yyt[i].x]) q[tot++] = mp(val[yyt[i].x], -yyt[i].x), push_heap(q, q + tot);
		}
		else
		{
			REP(j, 0, K) e[j].pb(mp((j + yyt[i].y) % K, (j + yyt[i].y) / K));
			dij(0);
			REP(i, 0, n)
				if (!be[i])
				{
					LL k = pos[i] / K;
					int b = pos[i] % K;
					if (dis[b] <= k) be[i] = 1, q[tot++] = mp(val[i], -i), push_heap(q, q + tot);
				}
		}
	}
	return 0;
}
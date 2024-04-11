#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <map>
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define SZ(x) (int((x).size()))

using namespace std;

template<typename T0, typename T1> bool chkmin(T0 &a, const T1 &b) { return a > b ? a = b, 1 : 0; }
template<typename T0, typename T1> bool chkmax(T0 &a, const T1 &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f, Max_val = 314000000;
const int maxn = 100000, maxm = 100000;

int deg[maxn + 5];

pair<pair<int, int>, int> all[maxm + 5];
int tmp[maxm + 5] = {0};

vector<int> yyt[maxn + 5];

bool vis[maxn + 5] = {0};
int Min[maxn + 5];
int Max[maxn + 5];

vector<int> zzj[maxm + 5];
vector<int> owaski[maxn + 5]; //zaiyiqi

int find(const int &x)
{
	if (vis[x]) return -2;
	if (Max[x]) return Max[x];
	vis[x] = 1;
	Max[x] = -2;
	REP(i, 0, SZ(owaski[x]))
	{
		const int &y = owaski[x][i];
		int tmp = ::tmp[y];
		REP(j, 0, SZ(zzj[y]))
		{
			const int &k = zzj[y][j];
			if (Max[k] == -1) goto yyt;
		}
		REP(j, 0, SZ(zzj[y]))
		{
			const int &k = zzj[y][j];
			int tmp0 = find(k);
			if (tmp0 == -1) goto yyt;
			else if (tmp0 == -2) tmp = -2;
			else if (tmp != -2) chkmin(tmp += tmp0, Max_val);
		}
		if (tmp == -2)
		{
			Max[x] = -2;
			vis[x] = 0;
			return Max[x];
		}
		Max[x] = max(Max[x], tmp);
yyt:;
	}
	vis[x] = 0;
	return Max[x];
}

int m, n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(Min, oo, sizeof Min);
	scanf("%d%d", &m, &n);
	REP(i, 0, m)
	{
		scanf("%d", &all[i].x.x), --all[i].x.x;
		static int nn;
		scanf("%d", &nn);
		all[i].x.y = tmp[i] = 0;
		owaski[all[i].x.x].pb(i);
		REP(j, 0, nn)
		{
			static int x;
			scanf("%d", &x);
			if (x == -1) ++all[i].x.y, ++tmp[i];
			else --x, ++all[i].y, yyt[x].pb(i), zzj[i].pb(x);
		}
	}
	REP(i, 0, m)
		if (!all[i].y) chkmin(Min[all[i].x.x], all[i].x.y);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	REP(i, 0, n)
		if (Min[i] < oo) q.push(mp(Min[i], i));
	while (!q.empty())
	{
		int x = q.top().y; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		REP(i, 0, SZ(yyt[x]))
		{
			const int &y = yyt[x][i];
			all[y].x.y = min(all[y].x.y + Min[x], Max_val);
			if (!--all[y].y && chkmin(Min[all[y].x.x], all[y].x.y)) q.push(mp(Min[all[y].x.x], all[y].x.x));
		}
	}
	memset(vis, 0, sizeof vis);
	memset(Max, 0, sizeof Max);
	REP(i, 0, n) if (Min[i] == oo) Min[i] = Max[i] = -1; 
	REP(i, 0, n)
	{
		find(i);
		printf("%d %d\n", Min[i], Max[i]);
	}	
	return 0;
}
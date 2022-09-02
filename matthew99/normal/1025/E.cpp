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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 60, maxm = 60;

int n, m;

pair<int, int> where[maxn + 5];
pair<int, int> goal[maxn + 5];

int id[maxn + 5][maxm + 5];

vector<pair<pair<int, int>, pair<int, int> > > ans;

inline check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n) return 0;
	REP(i, 0, m) if (x == where[i].x && y == where[i].y) return 0;
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		scanf("%d%d", &where[i].x, &where[i].y), --where[i].x, --where[i].y;
	}
	memset(id, -1, sizeof id);
	REP(i, 0, m)
	{
		scanf("%d%d", &goal[i].x, &goal[i].y), --goal[i].x, --goal[i].y;
		id[goal[i].x][goal[i].y] = i;
	}
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	while (1)
	{
		bool find = 0;
		REP(i, 0, m)
		{
			if (check(where[i].x, where[i].y - 1))
			{
				find = 1;
				ans.pb(mp(where[i], mp(where[i].x, where[i].y - 1)));
				--where[i].y;
			}
		}
		if (!find) break;
	}
	while (1)
	{
		bool find = 0;
		REP(i, 0, m)
			if (where[i].x < n - 1)
			{
				if (check(where[i].x + 1, where[i].y))
				{
					find = 1;
					ans.pb(mp(where[i], mp(where[i].x + 1, where[i].y)));
					++where[i].x;
				}
				else if (check(where[i].x, where[i].y + 1))
				{
					find = 1;
					ans.pb(mp(where[i], mp(where[i].x, where[i].y + 1)));
					++where[i].y;
				}
			}
		if (!find) break;
	}
	REP(i, 0, n - 2) REP(j, 0, n) if (~id[i][j])
	{
		int x = id[i][j];
		while (where[x].x > i + 1)
		{
			assert(check(where[x].x - 1, where[x].y));
			ans.pb(mp(where[x], mp(where[x].x - 1, where[x].y)));
			--where[x].x;
		}
		while (where[x].y > j)
		{
			assert(check(where[x].x, where[x].y - 1));
			ans.pb(mp(where[x], mp(where[x].x, where[x].y - 1)));
			--where[x].y;
		}
		while (where[x].y < j)
		{
			assert(check(where[x].x, where[x].y + 1));
			ans.pb(mp(where[x], mp(where[x].x, where[x].y + 1)));
			++where[x].y;
		}
		assert(check(where[x].x - 1, where[x].y));
		ans.pb(mp(where[x], mp(where[x].x - 1, where[x].y)));
		--where[x].x;
	}
	static bool done[maxn + 5];
	memset(done, 0, sizeof done);
	for (int j = n - 1; j >= 0; --j)
	{
		for (int i = n - 1; i >= n - 2; --i)
		{
			if (~id[i][j])
			{
				while (1)
				{
					bool find = 0;
					REP(k, 0, m) if (where[k].x == n - 1 && !done[k])
					{
						if (check(where[k].x, where[k].y - 1))
						{
							find = 1;
							ans.pb(mp(where[k], mp(where[k].x, where[k].y - 1)));
							--where[k].y;
						}
					}
					if (!find) break;
				}
				int x = id[i][j];
				assert(check(where[x].x - 1, where[x].y));
				ans.pb(mp(where[x], mp(where[x].x - 1, where[x].y)));
				--where[x].x;
				while (1)
				{
					bool find = 0;
					REP(k, 0, m) if (where[k].x == n - 1 && !done[k])
					{
						if (check(where[k].x, where[k].y - 1))
						{
							find = 1;
							ans.pb(mp(where[k], mp(where[k].x, where[k].y - 1)));
							--where[k].y;
						}
					}
					if (!find) break;
				}
//				REP(i, 0, m) debug("%d %d		%d %d\n", where[i].x, where[i].y, goal[i].x, goal[i].y);

//				debug("%d %d\n", where[x].x, where[x].y);
				pair<int, int> tmp = mp(goal[x].x, n - 1);
				while (tmp != where[x] && !check(tmp.x, tmp.y)) --tmp.y;
				while (where[x] != tmp)
				{
					if (where[x].x < tmp.x && check(where[x].x + 1, where[x].y))
					{
						ans.pb(mp(where[x], mp(where[x].x + 1, where[x].y)));
						++where[x].x;
					}
					if (where[x].y < tmp.y && check(where[x].x, where[x].y + 1))
					{
						ans.pb(mp(where[x], mp(where[x].x, where[x].y + 1)));
						++where[x].y;
					}
				}
				done[x] = 1;
			}
		}
	}
//	REP(i, 0, m)
//	{
//		debug("%d %d		%d %d\n", where[i].x, where[i].y, goal[i].x, goal[i].y);
//	}
	while (1)
	{
		bool find = 0;
		REP(i, 0, n)
			if (where[i] != goal[i])
			{
				find = 1;
				if (check(where[i].x, where[i].y - 1))
				{
					ans.pb(mp(where[i], mp(where[i].x, where[i].y - 1)));
					--where[i].y;
				}
			}
		if (!find) break;
	}
	printf("%d\n", SZ(ans));
	for (auto u : ans)
		printf("%d %d %d %d\n", u.x.x + 1, u.x.y + 1, u.y.x + 1, u.y.y + 1);
	return 0;
}
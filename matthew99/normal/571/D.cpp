#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 500000;

int bu[maxn + 5], bm[maxn + 5];
vector<int> allu[maxn + 5], allm[maxn + 5];
vector<pair<int, LL> > tunv[maxn + 5];
int tmil[maxn + 5];

int now;
int tme[maxn + 5];
LL val[maxn + 5];

inline void update(const int &x)
{
	int unv = bu[x], mil = bm[x];
	if (tmil[mil] >= tme[x])
	{
		tme[x] = tmil[mil];
		val[x] = 0;
	}
	vector<pair<int, LL> > &c = tunv[unv];
	int tmp = lower_bound(ALL(c), mp(tme[x], 0LL)) - c.begin();
	for (int i = tmp + 1; i <= SZ(c); i += i & -i) val[x] += c[i - 1].y;
	tme[x] = now;
}

inline void merge_unv(int x, int y)
{
	x = bu[x], y = bu[y];
	if (x == y) return;
	if (SZ(allu[x]) < SZ(allu[y])) swap(x, y);
	for (auto it : allu[y])
	{
		update(it);
		bu[it] = x;
		allu[x].pb(it);
	}
	allu[y].clear();
	tunv[y].clear();
}

inline void merge_mil(int x, int y)
{
	x = bm[x], y = bm[y];
	if (x == y) return;
	if (SZ(allm[x]) < SZ(allm[y])) swap(x, y);
	for (auto it : allm[y])
	{
		update(it);
		bm[it] = x;
		allm[x].pb(it);
	}
	allm[y].clear();
}

inline void Move(const int &x) 
{ 
	vector<pair<int, LL> > &c = tunv[bu[x]];
	c.pb(mp(now, 0LL)); 
	for (int i = SZ(c); i > 0; i -= i & -i) c[i - 1].y += SZ(allu[bu[x]]);
}

inline void Raid(const int &x) { tmil[bm[x]] = now; }

inline void query(const int &x) { update(x); printf("%I64d\n", val[x]); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) bu[i] = i, bm[i] = i, allu[i].pb(i), allm[i].pb(i);
	REP(i, 0, m)
	{
		now = i;
		static char op[5];
		static int x, y;
		scanf("%s", op);
		if (op[0] == 'U' || op[0] == 'M')
		{
			scanf("%d%d", &x, &y), --x, --y;
			if (op[0] == 'U') merge_unv(x, y);
			else merge_mil(x, y);
		}
		else
		{
			scanf("%d", &x), --x;
			if (op[0] == 'A') Move(x);
			else if (op[0] == 'Z') Raid(x);
			else query(x);
		}
	}
	return 0;
}
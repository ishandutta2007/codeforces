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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n;
pair<int, int> a[maxn + 5];
map<int, vector<int> > allx;
map<int, vector<int> > ally;

int fa[maxn + 5];
bool cyc[maxn + 5];

set<int> subx[maxn + 5], suby[maxn + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

inline void Union(int x, int y)
{
	x = get(x), y = get(y);
	if (x == y) cyc[x] = 1;
	else fa[x] = y;
}

int cnt[maxn + 5];

int pw[(maxn << 1) + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw[0] = 1;
	REP(i, 0, maxn << 1 | 1) pw[i + 1] = (pw[i] << 1) % Mod;
	scanf("%d", &n);
	REP(i, 0, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		allx[x].pb(i);
		ally[y].pb(i);
		a[i] = mp(x, y);
	}
	REP(i, 0, n) fa[i] = i;
	for (auto u : allx)
	{
		REP(i, 0, SZ(u.y) - 1)
		{
			Union(u.y[i], u.y[i + 1]);
		}
	}
	for (auto u : ally)
	{
		REP(i, 0, SZ(u.y) - 1)
		{
			Union(u.y[i], u.y[i + 1]);
		}
	}
	REP(i, 0, n) 
	{
		++cnt[get(i)], cyc[get(i)] |= cyc[i];
		subx[get(i)].insert(a[i].x);
		suby[get(i)].insert(a[i].y);
	}
	int ans = 1;
	REP(i, 0, n) if (fa[i] == i)
	{
		int tmp = SZ(subx[i]) + SZ(suby[i]);
		if (cyc[i]) ans = (LL)ans * pw[tmp] % Mod;
		else ans = (LL)ans * (pw[tmp] - 1) % Mod;
	}
	printf("%d\n", ans);
	return 0;
}
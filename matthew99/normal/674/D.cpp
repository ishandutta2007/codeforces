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

const int maxn = 100000, maxq = 100000;

int n, qn;
LL t[maxn + 5], a[maxn + 5];

int fa[maxn + 5];
int deg[maxn + 5];
LL per[maxn + 5];
vector<int> chd[maxn + 5];

multiset<LL> all, from[maxn + 5];

bool in_from[maxn + 5], in_all[maxn + 5];

inline void commit(int x)
{
	if (from[x].empty()) return;
	if (in_all[x]) return;
	in_all[x] = 1;
	all.insert(*--from[x].end() + t[x] / deg[x]);
	all.insert(*from[x].begin() + t[x] / deg[x]);
}

inline void remove(int x)
{
	if (from[x].empty()) return;
	if (!in_all[x]) return;
	in_all[x] = 0;
	all.erase(all.find(*--from[x].end() + t[x] / deg[x]));
	all.erase(all.find(*from[x].begin() + t[x] / deg[x]));
}

inline void add(int x) 
{ 
	if (in_from[x]) return;
	in_from[x] = 1;
	from[fa[x]].insert(a[x]); 
}

inline void del(int x) 
{ 
	if (!in_from[x]) return;
	in_from[x] = 0;
	from[fa[x]].erase(from[fa[x]].find(a[x])); 
}

inline void change_deg(int x, int y)
{
	a[fa[x]] -= per[x];
	a[x] -= t[x] - per[x] * (deg[x] - 1);
	deg[x] += y, per[x] = t[x] / deg[x];
	a[x] += t[x] - per[x] * (deg[x] - 1);
	a[fa[x]] += per[x];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%I64d", t + i);
	REP(i, 0, n) scanf("%d", fa + i), --fa[i], chd[fa[i]].pb(i);
	REP(i, 0, n)
	{
		deg[i] = SZ(chd[i]) + 2;
		per[i] = t[i] / deg[i];
		a[i] += t[i] - per[i] * (deg[i] - 1);
		a[fa[i]] += per[i];
	}
	REP(i, 0, n) add(i);
	REP(i, 0, n) commit(i);
	REP(i, 0, qn)
	{
		int ty, x, y;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d%d", &x, &y), --x, --y;
			if (y == fa[x]) continue;
			int old = fa[x];
			remove(old), remove(fa[old]), remove(fa[fa[old]]);
			remove(y), remove(fa[y]), remove(fa[fa[y]]);
			del(old), del(fa[old]);
			del(y), del(fa[y]);
			del(x);
			fa[x] = y;
			add(x);
			LL tmp = per[x];
			a[old] -= tmp;
			change_deg(old, -1);
			a[y] += tmp;
			change_deg(y, 1);
			add(y), add(fa[y]);
			add(old), add(fa[old]);
			commit(y), commit(fa[y]), commit(fa[fa[y]]);
			commit(old), commit(fa[old]), commit(fa[fa[old]]);
		}
		else if (ty == 2)
		{
			int x;
			scanf("%d", &x), --x;
			printf("%I64d\n", a[x] + per[fa[x]]);
		}
		else if (ty == 3) printf("%I64d %I64d\n", *all.begin(), *--all.end());
	}
	return 0;
}
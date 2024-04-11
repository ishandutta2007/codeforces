#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 100000, max0 = 300, max1 = (maxn + max0 - 1) / max0;

int n, m;
LL a[maxn + 5];

int pre[maxn + 5];

int p[max0 + 5];
LL labelx[max0 + 5], labely[max0 + 5];

vector<int> all[max0 + 5];

LL x[maxn + 5], y[maxn + 5];
int st[max0 + 5], ed[max0 + 5];

bool pkd[maxn + 5];

inline LL cross(const int &a, const int &b, const int &c)
{
	return (x[b] - x[a]) * (y[c] - y[a]) - (x[c] - x[a]) * (y[b] - y[a]);
}

inline LL calc(const int &a, const int &b)
{
	return x[a] * labelx[b] + y[a] + labely[b];
}

inline void update(const int &x) 
{ 
	while (p[x] != -1 && pre[p[x]] != -1 && calc(pre[p[x]], x) > calc(p[x], x)) p[x] = pre[p[x]];
}

inline void build(const int &x)
{
	labelx[x] = labely[x] = 0;
	p[x] = -1;
	for (auto i : all[x])	
		if (!pkd[i])
		{
			while (p[x] != -1 && pre[p[x]] != -1 && cross(pre[p[x]], p[x], i) <= 0) p[x] = pre[p[x]];
			pre[i] = p[x], p[x] = i;
		}
	int u = p[x];
	while (u != -1) u = pre[u];
	update(x);
}

inline void addx(const int &x, const LL &y) { labelx[x] += y; update(x); }
inline void addy(const int &x, const LL &y) { labely[x] += y; }

inline bool cmp(const int &x, const int &y) { return ::x[x] > ::x[y]; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%I64d", a + i);
	LL sum = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		x[i] = a[i];
		y[i] = -a[i] * (i + 1) - sum;
		sum += a[i];
	}
	m = (n + max1 - 1) / max1;
	REP(i, 0, m) 
	{
		st[i] = i * max1, ed[i] = min(n, (i + 1) * max1); 
		all[i].clear();
		REP(j, st[i], ed[i]) all[i].pb(j);
		sort(ALL(all[i]), cmp);
		build(i);
	}
	LL now = 0;
	REP(i, 0, n) now += (i + 1) * a[i];
	LL ans = now;
	REP(i, 0, n)
	{
		LL Max = LLONG_MIN;
		int Maxp = -1, Maxp0 = -1;
		REP(j, 0, m)
			if (p[j] != -1) if (chkmax(Max, calc(p[j], j))) Maxp = p[j], Maxp0 = j;
		now += Max;
		chkmax(ans, now);
		pkd[Maxp] = 1;
		REP(j, st[Maxp0], ed[Maxp0])
			if (!pkd[j])
			{
				y[j] += labely[Maxp0] + labelx[Maxp0] * x[j];
				if (j < Maxp) y[j] += a[Maxp];
				else y[j] += a[j];
			}
		build(Maxp0);
		REP(j, Maxp0 + 1, m) addx(j, 1);
		REP(j, 0, Maxp0) addy(j, a[Maxp]);
	}
	printf("%I64d\n", ans);
    return 0;
}
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

const int oo = 0x3f3f3f3f;

const int maxn = 200100;

int T;

int n;

int place[maxn + 5];

int step;

int cyc;

int ex_gcd(const int &a, const int &b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

map<int, vector<int> > all;

int ans[maxn + 5];

int inv;

inline void work(int x)
{
	vector<int> v;
	set<int> vis;
	for (auto u : all[x])
	{
		if (vis.count(place[u])) ans[u] = 0;
		else vis.insert(place[u]), v.pb(u);
	}
	if (v.empty()) return;
	vector<pair<int, int> > seq;
	for (auto u : v)
	{
		int tmp = (place[u] - x) / cyc;
		int p = (LL)inv * tmp % T;
		(p += T) %= T;
		seq.pb(mp(p, u));
	}
	assert(!seq.empty());
	sort(ALL(seq));
	seq.pb(mp(seq[0].x + T, -1));
	REP(i, 0, SZ(seq) - 1)
	{
		ans[seq[i].y] = seq[i + 1].x - seq[i].x;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &T, &n);
	step = 0;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		(step += x) %= T;
		place[i] = step;
	}
	cyc = __gcd(step, T);
	step /= cyc, T /= cyc;
	int tmp;
	assert(ex_gcd(step, T, inv, tmp) == 1);
	REP(i, 0, n) all[place[i] % cyc].pb(i);
	for (auto u : all) work(u.x);
	REP(i, 0, n) printf("%d ", ans[i]);
	return 0;
}
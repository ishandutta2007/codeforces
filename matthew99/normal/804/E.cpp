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

const int maxn = 1010;

vector<pair<int, int> > sol[10];

inline void work(int n, vector<pair<int, int> > &ret)
{
	int a[maxn + 5];
	vector<pair<int, int> > all;
	vector<int> pos;
	if (n <= 5) REP(i, 0, n) REP(j, 0, i) all.pb(mp(i, j)), pos.pb(SZ(pos));
	else REP(i, 0, 4) REP(j, 4, n) all.pb(mp(i, j)), pos.pb(SZ(pos));
	while (1)
	{
		random_shuffle(ALL(pos));
		REP(i, 0, n) a[i] = i;
		for (auto u : pos) swap(a[all[u].x], a[all[u].y]);
		bool failed = 0;
		REP(i, 0, n) if (a[i] != i) { failed = 1; break; }
		if (!failed)
		{
			ret.clear();
			for (auto u : pos) ret.pb(mp(all[u].x, all[u].y));
			return;
		}
	}
}

int n;

int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 1, 10) if (i % 4 <= 1) work(i, sol[i]);
	scanf("%d", &n);
	REP(i, 0, n) a[i] = i;
	int res = n % 4;
	if (res > 1) puts("NO");
	else
	{
		puts("YES");
		vector<pair<int, int> > ans;
		REP(i, 0, n / 4) REP(j, 0, i)
		{
			int len = 8;
			if (res && i == n / 4 - 1) ++len;
			for (auto u : sol[len])
			{
				u.x += j * 4;
				u.y = u.y - 4 + i * 4;
				ans.pb(mp(u.x, u.y));
			}
		}
		REP(i, 0, n / 4)
		{
			int len = 4;
			if (res && i == n / 4 - 1) ++len;
			for (auto u : sol[len])
			{
				u.x += i * 4, u.y += i * 4;
				ans.pb(mp(u.x, u.y));
			}
		}
		assert(SZ(ans) == n * (n - 1) >> 1);
		for (auto u : ans) swap(a[u.x], a[u.y]);
		REP(i, 0, n) assert(a[i] == i);
		for (auto u : ans) 
		{
			if (u.x > u.y) swap(u.x, u.y);
			printf("%d %d\n", u.x + 1, u.y + 1);
		}
	}
	return 0;
}
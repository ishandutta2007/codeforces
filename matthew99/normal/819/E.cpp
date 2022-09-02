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

const int maxn = 310;

vector<vector<int> > ans;

int cnt[maxn + 5][maxn + 5];

void work(int x)
{
	if (x == 3)
	{
		ans.pb({0, 1, 2});
		ans.pb({0, 1, 2});
		return;
	}
	if (x == 4)
	{
		ans.pb({0, 1, 2});
		ans.pb({0, 1, 3});
		ans.pb({0, 2, 3});
		ans.pb({1, 2, 3});
		return;
	}
	work(x - 2);
	if (x & 1)
	{
		ans.pb({x - 3, x - 2, x - 1});
		ans.pb({x - 3, x - 2, x - 1});
		REP(i, 0, (x - 2) >> 1)
		{
			ans.pb({i << 1, x - 2, i << 1 | 1, x - 1});
			ans.pb({i << 1, x - 2, i << 1 | 1, x - 1});
		}
	}
	else
	{
		ans.pb({0, x - 2, x - 1});
		ans.pb({1, x - 2, x - 1});
		ans.pb({0, x - 2, 1, x - 1});
		REP(i, 1, (x - 2) >> 1)
		{
			ans.pb({i << 1, x - 2, i << 1 | 1, x - 1});
			ans.pb({i << 1, x - 2, i << 1 | 1, x - 1});
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	work(n);
	printf("%d\n", SZ(ans));
	for (auto u : ans)
	{
		printf("%d", SZ(u));
		int lst = u.back();
		for (auto v : u) ++cnt[v][lst], ++cnt[lst][v], lst = v, printf(" %d", v + 1);
		printf("\n");
	}
	REP(i, 0, n) REP(j, 0, i) 
	{
		assert(cnt[i][j] == 2);
	}
	return 0;
}
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

const int maxn = 400100;

int n;

map<int, int> cnt;

int a[maxn + 5];
int sum[maxn + 5];

int ans[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	for (auto u : cnt)
	{
		REP(i, 1, u.y + 1)
			++sum[i];
	}
	REP(i, 1, n + 1) sum[i] += sum[i - 1];
	int best = -1;
	int Max = -1;
	REP(i, 1, n + 1)
	{
		int j = sum[i] / i;
		if (j >= i && chkmax(Max, i * j))
			best = i;
	}
	int r = best, c = sum[r] / best;
	int N = 0;
	for (auto u : cnt)
	{
		if (u.y >= r)
			REP(i, 0, r)
				a[N++] = u.x;
	}
	for (auto u : cnt)
	{
		if (u.y < r)
			REP(i, 0, u.y)
				a[N++] = u.x;
	}
	int cur = 0;
	REP(i, 0, c) REP(j, 0, r)
	{
		int x = j, y = (i + j) % c;
		ans[x * c + y] = a[cur++];
	}
	printf("%d\n%d %d\n", r * c, r, c);
	REP(i, 0, r) 
	{
		REP(j, 0, c)
			printf("%d ", ans[i * c + j]);
		printf("\n");
	}
	return 0;
}
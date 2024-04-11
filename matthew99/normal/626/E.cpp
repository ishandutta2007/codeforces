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

const int maxn = 200000;

int n, a[maxn + 5];

long double sum[maxn + 5];

long double ans = -1;
int x = -1, y = -1, z = -1;

inline long double calc(int j, int i)
{
	if (j > i || n - i + j <= i) return -1;
	return (sum[n] + sum[i] - sum[j] - sum[n - i + j] - (long double)((i - j) << 1) * a[i]) / ((i - j) << 1 | 1);
}

inline void work(int l, int r, int l0, int r0)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	int Maxp = -1;
	long double Max = -1;
	REP(i, l0, r0)
		if (chkmax(Max, calc(i, mid))) Maxp = i;
	assert(Maxp != -1);
	if (chkmax(ans, Max)) x = Maxp, y = mid + 1, z = n - mid + Maxp;
	work(l, mid, l0, Maxp + 1);
	work(mid + 1, r, Maxp, r0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	sum[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] + a[i];
	work(0, n, 0, n);
	printf("%d\n", n - z + y - x);
	REP(i, x, y) printf("%d ", a[i]);
	REP(i, z, n) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
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

const int maxn = 500;

int n;
LL a[maxn + 5][maxn + 5];

inline bool check(const LL &goal)
{
	LL sum = 0;
	REP(i, 0, n)
	{
		sum = 0;
		REP(j, 0, n) sum += a[i][j];
		if (sum != goal) return 0;
		sum = 0;
		REP(j, 0, n) sum += a[j][i];
		if (sum != goal) return 0;
	}
	sum = 0;
	REP(i, 0, n) sum += a[i][i];
	if (sum != goal) return 0;
	sum = 0;
	REP(i, 0, n) sum += a[i][n - i - 1];
	if (sum != goal) return 0;
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	if (n == 1) { puts("1"); return 0; }
	int px = -1, py = -1;
	REP(i, 0, n)
	{
		REP(j, 0, n)
		{
			scanf("%I64d", a[i] + j);
			if (!a[i][j]) px = i, py = j;
		}
	}
	LL sumu = 0, sumv = 0;
	REP(i, 0, n) sumu += a[(px + 1) % n][i], sumv += a[px][i];
	if (sumu - sumv <= 0) puts("-1");
	else
	{
		a[px][py] = sumu - sumv;
		if (!check(sumu)) puts("-1");
		else printf("%I64d\n", a[px][py]);
	}
	return 0;
}
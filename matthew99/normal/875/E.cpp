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

const int maxabs = 1.01e9;

const int max0 = 17;
const int maxn = 100100;

int n, s0, s1;
int a[maxn + 5];

int Max[max0][maxn + 5];
int Min[max0][maxn + 5];

int Log[maxn + 5];

inline void build()
{
	for (int i = 1; i <= maxn; ++i)
	{
		Log[i] = 0;
		int u = i;
		while (u >>= 1) ++Log[i];
	}
	REP(i, 1, max0)
		REP(j, 0, n)
		if (j + (1 << (i - 1)) > n) Max[i][j] = Max[i - 1][j], Min[i][j] = Min[i - 1][j];
		else 
		{
			Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
			Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
		}
}

inline int get_Max(int l, int r)
{
	int tmp = Log[r - l];
	return max(Max[tmp][l], Max[tmp][r - (1 << tmp)]);
}

inline int get_Min(int l, int r)
{
	int tmp = Log[r - l];
	return min(Min[tmp][l], Min[tmp][r - (1 << tmp)]);
}

int nxt[maxn + 5];

bool ok[maxn + 5];

inline bool check(int lim)
{
	for (int i = n - 1; i >= 0; --i)
	{
		int l = i + 1, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (get_Min(i, mid) >= a[i] - lim && get_Max(i, mid) <= a[i] + lim) l = mid;
			else r = mid - 1;
		}
		nxt[i] = l;
	}
	memset(ok, 0, sizeof ok);
	int limi = 0;
	while (limi < n && abs(a[limi] - s1) <= lim) ok[limi++] = 1;
	int j = 0;
	while (j < n && abs(a[j] - s0) <= lim) 
	{
		chkmax(limi, j + 1);
		while (limi < nxt[j]) ok[limi++] = 1;
		++j;
	}
	REP(i, 0, n) if (ok[i])
	{
		chkmax(j, i + 1);
		while (j < nxt[i]) 
		{
			chkmax(limi, j + 1);
			while (limi < nxt[j]) ok[limi++] = 1;
			++j;
		}
	}
	return j == n;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &s0, &s1);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) Min[0][i] = Max[0][i] = a[i];
	build();
	int l = abs(s1 - s0), r = maxabs;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
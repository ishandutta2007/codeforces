

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

const int Mod = 1e9 + 7;

const int maxn = 200100;

int n, qn;
int a[maxn + 5], w[maxn + 5];

int sumaw[maxn + 5];
int sumwi[maxn + 5];
LL sumw[maxn + 5];

inline void add(int x, int y)
{
	for (int i = x + 1; i <= n; i += i & -i)
		(sumaw[i] += (LL)a[x] * y % Mod) %= Mod;
	for (int i = x + 1; i <= n; i += i & -i)
		(sumwi[i] += (LL)x * y % Mod) %= Mod;
	for (int i = x + 1; i <= n; i += i & -i)
		sumw[i] += y;
}

inline int queryaw(int x)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i)
		(ret += sumaw[i]) %= Mod;
	return ret;
}

inline int queryiw(int x)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i)
		(ret += sumwi[i]) %= Mod;
	return ret;
}

inline LL queryw(int x)
{
	LL ret = 0;
	for (int i = x; i > 0; i -= i & -i)
		ret += sumw[i];
	return ret;
}

inline LL get(int x, int y, int s)
{
	int l = x, r = y;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] <= s + mid - x) l = mid + 1;
		else r = mid;
	}
	return 2 * queryw(l) - queryw(x) - queryw(y);
}

inline int calc(int x, int y, int s)
{
	int l = x, r = y;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] <= s + mid - x) l = mid + 1;
		else r = mid;
	}
	LL ans = 0;
	(ans += ((LL)(s - x) * ((queryw(l) - queryw(x)) % Mod) % Mod + queryiw(l) - queryiw(x)) % Mod) %= Mod;
	(ans -= (queryaw(l) - queryaw(x)) % Mod) %= Mod;
	(ans -= ((LL)(s - x) * ((queryw(y) - queryw(l)) % Mod) % Mod + queryiw(y) - queryiw(l)) % Mod) %= Mod;
	(ans += (queryaw(y) - queryaw(l)) % Mod) %= Mod;
	(ans += Mod) %= Mod;
	return ans;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", w + i), add(i, w[i]);
	REP(i, 0, qn)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < 0)
		{
			x = -x;
			--x;
			add(x, y - w[x]);
			w[x] = y;
		}
		else
		{
			--x;
			int l = a[x], r = a[y - 1] - (y - x) + 1;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (get(x, y, mid) < 0) l = mid + 1;
				else r = mid;
			}
			printf("%d\n", calc(x, y, l));
		}
	}
	return 0;
}
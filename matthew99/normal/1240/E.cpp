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

const int maxabs = 1000100;

int n;
int cnt[maxabs + 5];
int pre0[maxabs + 5], pre1[maxabs + 5];

inline pair<int, int> find_best(int y, int lim)
{
	int best0 = -1, best1 = -1;
	for (int i = y; i <= maxabs; i += y)
	{
		if (pre0[i] >= max(lim, i - y))
		{
			if (!~best0 || pre0[i] % y > best0 % y) best1 = best0, best0 = pre0[i];
			else if (pre0[i] % y > best1 % y) best1 = pre0[i];
		}
		if (pre1[i] >= max(lim, i - y)) 
		{
			if (pre1[i] % y > best1 % y) best1 = pre1[i];
		}
	}
	return mp(best0, best1);
}

inline bool check(int x, int y, const LL &sum)
{
	pair<int, int> tmp = find_best(y, 2 * x);
	if (~tmp.x && sum - tmp.x / y + (tmp.x - x * 2) / y >= x) 
		return 1;
	tmp = find_best(y, x);
	if (~tmp.x && ~tmp.y && sum - tmp.x / y - tmp.y / y + (tmp.x - x) / y + (tmp.y - x) / y >= x) 
		return 1;
	return 0;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int Max0 = 0, Max1 = 0;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		if (x > Max0) Max1 = Max0, Max0 = x;
		else chkmax(Max1, x);
		++cnt[x];
	}
	LL upperx = max(Max0 >> 1, Max1);
	int lst0 = -1, lst1 = -1;
	REP(i, 0, maxabs + 1)
	{
		pre0[i] = lst0;
		pre1[i] = lst1;
		if (cnt[i] == 1) lst1 = lst0, lst0 = i;
		else if (cnt[i] > 1) lst0 = lst1 = i;
	}
	for (int i = maxabs - 1; i >= 0; --i)
		cnt[i] += cnt[i + 1];
	LL ans = 0;
	for (int y = 2; y <= maxabs; ++y)
	{
		LL sum = 0;
		for (int i = y; i <= maxabs; i += y)
		{
			sum += cnt[i];
		}
		int Maxx = min(upperx, max(2LL, sum - (2 * sum + y + 1) / (y + 2)));
		REP(x, max(2, Maxx - 10), Maxx + 10)
			if (check(x, y, sum)) chkmax(ans, (LL)x * y);
	}
	printf("%lld\n", ans);
	return 0;
}
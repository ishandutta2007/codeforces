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

const int max0 = 30;

const int maxn = 200100;

int n;
int a[maxn + 5];
int b[maxn + 5];

int pre_bigger[maxn + 5];
int pre_good[maxn + 5];
int nxt_bigger[maxn + 5];
int nxt_good[maxn + 5];

int fen[maxn + 5];

int lst[max0 + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	vector<int> val;
	REP(i, 0, n) scanf("%d", a + i), val.pb(a[i]);
	sort(ALL(val));
	REP(i, 0, n) b[i] = lower_bound(ALL(val), a[i]) - val.begin();
	memset(fen, -1, sizeof fen);
	memset(lst, -1, sizeof lst);
	REP(i, 0, n)
	{
		int Max = -1;
		for (int j = b[i] + 1; j <= n; j += j & -j) chkmax(Max, fen[j]);
		pre_bigger[i] = Max;
		for (int j = b[i]; j > 0; j -= j & -j) fen[j] = i;
		pre_good[i] = -1;
		REP(j, 0, max0) 
			if (a[i] >> j & 1) lst[j] = i;
			else chkmax(pre_good[i], lst[j]);
	}

	memset(fen, oo, sizeof fen);
	memset(lst, oo, sizeof lst);
	for (int i = n - 1; i >= 0; --i)
	{
		int Min = n;
		for (int j = b[i] + 1; j <= n; j += j & -j) chkmin(Min, fen[j]);
		nxt_bigger[i] = Min;
		for (int j = b[i] + 1; j > 0; j -= j & -j) fen[j] = i;
		nxt_good[i] = n;
		REP(j, 0, max0) 
			if (a[i] >> j & 1) lst[j] = i;
			else chkmin(nxt_good[i], lst[j]);
	}

	LL ans = 0;
	REP(i, 0, n)
	{
		chkmax(pre_good[i], pre_bigger[i]);
		chkmin(nxt_good[i], nxt_bigger[i]);
		ans += (LL)(i - pre_bigger[i]) * (nxt_bigger[i] - i);
		ans -= (LL)(i - pre_good[i]) * (nxt_good[i] - i);
	}
	cout << ans << endl;
	return 0;
}
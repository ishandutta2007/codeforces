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

const int maxn = 550000, maxabs = 1e9 + 100;

int n, K;
int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	LL sum = 0;
	REP(i, 0, n) scanf("%d", a + i), sum += a[i];
	sort(a, a + n);
	int lo = sum / n, hi = (sum + n - 1) / n;
	int l = 0, r = lo;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		LL need = 0;
		REP(i, 0, n) if (a[i] < mid) need += mid - a[i];
		if (need <= K) l = mid;
		else r = mid - 1;
	}
	lo = l;
	l = hi, r = maxabs;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		LL need = 0;
		REP(i, 0, n) if (a[i] > mid) need += a[i] - mid;
		if (need <= K) r = mid;
		else l = mid + 1;
	}
	hi = l;
	printf("%d\n", hi - lo);
	return 0;
}
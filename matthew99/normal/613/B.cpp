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

const int maxn = 100000;

int n, A, cf, cm;
LL m;
int a[maxn + 5], b[maxn + 5], c[maxn + 5];
int pos[maxn + 5];
LL sum[maxn + 5];

inline bool cmp(int x, int y) { return b[x] < b[y]; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%I64d", &n, &A, &cf, &cm, &m);
	REP(i, 0, n) scanf("%d", a + i), b[i] = a[i], c[i] = a[i], pos[i] = i;
	sort(a, a + n);
	sum[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] + a[i];
	sort(pos, pos + n, cmp);
	LL ans = -1;
	int ansx = -1, ansy = -1;
	LL M = m;
	for (int i = n; i >= 0; --i)
	{
		if (m < 0) break;
		int l = 0, r = A;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			int p = lower_bound(a, a + i, mid) - a;
			if ((LL)mid * p - sum[p] > m) r = mid - 1;
			else l = mid;
		}
		if (chkmax(ans, LL(n - i) * cf + (LL)l * cm)) ansx = i, ansy = l;
		if (i) m -= A - a[i - 1];
	}
	printf("%I64d\n", ans);
	REP(i, ansx, n) b[pos[i]] = A;
	REP(i, 0, n) chkmax(b[i], ansy);
	LL tot = 0;
	REP(i, 0, n) printf("%d ", b[i]), assert(b[i] >= c[i]), tot += b[i] - c[i];
	assert(tot <= M);
	printf("\n");
	return 0;
}
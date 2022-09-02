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
const int maxk = 10;

vector<LL> all[maxk + 1];

int n, k, x;
LL a[maxn + 5], to[maxn + 5];
LL sum[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &k, &x);
	REP(i, 0, n) 
	{
		scanf("%I64d", a + i);
		to[i] = a[i];
		REP(j, 0, k) to[i] *= x;
	}
	sum[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] | a[i];
	LL ans = 0;
	LL now = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		chkmax(ans, sum[i] | now | to[i]);
		now |= a[i];
	}
	printf("%I64d\n", ans);
	return 0;
}
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

const int maxn = 2000, maxabs = 5000;

int n, a[maxn + 5];

double P[maxabs + 5], sum[maxabs + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	double tot = n * (n - 1) >> 1;
	REP(i, 0, n) REP(j, 0, n) if (i != j)
	{
		if (a[i] > a[j]) ++P[a[i] - a[j]];
	}
	REP(i, 0, maxabs + 1) P[i] /= tot;
	double ans = 0;
	sum[maxabs + 1] = 0;
	for (int i = maxabs; i >= 0; --i)
		sum[i] = sum[i + 1] + P[i];
	REP(i, 0, maxabs + 1) REP(j, 0, maxabs - i + 1) 
		ans += P[i] * P[j] * sum[i + j + 1];
	printf("%.15f\n", ans);
	return 0;
}
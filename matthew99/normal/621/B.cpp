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

const int max0 = 2000;

int n;

int cnt0[max0 + 5], cnt1[max0 + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	LL ans = 0;
	REP(i, 0, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans += cnt0[a - b + (max0 >> 1)];
		ans += cnt1[a + b];
		++cnt0[a - b + (max0 >> 1)];
		++cnt1[a + b];
	}
	printf("%I64d\n", ans);
	return 0;
}
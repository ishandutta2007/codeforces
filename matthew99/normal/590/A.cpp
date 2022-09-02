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

const int maxn = 500000;

int n;
int a[maxn + 5], b[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 1, n) b[i] = a[i] ^ a[i - 1];
	int ans = 0;
	for (int i = 1; i < n; )
	{
		int j = i;
		while (j < n && b[j] == 1) ++j;
		chkmax(ans, (j - i) >> 1);
		REP(k, i, j) b[k] = 0;
		if ((j - i) & 1) b[(i + j) >> 1] = 1;
		i = j + 1;
	}
	printf("%d\n", ans);
	int now = a[0];
	REP(i, 0, n)
	{
		printf("%d ", now);
		now ^= b[i + 1];
	}
	return 0;
}
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

int n, m;
int a[maxn + 5];

int work(int x)
{
	int ret = 0;
	for (int i = 0; i < n; )
	{
		int j = i;
		while (j < n && a[j] - a[i] < x) ++j;
		ret += j - i - 1;
		i = j;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	m = ((n - 2) >> 1) + 1;
	sort(a, a + n);
	int ans = oo;
	REP(i, 0, n - m) chkmin(ans, a[i + m] - a[i]);
	printf("%d\n", ans);
	return 0;
}
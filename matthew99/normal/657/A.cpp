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

int n, d, h;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &d, &h);
	if (n == 2)
	{
		printf("1 2\n");
		return 0;
	}
	if ((h << 1) < d || d == 1) 
	{
		printf("-1\n");
		return 0;
	}
	static int a[maxn + 5];
	REP(i, 0, d + 1) a[i] = i;
	rotate(a, a + h + 1, a + d + 1);
	REP(i, 0, d) printf("%d %d\n", a[i] + 1, a[i + 1] + 1);
	REP(i, d + 1, n) printf("%d %d\n", a[d >> 1] + 1, i + 1);
	return 0;
}
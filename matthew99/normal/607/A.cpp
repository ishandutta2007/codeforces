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

int n;
pair<int, int> a[maxn + 5];

int dep[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + n);
	REP(i, 0, n)
	{
		int tmp = lower_bound(a, a + n, mp(a[i].x - a[i].y, 0)) - a - 1;
		if (tmp < 0) dep[i] = 1;
		else dep[i] = dep[tmp] + 1;
	}
	printf("%d\n", n - *max_element(dep, dep + n));
	return 0;
}
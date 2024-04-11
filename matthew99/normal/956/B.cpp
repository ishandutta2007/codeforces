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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n, U;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &U);
	REP(i, 0, n) scanf("%d", a + i);
	bool flag = 0;
	int ptr = 0;
	double ans = 0;
	REP(i, 0, n)
	{
		while (ptr + 1 < n && a[ptr + 1] - a[i] <= U) ++ptr;
		if (ptr > i + 1)
		{
			flag = 1;
			chkmax(ans, double(a[ptr] - a[i + 1]) / (a[ptr] - a[i]));
		}
	}
	if (!flag) printf("-1\n");
	else printf("%.15f\n", ans);
	return 0;
}
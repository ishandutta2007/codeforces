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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	if (n <= 2) puts("-1");
	else
	{
		int tmp = n & -n;
		if (tmp == n)
		{
			tmp >>= 2;
			printf("%d %d\n", 3 * tmp, 5 * tmp);
			exit(0);
		}
		n /= tmp;
		LL a = (LL)n * n >> 1, b = a + 1;
		a *= tmp, b *= tmp;
		printf("%I64d %I64d\n", a, b);
	}
	return 0;
}
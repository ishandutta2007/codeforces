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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[20];
	int n;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	bool found = 0;
	REP(i, 0, 1 << n)
	{
		int tmp = 0;
		REP(j, 0, n) if (i >> j & 1) tmp += a[j]; else tmp -= a[j];
		if ((tmp % 360) == 0)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
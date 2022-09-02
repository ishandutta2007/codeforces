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

const int maxn = 30;

int p[maxn + 5];

int main()
{
#ifdef matthew99
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int m, n;
	scanf("%d%d", &m, &n);
	REP(i, 0, n)
	{
		printf("1\n");
		fflush(stdout);
		scanf("%d", p + i);
		if (!p[i]) exit(0);
		p[i] = p[i] == 1;
	}
	int l = 1, r = m;
	int cur = 0;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (p[cur]) x = -x;
		if (!x) exit(0);
		if (x == 1) r = mid - 1;
		if (x == -1) l = mid + 1;
		(++cur) %= n;
	}
	printf("%d\n", l);
	return 0;
}
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

const int maxn = 500100;

int n;
int a[maxn + 5];
int b[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int par = 0;
	REP(i, 0, n) scanf("%d", a + i), par ^= a[i] & 1;
	int from = -1, to = -1;
	int l = 0, r = n;

	while (l < r)
	{
		int mid = (l + r) >> 1;
		REP(i, 0, n) b[i] = a[i];
		b[n] = mid;
		sort(b, b + n + 1, greater<int>());

		static LL sum[maxn + 5];
		sum[0] = 0;
		REP(i, 0, n + 1)
			sum[i + 1] = sum[i] + b[i];

		bool failed = 0;
		int ptr = n + 1;
		REP(i, 1, n + 2)
		{
			chkmax(ptr, i);
			while (ptr > i && b[ptr - 1] < i) --ptr;
			LL lhs = sum[i];
			LL rhs = LL(i) * (i - 1) + LL(ptr - i) * i + sum[n + 1] - sum[ptr];
			if (lhs > rhs && b[i - 1] > mid) failed = 1;
		}

		if (failed) l = mid + 1;
		else r = mid;
	}
	from = l;

	l = 0, r = n;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		REP(i, 0, n) b[i] = a[i];
		b[n] = mid;
		sort(b, b + n + 1, greater<int>());

		static LL sum[maxn + 5];
		sum[0] = 0;
		REP(i, 0, n + 1)
			sum[i + 1] = sum[i] + b[i];

		bool failed = 0;
		int ptr = n + 1;
		REP(i, 1, n + 2)
		{
			chkmax(ptr, i);
			while (ptr > i && b[ptr - 1] < i) --ptr;
			LL lhs = sum[i];
			LL rhs = LL(i) * (i - 1) + LL(ptr - i) * i + sum[n + 1] - sum[ptr];
			if (lhs > rhs && b[i - 1] <= mid) failed = 1;
		}

		if (failed) r = mid - 1;
		else l = mid;
	}
	to = l;

	bool empty = 1;
	REP(i, from, to + 1) if (!(par ^ (i & 1))) printf("%d ", i), empty = 0;
	if (empty) printf("-1");
	printf("\n");
	return 0;
}
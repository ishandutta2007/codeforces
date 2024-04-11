#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)

using namespace std;

const int maxn = 100000, maxm = 100000;

int n, m;

struct data
{
	int l, r, q;

	data() { }
	data(const int &_l, const int &_r, const int &_q): l(_l), r(_r), q(_q) { }

	friend bool operator < (const data &x, const data &y)
	{
		if (x.l == y.l) return x.r < y.r;
		return x.l < y.l;
	}

};

data a[maxm + 5];

int ans[maxm + 5] = {0};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].q), --a[i].l;
	sort(a, a + m);
	REP(j, 0, 30)
	{
		int cur = -1;
		REP(i, 0, m)
			if (a[i].q >> j & 1)
				for (cur = max(cur, a[i].l); cur < a[i].r; ++cur) ans[cur] |= 1 << j;
		static int sum[maxn + 5];
		sum[0] = 0;
		REP(i, 0, n)
			sum[i + 1] = sum[i] + (ans[i] >> j & 1);
		REP(i, 0, m)
			if (!(a[i].q >> j & 1) && sum[a[i].r] - sum[a[i].l] == a[i].r - a[i].l) EXIT("NO\n");
	}
	printf("YES\n");
	REP(i, 0, n) printf("%d ", ans[i]);
	return 0;
}
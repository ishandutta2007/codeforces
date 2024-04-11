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

int n, k, a, b, qn;
int sum0[maxn + 5], sum1[maxn + 5];

void add(int x, int y, int *sum)
{
	for (int i = x + 1; i <= n; i += i & -i) sum[i] += y;
}

int query(int x, int *sum)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += sum[i];
	return ret;
}

int now[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &qn);
	REP(i, 0, qn)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			int d, x;
			scanf("%d%d", &d, &x), --d;
			int old = now[d];
			now[d] += x;
			add(d, min(now[d], a) - min(old, a), sum0);
			add(d, min(now[d], b) - min(old, b), sum1);
		}
		else
		{
			int p;
			scanf("%d", &p), --p;
			printf("%d\n", query(n, sum0) - query(p + k, sum0) + query(p, sum1));
		}
	}
	return 0;
}
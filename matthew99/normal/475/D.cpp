#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)

using namespace std;

const int oo = 0x3f3f3f3f;

typedef long long LL;

int gcd(int x, int y) { while (y) y ^= x ^= y ^= x %= y; return x; }

const int maxn = (int)1e5, maxq = (int)3e5;

const int MAX = 17;

int n;
int a[maxn + 5];

int g[maxn + 5][MAX];

int nq;

int q[maxq + 5];

map<int, LL> all;

int Log[maxn + 5];

void init()
{
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), g[i][0] = a[i];
	scanf("%d", &nq);
	REP(i, 0, nq) scanf("%d", q + i), all[q[i]] = 0;
}

void prepare()
{
	REP(j, 1, MAX)
		REP(i, 0, n)
			g[i][j] = gcd(g[i][j - 1], i + (1 << (j - 1)) < n ? g[i + (1 << (j - 1))][j - 1] : g[i][j - 1]);
	REP(i, 1, n + 1)
		for (int j = 0; (1 << j) <= i; ++j) Log[i] = j;
}

int Gcd(const int &x, const int &y)
{
	int t = Log[y - x];
	return gcd(g[x][t], g[y - (1 << t)][t]);
}

int work(const int &x, const int &y, const int &bound = n - 1)
{
	if (y == a[x]) return -1;
	int l = x + 1, r = bound;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (Gcd(x, mid) > y) l = mid;
		else r = mid - 1;
	}
	return l;
}

void add(const int &a, const int &b)
{
	if (all.count(a)) all[a] += b;
}

void solve()
{
	REP(i, 0, n)
	{
		int lst = Gcd(i, n);
		int bound = n;
		for ( ; ; )
		{
			int lyc = work(i, lst, bound);
			if (lyc == -1)
			{
				add(lst, bound - i);
				break;
			}
			add(lst, bound - lyc);
			bound = lyc;
			lst = Gcd(i, lyc);
		}
	}
}

void output()
{
	REP(i, 0, nq) printf("%I64d\n", all[q[i]]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	prepare();
	solve();
	output();
	return 0;
}
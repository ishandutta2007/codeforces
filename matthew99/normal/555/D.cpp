#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 200000;

int n, m;
int x[maxn + 5];
int pos[maxn + 5], rk[maxn + 5];

inline bool cmp(const int &x, const int &y) { return ::x[x] < ::x[y]; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", x + i), pos[i] = i;
	sort(pos, pos + n, cmp);
	sort(x, x + n);
	REP(i, 0, n) rk[pos[i]] = i;
	REP(i, 0, m)
	{
		static int a, l;
		scanf("%d%d", &a, &l), --a;
		a = rk[a];
		while (1)
		{
			int p = upper_bound(x, x + n, x[a] + l) - x;
			--p;
			p = max(p, a);
			l -= x[p] - x[a];
			int p0 = lower_bound(x, x + n, x[p] - l) - x;
			if (p == a && p0 == a)
			{
				printf("%d\n", pos[a] + 1);
				break;
			}
			if (p0 == a)
			{
				int t = l / (x[p] - x[a]);
				l %= x[p] - x[a];
				if (!(t & 1)) l += x[p] - x[a];
			}
			else
			{
				if (p0 == p)
				{
					printf("%d\n", pos[p] + 1);
					break;
				}
				a = p0, l -= x[p] - x[p0];
			}
		}
	}
	return 0;
}
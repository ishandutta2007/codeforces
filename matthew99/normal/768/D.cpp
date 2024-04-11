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

const int maxn = 1010, maxp = 1000;

const double eps = 1e-7;

double P[maxn + 5];

int ans[maxp + 5];
double lim[maxp + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, qn;
	scanf("%d%d", &n, &qn);
	P[0] = 1;
	REP(i, 0, maxp + 1) lim[i] = (i - eps) / 2000;
	int day = 0;
	int now = 0;
	while (1)
	{
		while (now <= maxp && P[n] >= lim[now]) ans[now] = day, ++now;
		if (now > maxp) break;
		++day;
		for (int i = n - 1; i >= 0; --i)
		{
			P[i + 1] += P[i] * (1 - (double)i / n);
			P[i] *= (double)i / n;
		}
	}
	REP(i, 0, qn)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
	return 0;
}
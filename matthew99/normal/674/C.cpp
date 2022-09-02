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

int n, K;
int a[maxn + 5];
double sum[maxn + 5];
double sumf[maxn + 5], sumg[maxn + 5];

double dp[maxn + 5];

inline double cross(const pair<double, double> &a, const pair<double, double> &b, const pair<double, double> &c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline double calc(const pair<double, double> &a, const double &b) { return b * a.x + a.y; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	sum[0] = 0;
	REP(i, 0, n) scanf("%d", a + i), sum[i + 1] = sum[i] + a[i];
	sumf[0] = sumg[0] = 0;
	REP(i, 0, n)
	{
		sumf[i + 1] = sumf[i] + sum[i + 1] / a[i];
		sumg[i + 1] = sumg[i] - 1. / a[i];
	}
	dp[0] = 0;
	REP(i, 0, K)
	{
		static pair<double, double> q[maxn + 5];
		int head = 0, rear = 0;
		q[rear++] = mp(sum[i], dp[i] - sumf[i] - (sumg[i] * sum[i]));
		REP(j, 0, i + 1) dp[j] = -1;
		REP(j, i + 1, n + 1)
		{
			pair<double, double> bar = mp(sum[j], dp[j] - sumf[j] - (sumg[j] * sum[j]));
			while (head + 1 < rear && calc(q[head], sumg[j]) > calc(q[head + 1], sumg[j])) ++head;
			dp[j] = calc(q[head], sumg[j]) + sumf[j];
			if (i)
			{
				while (head + 1 < rear && cross(q[rear - 2], q[rear - 1], bar) <= 0) --rear;
				q[rear++] = bar;
			}
		}
	}
	printf("%.15f\n", dp[n]);
	return 0;
}
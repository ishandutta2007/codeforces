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

const int maxn = 100000;

double x[maxn + 5], y[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double Max = 0, Min = 1e100;
	int n;
	double Px, Py;
	scanf("%d%lf%lf", &n, &Px, &Py);
	REP(i, 0, n)
	{
		scanf("%lf%lf", x + i, y + i);
		x[i] -= Px, y[i] -= Py;
		double tmp = x[i] * x[i] + y[i] * y[i];
		chkmax(Max, tmp), chkmin(Min, tmp);
	}
	REP(i, 0, n)
	{
		double tmpx = y[i] - y[(i + 1) % n], tmpy = x[(i + 1) % n] - x[i];
		double tmp = abs(x[i] * y[(i + 1) % n] - y[i] * x[(i + 1) % n]);
		double tmp0 = sqrt((x[i] - x[(i + 1) % n]) * (x[i] - x[(i + 1) % n]) + (y[i] - y[(i + 1) % n]) * (y[i] - y[(i + 1) % n]));
		if ((tmpx * y[i] - tmpy * x[i]) * (tmpx * y[(i + 1) % n] - tmpy * x[(i + 1) % n]) <= 0) 
		{
			chkmin(Min, (tmp / tmp0) * (tmp / tmp0));
		}
	}
	double ans = Max - Min;
	ans *= acos(-1);
	printf("%.10f\n", ans);
	return 0;
}
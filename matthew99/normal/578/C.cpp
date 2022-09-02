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

const double eps = 1e-12;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int n;
int a[maxn + 5];

double work(double x)
{
	double ret = 0;
	double sum = 0;
	double Min = 0, Max = 0;
	REP(i, 0, n) 
	{
		sum += a[i] - x;
		chkmax(ret, abs(sum - Min));
		chkmax(ret, abs(sum - Max));
		chkmin(Min, sum);
		chkmax(Max, sum);
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	long double l = -10000, r = 10000;
	while (1)
	{
		if (clock() >= 1.9 * CLOCKS_PER_SEC) break;
		double midl = (2 * l + r) / 3;
		double midr = (l + 2 * r) / 3;
		if (work(midl) < work(midr)) r = midr;
		else l = midl;
	}
	printf("%.15f\n", work(l));
	return 0;
}
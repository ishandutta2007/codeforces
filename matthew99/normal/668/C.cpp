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

int n;
double Max[maxn + 5], Min[maxn + 5];

double a[maxn + 5], b[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lf", Max + i);
	REP(i, 0, n) scanf("%lf", Min + i);
	//(prea + a[i]) * (preb + b[i]) = preMax
	//(1 - prea - a[i]) * (1 - preb - b[i]) = 1 - preMin
	//(1 - u) * (1 - v) = 1 - preMin
	//u + v - uv = preMin
	//u + v = preMin + preMax
	double prea = 0, preb = 0;
	double preMin = 0;
	double preMax = 0;
	REP(i, 0, n)
	{
		preMin += Min[i];
		preMax += Max[i];
		double sum = preMin + preMax;
		double prod = preMax;
		double delta = sqrt(max((double)0, sum * sum - 4 * prod));
		double u = (sum - delta) / 2;
		double v = (sum + delta) / 2;
		a[i] = u - prea;
		b[i] = v - preb;
		prea = u, preb = v;
	}
	REP(i, 0, n) printf("%.15f ", a[i]);
	printf("\n");
	REP(i, 0, n) printf("%.15f ", b[i]);
	printf("\n");
	return 0;
}
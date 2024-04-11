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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 100;

int n;

double p[maxn + 5], P[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lf", p + i), p[i] /= 100, p[i] = 1 - p[i], P[i] = 1;
	double ans = 0;
	while (clock() <= 1.5 * CLOCKS_PER_SEC)
	{
		double tmp = 1;
		REP(j, 0, n) tmp *= 1 - P[j];
		ans += 1 - tmp;
		int delp = -1;
		double Max = -1;
		REP(j, 0, n) 
			if (P[j] == 1) 
			{
				delp = j;
				break;
			}
			else if (chkmax(Max, (1 - P[j] * p[j]) / (1 - P[j]))) delp = j;
		P[delp] *= p[delp];
	}
	printf("%f\n", ans);
	return 0;
}
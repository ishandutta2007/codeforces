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

const double pi = acos(-1);

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

int n, R, v;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &R, &v);
	double w = (double)v / R;
	REP(i, 0, n)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		double l = 0, r = double(t - s) / v;
		REP(j, 0, 100)
		{
			double mid = (l + r) / 2;
			double val = mid * v + 2.0 * R * abs(sin(mid * w / 2));
			if (val > t - s) r = mid;
			else l = mid;
		}
		printf("%.15f\n", l);
	}
	return 0;
}
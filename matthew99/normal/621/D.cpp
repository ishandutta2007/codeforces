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

const int Mod = 1e9 + 7;

const int maxn = 100000;

const long double eps = 1e-12;

long double x, y, z;

inline bool eq(const long double &x, const long double &y)
{
	return abs(x - y) < eps || abs(x - y) < eps * abs(x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	{
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		x = a, y = b, z = c;
	}
	long double logx = log(x);
	long double logy = log(y);
	long double logz = log(z);
	long double a[11];
	a[0] = logx * pow(y, z);
	a[1] = logx * pow(z, y);
	a[2] = logx * y * z;
	a[3] = a[2];
	a[4] = logy * pow(x, z);
	a[5] = logy * pow(z, x);
	a[6] = logy * x * z;
	a[7] = a[6];
	a[8] = logz * pow(x, y);
	a[9] = logz * pow(y, x);
	a[10] = logz * x * y;
	long double tmp = -1;
	int ansp = -1;
	REP(i, 0, 11) if (!eq(a[i], tmp) && a[i] > tmp)
	{
		tmp = a[i];
		ansp = i;
	}
	if (ansp == 0) printf("x^y^z\n");
	if (ansp == 1) printf("x^z^y\n");
	if (ansp == 2) printf("(x^y)^z\n");
	if (ansp == 4) printf("y^x^z\n");
	if (ansp == 5) printf("y^z^x\n");
	if (ansp == 6) printf("(y^x)^z\n");
	if (ansp == 8) printf("z^x^y\n");
	if (ansp == 9) printf("z^y^x\n");
	if (ansp == 10) printf("(z^x)^y\n");
	return 0;
}
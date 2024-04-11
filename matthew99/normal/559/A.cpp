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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[6];
	REP(i, 0, 6) scanf("%d", a + i);
	long double X = 0, Y = 0;
	long double step = acos((long double)-1) / 3;
	long double sum = 0;
	REP(i, 0, 6)
	{
		long double xx = sin(i * step), yy = cos(i * step);
		xx *= a[i], yy *= a[i];
		sum -= X * yy - Y * xx;
		X += xx, Y += yy;
	}
	cout << LL(sum / (sqrt(3.0) / 2.0) + 0.5) << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int R, X1, Y1, X2, Y2;

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

void Print(ld x, ld y, ld r)
{
	cout << fixed << setprecision(15) << x << " " <<
			fixed << setprecision(15) << y << " " <<
			fixed << setprecision(15) << r << endl;
}

int main()
{
	scanf("%d %d %d %d %d", &R, &X1, &Y1, &X2, &Y2);
	ld d = Dist(X1 - X2, Y1 - Y2);
	if (d >= R) { Print(X1, Y1, R); return 0; }
	if (d < 1e-9l) { Print(X1 + ld(R) / 2.0l, Y1, ld(R) / 2.0l); return 0; }
	ld ax = X1 - X2, ay = Y1 - Y2;
	ld myr = (d + R) / 2.0;
	ax /= d; ay /= d;
	ld X = X2 + ax * myr, Y = Y2 + ay * myr;
	Print(X, Y, myr);
	return 0;
}
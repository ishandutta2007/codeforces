#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld pi = acos(-1.0l);
const ld eps = 1e-15l;

ld X1, Y1, R1;
ld X2, Y2, R2;
ld res;

ld Len(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

ld getPie(ld ang, ld r)
{
	return ang / 2.0l * r * r;
}

ld getTrian(ld ang, ld r)
{
	return sin(ang) * r * r / 2.0l;
}

void Print()
{
	cout << fixed << setprecision(15) << res << endl;
}

ld Acos(ld arg)
{
	if (arg < -1.0) arg = -1.0;
	if (arg > 1.0) arg = 1.0;
	return acos(arg); 
}

ld getAng(ld c, ld a, ld b)
{
	return Acos((a * a + b * b - c * c) / (2.0l * a * b));
}

int main()
{
	cin >> X1 >> Y1 >> R1;
	cin >> X2 >> Y2 >> R2;
	if (R1 < R2) { swap(X1, X2); swap(Y1, Y2); swap(R1, R2); }
	ld d = Len(X1 - X2, Y1 - Y2);
	if (R1 + R2 <= d + eps) { Print(); return 0; }
	if (d <= R1 - R2 + eps) { res += getPie(2 * pi, R2); Print(); return 0; }
	if (fabs(X1 - X2) <= eps && fabs(Y1 - Y2) <= eps) { res += getPie(2 * pi, R2); Print(); return 0; }

	ld alpha = 2 * getAng(R1, R2, d);
	ld beta = 2 * getAng(R2, R1, d);
	res += getPie(beta, R1) - getTrian(beta, R1);

	if (alpha <= pi) res += getPie(alpha, R2) - getTrian(alpha, R2);
	else res += getPie(2 * pi, R2) - (getPie(2 * pi - alpha, R2) - getTrian(2 * pi - alpha, R2));
	Print();
	return 0;
}
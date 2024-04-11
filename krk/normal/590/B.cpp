#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

int X1, Y1, X2, Y2;
int vmax, t;
int vx, vy, wx, wy;

bool Pos(ld tim)
{
	ld cx = X1, cy = Y1;
	ld tk = min(tim, ld(t)); 
	cx += tk * vx; cy += tk * vy;
	cx += (tim - tk) * wx; cy += (tim - tk) * wy;
	ld ux = X2 - cx, uy = Y2 - cy;
	return sqrt(ux * ux + uy * uy) / vmax <= tim;

}

int main()
{
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	scanf("%d %d", &vmax, &t);
	scanf("%d %d %d %d", &vx, &vy, &wx, &wy);
	ld l = 0l, r = 1000000000ll;
	for (int i = 0; i < 70; i++) {
		ld m = (l + r) / 2;
		if (Pos(m)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(12) << r << endl;
	return 0;
}
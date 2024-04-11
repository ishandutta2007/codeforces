#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;

const ld eps = 1e-9l;

ld xv, yv;
ld xp, yp;
ld xr, yr;
ld xw1, yw1, xw2, yw2;
ld xm1, ym1, xm2, ym2;
ld xr1, yr1, xr2, yr2;

void Rot(ld &X, ld &Y, ld ang)
{
	ld nX = X * cos(ang) + Y * sin(ang);
	ld nY = -X * sin(ang) + Y * cos(ang);
	X = nX; Y = nY;
}

void Mirror(ld X, ld Y, ld x1, ld y1, ld x2, ld y2, ld &nX, ld &nY)
{
	nX = X; nY = Y;
	nX -= x1; nY -= y1;
	ld ang = atan2(y2 - y1, x2 - x1);
	Rot(nX, nY, ang);
	nY = -nY;
	Rot(nX, nY, -ang);
	nX += x1; nY += y1;
}

bool Intersect(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x4, ld y4)
{
	ld A1, B1, C1; A1 = y2 - y1; B1 = x1 - x2; C1 = A1 * x1 + B1 * y1;
	ld A2, B2, C2; A2 = y4 - y3; B2 = x3 - x4; C2 = A2 * x3 + B2 * y3;
	ld det = A1 * B2 - A2 * B1;
	if (fabs(det) <= eps)
		if (fabs(A2 * x1 + B2 * y1 - C2) <= eps)
			if (fabs(x1 - x2) <= eps)
				return min(y1, y2) <= min(y3, y4) + eps && min(y3, y4) <= max(y1, y2) + eps ||
		        	   min(y3, y4) <= min(y1, y2) + eps && min(y1, y2) <= max(y3, y4) + eps;
			else return min(x1, x2) <= min(x3, x4) + eps && min(x3, x4) <= max(x1, x2) + eps ||
				        min(x3, y4) <= min(x1, x2) + eps && min(x1, x2) <= max(x3, y4) + eps;
		else return false;
	ld X = (B2 * C1 - B1 * C2) / det;
	ld Y = (A1 * C2 - A2 * C1) / det;
	return min(x1, x2) <= X + eps && X <= max(x1, x2) + eps && min(y1, y2) <= Y + eps && Y <= max(y1, y2) + eps &&
		   min(x3, x4) <= X + eps && X <= max(x3, x4) + eps && min(y3, y4) <= Y + eps && Y <= max(y3, y4) + eps;
}

int main()
{
	cin >> xv >> yv;
	cin >> xp >> yp;
	cin >> xw1 >> yw1 >> xw2 >> yw2;
	cin >> xm1 >> ym1 >> xm2 >> ym2;
	if (!Intersect(xv, yv, xp, yp, xw1, yw1, xw2, yw2) && !Intersect(xv, yv, xp, yp, xm1, ym1, xm2, ym2))
		printf("YES\n");
	else {
		Mirror(xw1, yw1, xm1, ym1, xm2, ym2, xr1, yr1);
		Mirror(xw2, yw2, xm1, ym1, xm2, ym2, xr2, yr2);
		Mirror(xv, yv, xm1, ym1, xm2, ym2, xr, yr);
		if ((fabs(xr - xp) >= eps || fabs(yr - yp) >= eps) && Intersect(xp, yp, xr, yr, xm1, ym1, xm2, ym2) && 
			!Intersect(xp, yp, xr, yr, xw1, yw1, xw2, yw2) && !Intersect(xp, yp, xr, yr, xr1, yr1, xr2, yr2))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
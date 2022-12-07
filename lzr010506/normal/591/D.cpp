#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
double vm, t, dx, dy;
double px1, py1, px2, py2, vx1, vy1, vx2, vy2;

bool check(double mid)
{
	double x, y, d;
	x = px2;
	y = py2;
	if(mid >= t) x = x - vx2 * (mid - t) - vx1 * t, y = y - vy2 * (mid - t) - vy1 * t;
	else x -= mid * vx1, y -= mid * vy1;
	d = mid * vm;
	if ((x - px1) * (x - px1) + (y - py1) * (y - py1) <= d * d) return true;
    else return false;
}

int main()
{
	scanf("%lf%lf%lf%lf",&px1,&py1,&px2,&py2);
	scanf("%lf%lf",&vm,&t);
	scanf("%lf%lf",&vx1,&vy1);
	scanf("%lf%lf",&vx2,&vy2);
	dx = px2 - px1;
	dy = py2 - py1;
	double l = 0, r = 1e9;
	while(r - l >= eps)
	{
		double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.8lf", r);
	return 0;
}
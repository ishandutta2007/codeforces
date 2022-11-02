#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

double vp, vd, t, f, c;

int sgn(double A){
	if (A > 1e-7) return 1;
	if (A < -1e-7) return -1;
	return 0;
}

int main(){
	//freopen("b.in", "r", stdin);
	scanf("%lf%lf%lf%lf%lf", &vp, &vd, &t, &f, &c);
	if (sgn(vd - vp) <= 0)
	{
		printf("0\n");
		return 0;
	}
	double position = vp * t;
	int ans = 0;
	for (;;)
	{
		double value = position / (vd - vp);
		if (sgn(value * vp + position - c) >= 0) 
		{
			printf("%d\n", ans);
			return 0;
		}
		++ans;
		position += value * vp;
		position += (position / vd + f) * vp;
	}
}
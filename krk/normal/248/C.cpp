#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-11;

double Y1, Y2, Yw, Xb, Yb, R;

int main()
{
	scanf("%lf %lf %lf %lf %lf %lf", &Y1, &Y2, &Yw, &Xb, &Yb, &R);
	double Yg = Y1 + R;
	double tanB = (2.0 * Yw - 2.0 * R - Yb - Yg) / Xb;
	double B = atan(tanB);
	if ((Y2 - Yg) * cos(B) <= R + eps) printf("-1\n");
	else {
		double Xw = Xb - (Yw - R - Yb) / tanB;
		printf("%.16lf\n", Xw);
	}
	return 0;
}
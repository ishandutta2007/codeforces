#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.0);
const int steps = 1000000;
const double step = pi / 2.0 / steps;

int r, h;
int d;
int res;

bool Ok()
{
	for (double ang = 0.0; ang <= pi / 2; ang += step) {
		double x = r / 2.0 + r / 2.0 * cos(ang);
		double y1 = sqrt((r / 2.0) * (r / 2.0) - (x - r / 2.0) * (x - r / 2.0)) - d + r / 2.0;
		double y2 = sqrt(double(r) * r - double(x) * x);
		if (y2 + eps < y1) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &r, &h);
	res += h / r * 2;
	d = h % r;
	if (Ok()) {
		res += 2;
		double u = -d + r + sqrt(3.0) / 2.0 * r;
		if (u <= r + eps) res++;
	} else res++;
	printf("%d\n", res);
	return 0;
}
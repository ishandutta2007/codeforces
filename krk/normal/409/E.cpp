#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double x;
double best = 1e30;
int ba, bh;

int main()
{
	scanf("%lf", &x);
	for (int a = 1; a <= 10; a++)
		for (int h = 1; h <= 10; h++) {
			double C = sqrt(h * h + a * a / 4.0);
			double y = (C * C + h * h - a * a / 4.0) / (2.0 * C);
			double r = sqrt(h * h - y * y);
			if (fabs(r - x) < best) { best = fabs(r - x); ba = a; bh = h; }
		}
	printf("%d %d\n", ba, bh);
	return 0;
}
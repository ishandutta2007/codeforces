#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int w, h, a;
const double eps = 1e-8;

void Rot(double x, double y, double a, double &nx, double &ny)
{
	nx = cos(a) * x - sin(a) * y;
	ny = sin(a) * x + cos(a) * y;
}

double Cross(double ax, double ay, double bx, double by) { return ax * by - ay * bx; }

int main()
{
	scanf("%d %d %d", &w, &h, &a);
	if (h > w) swap(h, w);
	if (a == 0) printf("%.8lf\n", double(h) * w);
	else if (a == 90) printf("%.8lf\n", double(h) * double(h));
	else {
		if (a > 90) a = 180 - a;
		double t = tan(acos(-1.0) / 180.0 * a);
		double tt = t * t;
		double expr = 1.0 + sqrt(1.0 + tt);
		double x = (w * expr - h * t) / (expr * expr - tt);
		double y = (h - x * t) / expr;
		if (y + eps < 0.0 || x + eps < 0.0) {
			double x1, y1, x2, y2, x3, y3, x4, y4;
			Rot(w / 2.0, h / 2.0, acos(-1.0) / 180.0 * a, x1, y1);
			Rot(-w / 2.0, h / 2.0, acos(-1.0) / 180.0 * a, x2, y2);
			Rot(w / 2.0, -h / 2.0, acos(-1.0) / 180.0 * a, x3, y3);
			Rot(-w / 2.0, -h / 2.0, acos(-1.0) / 180.0 * a, x4, y4);
			double x5, x6, x7;
			x5 = ((x1 - x2) * (h / 2.0) + x2 * y1 - x1 * y2) / (y1 - y2);
			x6 = ((x1 - x2) * (-h / 2.0) + x2 * y1 - x1 * y2) / (y1 - y2);
			x7 = ((x3 - x4) * (h / 2.0) + x4 * y3 - x3 * y4) / (y3 - y4);
			printf("%.8lf\n", fabs(Cross(x6 - x5, h, x7 - x5, 0)));
		} else printf("%.8lf\n", double(h) * w - x * x * t - y * y * t);
	}
	return 0;
}
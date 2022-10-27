#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
double a, b, c;
int x1, y1, x2, y2;
double dist(double xs, double ys, double xe, double ye)
{
	return sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye));
}

signed main() {
	cin >> a >> b >> c;
	cin >> x1 >> y1 >> x2 >> y2;
	if(a == 0 || b == 0)
	{
		cout << abs(x1 - x2) + abs(y1 - y2);
		return 0;
	}
	double y3 = (- c - a * x1) / b;
	double x3 = (- c - b * y1) / a;
	double y4 = (- c - a * x2) / b;
	double x4 = (-c - b * y2) / a;
	double ans = fabs(y3 - y1) + min(fabs(y4 - y2) + dist(x1, y3, x2, y4), fabs(x2 - x4) + dist(x1, y3, x4, y2));
	ans = min(ans, fabs(x1 - x3) + min(fabs(y4 - y2) + dist(x3, y1, x2, y4), fabs(x2 - x4) + dist(x3, y1, x4, y2)));
	double p = fabs(x1 - x2) + fabs(y1 - y2);
	ans = min(ans, p);
	cout << fixed << setprecision(7) << ans; 
	return 0;
}
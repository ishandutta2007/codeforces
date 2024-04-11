#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-4;
const double pi = acos(-1);
pair <double, double> inter(double A1, double B1, double C1, double A2, double B2, double C2)
{
	double d1 = A1 * B2 - A2 * B1;
	double d2 = B1 * C2 - B2 * C1;
	double d3 = A1 * C2 - A2 * C1;
	double x = d2 / d1;
	double y = -d3 / d1;
	return {x, y};
}
double crossproduct(pair <double, double> a, pair <double, double> b, pair <double, double> c)
{
	return (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first);
}
double dotproduct(pair <double, double> a, pair <double, double> b, pair <double, double> c)
{
	return (a.first - b.first) * (c.first - b.first) + (a.second - b.second) * (c.second - b.second);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double x12 = (x1 + x2) / 2;
	double y12 = (y1 + y2) / 2;
	double A1 = x1 - x2;
	double B1 = y1 - y2;
	double C1 = -A1 * x12 - B1 * y12;
	double x23 = (x2 + x3) / 2;
	double y23 = (y2 + y3) / 2;
	double A2 = x2 - x3;
	double B2 = y2 - y3;
	double C2 = -A2 * x23 - B2 * y23;
	pair <double, double> v = inter(A1, B1, C1, A2, B2, C2);
	double dist = (v.first - x1) * (v.first - x1) + (v.second - y1) * (v.second - y1);
	double fi1 = atan2(crossproduct({x1, y1}, v, {x2, y2}), dotproduct({x1, y1}, v, {x2, y2}));
	double fi2 = atan2(crossproduct({x2, y2}, v, {x3, y3}), dotproduct({x2, y2}, v, {x3, y3}));
	double fi3 = atan2(crossproduct({x3, y3}, v, {x1, y1}), dotproduct({x3, y3}, v, {x1, y1}));
	if(fi1 < 0)
	{
		fi1 += 2 * pi;
	}
	if(fi1 > pi)
	{
		fi1 = 2 * pi - fi1;
	}
	if(fi2 < 0)
	{
		fi2 += 2 * pi;
	}
	if(fi2 > pi)
	{
		fi2 = 2 * pi - fi2;
	}
	if(fi3 < 0)
	{
		fi3 += 2 * pi;
	}
	if(fi3 > pi)
	{
		fi3 = 2 * pi - fi3;
	}
	for(int n = 3; n <= 100; n++)
	{
		if(fabs(sin(fi1 * n / 2)) < eps && fabs(sin(fi2 * n / 2)) < eps && fabs(sin(fi3 * n / 2)) < eps)
		{
			cout << fixed << setprecision(10) << 1.0 / 2 * fabs(sin(2 * pi / n)) * dist * n;
			return 0;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define double long double
const double eps = 1e-10;
double sqrdist(double x1, double y1, double x2, double y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
}
double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqrdist(x1, y1, x2, y2));
}
const double pi = acos(-1.0);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double x0, y0, v, t;
    cin >> x0 >> y0 >> v >> t;
    double r0 = v * t;
    int n;
    cin >> n;
    vector <pair <double, int> > a;
    for(int i = 0; i < n; i++)
    {
    	double x, y, r;
    	cin >> x >> y >> r;
    	double d = sqrdist(x, y, x0, y0);
    	if(d < r * r + eps)
    	{
    		cout << fixed << setprecision(10) << 1.0;
    		return 0;
		}
		d = sqrt(d);
		if(r + r0 < d - eps)
		{
			continue;
		}
		double angl, angr, ang;
		double angm = atan2(y - y0, x - x0);
		if(angm < 0)
		{
			angm += 2 * pi;
		}
		double len = sqrt(d * d - r * r);
		if(len < r0 + eps)
		{
			ang = asin(r / d);
		}
		else
		{
			ang = acos((d * d + r0 * r0 - r * r) / (2 * d * r0));
		}
		angl = angm - ang;
		angr = angm + ang;
		if(angl < 0)
		{
			a.push_back(make_pair(angl + 2 * pi, 1));
			a.push_back(make_pair(2 * pi, -1));
			a.push_back(make_pair(0.0, 1));
			a.push_back(make_pair(angr, -1));
		}
		else if(angr > 2 * pi)
		{
			a.push_back(make_pair(angl, 1));
			a.push_back(make_pair(2 * pi, -1));
			a.push_back(make_pair(0.0, 1));
			a.push_back(make_pair(angr - 2 * pi, -1));
		}
		else
		{
			a.push_back(make_pair(angl, 1));
			a.push_back(make_pair(angr, -1));
		}
	}
	if(a.size() != 0)
	{
	sort(a.begin(), a.end());
	}
	double last = 0;
	int c = 0;
	double ans = 0;
	for(int i = 0; i< a.size(); i++)
	{
		if(c > 0)
		{
			ans += a[i].first - last;
		}
		c += a[i].second;
		last = a[i].first;
	}
	ans /= 2 * pi;
	cout << fixed << setprecision(10) << ans;
    return 0;
}
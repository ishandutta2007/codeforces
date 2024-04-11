#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
double dist(pair <double, double> a, pair <double, double> b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
double dist(pair <double, double> a, pair <double, double> b, pair <double, double> c)
{
	double A = c.second - b.second;
	double B = b.first - c.first;
	double C = -A * b.first - B * b.second;
	return fabs(a.first * A + a.second * B + C) / sqrt(A * A + B * B);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <double, double> > x(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
	}
	double ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			double hmax1 = 0, hmax2 = 0;
			for(int p = 0; p< n; p++)
			{
				double A = x[j].second - x[i].second;
				double B = x[i].first - x[j].first;
				double C = - A * x[i].first - B * x[i].second;
				if(A * x[p].first + B * x[p].second + C > 0)
				{
					hmax1 = max(hmax1, dist(x[p], x[i], x[j]));
				}
				else
				{
					hmax2 = max(hmax2, dist(x[p], x[i], x[j]));
				}
			}
			if(hmax1 == 0 || hmax2 == 0)
			{
				continue;
			}
			ans = max(ans, (hmax1 + hmax2) * dist(x[i], x[j]) / 2);
		}
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}
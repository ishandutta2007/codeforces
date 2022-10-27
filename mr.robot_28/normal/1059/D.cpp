#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
double max(double a, double b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
const double eps = 1e-6;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	bool fl1 = false;
	bool fl2 = false;
	vector <pair <int, int> > x(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
		if(x[i].second < 0)
		{
			fl1 = true;
		}
		if(x[i].second > 0)
		{
			fl2 = true;
		}
	}
	if(fl1 && fl2)
	{
		cout << -1;
		return 0;
	}
	int k1 = 1;
	if(fl1){
		k1 *= -1;
	}
	double l = 0, r = 1e18;
	for(int i = 0; i < n; i++)
	{
		l = max(l, fabs(x[i].second) * 1.0 / 2);
	}
	for(int j = 0; j < 80; j++)
	{
		double midd = (r + l) / 2;
		double minl = -1e18;
		double maxr = 1e18;
		for(int i = 0; i < n; i++)
		{
			minl = max(minl, x[i].first - sqrt(fabs(x[i].second)) * sqrt(2 * midd - k1 * x[i].second));
			maxr = min(maxr, x[i].first + sqrt(fabs(x[i].second)) * sqrt(2 * midd - k1 * x[i].second));
			if(minl > maxr)
			{
				break;
			}
		}
		if(minl <= maxr)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	cout << fixed << setprecision(10) << r;
    return 0;
}
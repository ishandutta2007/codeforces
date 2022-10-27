#include <bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const double eps = 1e-9;
double max(double a,double b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
double min(double a, double b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	double s;
	cin >> n >> s;
	vector <double> x(n), v(n), t(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> v[i] >> t[i];
	}
	double l = 0, r = 1e9;
	while(r - l > eps)
	{
		double midd = (r + l) / 2;
		int l1 = 1e6 + 1, r1 = -1;
		int l2 = 1e6 + 1, r2 = -1;
		for(int i = 0; i < n; i++)
		{
			if(t[i] == 1)
			{
				if(v[i] * midd >= x[i])
				{
					r1 = 1e6, l1 = 0;
				}
				else if((v[i] + s) *  midd >= x[i])
				{
					l1 = min(l1, floor(x[i]));
					r1 = max(r1, floor((midd * (s * s - v[i] * v[i]) + x[i] * v[i]) / s));
				}
			}
			else
			{
				if(v[i] * midd >= 1e6 - x[i])
				{
					l2 = 0, r2 = 1e6;
				}
				else if((v[i] + s) * midd >= 1e6 - x[i])
				{
					r2 = max(r2, floor(x[i]));
					l2 = min(l2, ceil(x[i] - (midd * (s * s - v[i] * v[i]) + (v[i] - s) * 1000000 + (s - v[i]) * x[i]) / s));
				}
			}
		}
		if(l2 <= r1 && r2 >= l2 && r2 >= l1 && l1 <= r1)
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
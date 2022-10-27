#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const double pi = 3.1415926535897932384626433832;
signed main() {
	int n;
	cin >> n;
	vector <int> x(n), y(n), r(n);
	vector <pair <int, int> > mass;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
		mass.push_back({r[i], i});
	}
	vector <vector <int> > g(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= r[i] * r[i] && r[i] > r[j])
			{
				g[i].push_back(j);
			}
		}
	}
	double ans = 0;
	vector <int> col1(n, -1), col2(n, -1);
	sort(mass.begin(), mass.end());
	for(int i = mass.size() - 1; i >= 0; i--)
	{
		if(col1[mass[i].second] == -1)
		{
			ans += mass[i].first * mass[i].first * pi;
			for(int j = 0; j < g[mass[i].second].size(); j++)
			{
				col1[g[mass[i].second][j]] = 1;
			}
		}
		else if(col2[mass[i].second] == -1)
		{
			ans += mass[i].first * mass[i].first * pi;
			for(int j = 0; j < g[mass[i].second].size(); j++)
			{
				col2[g[mass[i].second][j]] = 1;
			}
		}
		else
		{
			ans -= mass[i].first * mass[i].first * pi;
			for(int j = 0; j < g[mass[i].second].size(); j++)
			{
				col1[g[mass[i].second][j]] = -1;
			}
		}
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}
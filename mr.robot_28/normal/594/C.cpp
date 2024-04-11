#include<bits/stdc++.h>
 
using namespace std;
const double eps = 1e-9;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <pair <double, double> > x(n);
	vector <pair <double, double> > y(n);
	for(int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x[i] = {(x1 + x2) * 1.0 / 2, (y2 + y1) * 1.0 / 2};
		y[i] = {x[i].second, x[i].first};
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long long ans = 1e18;
	for(int i = 0; i <= k; i++)
	{
		for(int j = max(i, n - k - 1); j < n; j++)
		{
			vector <double> un;
			for(int it = 0; it < n; it++)
			{
				if(y[it].second >= x[i].first && y[it].second <= x[j].first)
				{
					un.push_back(y[it].first);
				}
			}
			if(un.size() < (n - k))
			{
				continue;
			}
			for(int it = 0; it <= un.size() - (n - k); it++)
			{
				int a = (x[j].first - x[i].first + 0.5);
				int b = (un[it + (n - k) - 1] - un[it] + 0.5);
				if(b == 0)
				{
					b = 1;
				}
				if(a == 0)
				{
					a = 1;
				}
				ans = min(ans, a * b);
			}
		}
	}
	if(ans == 0)
	{
		ans = 1;
	}
	cout << ans;
	return 0;
}
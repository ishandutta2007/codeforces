#include<bits/stdc++.h>

using namespace std;


signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n, u;
	cin >> n >> u;
	vector <int> e(n);
	for(int i = 0; i < n; i++)
	{
		cin >> e[i];
	}
	double ans = 0;
	bool fl = 0;
	for(int i = 0; i < n - 2; i++)
	{
		if(e[i + 2] - e[i] > u)
		{
			continue;
		}
		fl = 1;
		int l = i + 2;
		int r = n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(e[midd] - e[i] <= u)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		ans = max(ans, 1.0 * (e[l] - e[i + 1]) / (e[l] - e[i]));
	}
	if(!fl)
	{
		cout << -1;
		return 0;
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		long long k;
		cin >> n >> k;
		vector <int>a(n);
		int dmax = -1e9;
		int dmin = 1e9;
		k--;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			dmin = min(dmin, a[i]);
			dmax = max(dmax, a[i]);
		}
		for(int i = 0; i < n; i++)
		{
			a[i] = dmax - a[i];
		}
		if(k % 2 == 1)
		{
			for(int i = 0; i < n; i++)
			{
				a[i] = (dmax - dmin) - a[i];
			}
		}
		for(int i = 0; i< n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
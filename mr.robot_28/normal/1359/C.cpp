#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		double h, c, t;
		cin >> h >> c >> t;
		int l = 1, r = 1e9;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			double temp = (midd * h + (midd - 1) * c) / (2 * midd - 1);
			if(temp >= t)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		double ans = fabs(t - (h + c) / 2);
		int anst = 2;
		double temp1 = (l * h + (l - 1) * c) / (2 * l - 1);
		if(fabs(t - temp1) < ans)
		{
			ans = fabs(t - temp1);
			anst = l * 2- 1;
		}
		temp1 = (r * h + (r - 1) * c) / (2 * r - 1);
		if(fabs(t - temp1) < ans)
		{
			ans = fabs(t - temp1);
			anst = r * 2 - 1;
		}
		cout << anst << "\n";
	}
    return 0;
}
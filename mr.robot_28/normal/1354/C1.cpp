#include <bits/stdc++.h>
 
using namespace std;
const double pi = 3.1415926535;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		double fi = 90 * (n - 1) * 1.0 / n;
		fi = fi * pi / 180;
		double a = sin(fi) / cos(fi);
		cout << fixed << setprecision(10) << a << "\n";
	}
    return 0;
}
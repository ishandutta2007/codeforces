#include <bits/stdc++.h> 
#include<iomanip>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, x, y, d;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> x >> y >> d;
		if(abs(x - y) % d != 0 && ((y - 1) % d != 0) && ((n - y) % d != 0))
		{
			cout << -1 << endl;
		}
		else
		{
			int max = 1e9;
			if(abs(x - y) % d == 0 && abs(x - y) / d < max)
			{
				max = abs(x - y) / d;
			}
			if((x - 1) / d + ((x - 1) % d != 0) + (y - 1) / d < max && (y - 1) % d == 0) 
			{
				max = (x - 1) / d + ((x - 1) % d != 0) + (y - 1) / d;
			}
			if(abs(n - y) / d + (n - x ) / d + ((n - x) % d != 0) < max && (n - y) % d == 0)
			{
				max = abs(n - y) / d + (n - x ) / d + ((n - x) % d != 0);
			}
			cout << max << endl;
		}
	}
	return 0;
}
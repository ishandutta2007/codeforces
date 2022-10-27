#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n, d, e;
	cin >> n >> d >> e;
	int min = 1e9;
	for(int i = 0; i <= n; i += e * 5)
	{
		if((n - i) % d < min)
		{
			min = (n - i) % d;
		}
	}
	cout << min;
	return 0;
}
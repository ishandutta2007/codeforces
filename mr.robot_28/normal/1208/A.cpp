# include <bits/stdc++.h>
using namespace std;
signed main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a, b, n;
		cin >> a >> b >> n;
		if(n % 3 == 2)
		{
			cout << (a^b) << "\n";
		}
		else if(n % 3 == 0)
		{
			cout << a << "\n";
		}
		else
		{
			cout << b << "\n";
		}
	}
	return 0;
}
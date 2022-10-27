#include<bits/stdc++.h>
 
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if((y - x) % (a + b) == 0)
		{
			cout << (y - x) / (a + b) << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
	return 0;
}
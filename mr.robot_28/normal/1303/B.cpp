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
		int n, g, b;
		cin >> n >> g >> b;
		int left = (n + 1) / 2;
		int right = n - left;
		int k = (left + g - 1) / g;
		if(right <= (k - 1) * b)
		{
			cout << (k - 1) * (b) + left << "\n"; 
		}
		else
		{
			cout <<  n << "\n";
		}
	}
	return 0;
}
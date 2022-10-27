#include<bits/stdc++.h>
 
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
		int n, x;
		cin >> n >> x;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		int ans = 1e9;
		for(int i = 0; i  < n; i++)
		{
			if(A[i] > x)
			{
				ans = min(ans, 2);
			}
			else if(x % A[i] == 0)
			{
				ans = min(ans, x / A[i]);
			}
			else
			{
				ans = min(ans, x / A[i] + 1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
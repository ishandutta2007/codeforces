#include <bits/stdc++.h>
 
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
		int n;
		cin >> n;
		vector <int> A(2 * n);
		for(int i = 0; i < 2 * n; i++)
		{
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int ans = 1e9;
		for(int i = n / 2; i < 2 * n; i++)
		{
			int j = n - 1;
			if(j >= i)
			{
				j++;
			}
			ans = min(ans, abs(A[i] - A[j]));
		}
		cout << ans << "\n";
	}
	return 0;
}
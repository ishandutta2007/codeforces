#include<bits/stdc++.h>
 
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int ans = 0;
		if(k % n != 0)
		{
			ans = 2;
		}
		vector <vector <int> > A(n, vector <int> (n, 0));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < min(n, k); j++)
			{
				A[(i + j) % n][j] = 1;
			}
			k -= min(n, k);
		}
		cout << ans << "\n";
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << A[i][j];
			}
			cout << "\n";
		}
	}
    return 0;
}
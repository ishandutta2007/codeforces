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
		int n;
		cin >> n;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		int bal = -1e9;
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			bal = max(bal, A[i]);
			ans = max(ans, bal - A[i]);
		}
		if(ans == 0)
		{
			cout << 0 << "\n";
			continue;
		}
		int k = log2(ans);
		cout << k + 1 << "\n";
	}
    return 0;
}
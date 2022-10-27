#include <bits/stdc++.h>

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
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long sum = 0;
		for(int i = 1; i < n; i++)
		{
			sum += max(0, a[i - 1] - a[i]);
		}
		cout << sum << "\n";
	}
	return 0;
}
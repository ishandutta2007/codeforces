#include<bits/stdc++.h>
using namespace std;


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			sum += a;
		}
		cout << min(sum, m) << "\n";
	}
	return 0;
}
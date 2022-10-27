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
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for(int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
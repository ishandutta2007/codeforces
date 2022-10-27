#include<bits/stdc++.h>
using namespace std;
//#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			a[i][j] ^= t;
			cnt += a[i][j];
		}
	}
	for(int i = 0;i + 1 < n; i++)
	{
		int c = 0;
		for(int j = 0; j < m; j++)
		{
			c += a[i][j];
			a[i + 1][j] ^= a[i][j];
		}
		if(c % 2 == 1)
		{
			cout << "No";
			return 0;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(a[n - 1][i] == 1)
		{
			cout << "No";
			return 0;
		}
	}
	 cout << "Yes";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		map <pair <int, int>, int> mp;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[{a[i], i % 2}]++;
		}
		bool fl = 1;
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++)
		{
			if(mp[{a[i], i % 2}] == 0)
			{
				fl = 0;
			}
			mp[{a[i], i % 2}]--;
		}
		if(fl)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}	
	return 0;
}
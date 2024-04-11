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
		bool flag = true;
		vector <bool> used(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(used[(n + i + a[i] % n) % n])
			{
				flag = false;
			}
			used[(n + i + a[i] % n) % n] = true;	
		}
		if(flag)
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
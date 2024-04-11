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
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		int imax = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] > a[imax])
			{
				imax = i;
			}
		}
		vector <int> ans;
		ans.push_back(a[imax]);
		vector <bool> used(n, false);
		used[imax] = 1;
		int f = a[imax];
		for(int it = 1; it < n; it++)
		{
			imax = -1;
			for(int j = 0; j < n; j++)
			{
				if(!used[j] && (imax == -1 || __gcd(f, a[j]) > __gcd(f, a[imax])))
				{
					imax = j;
				}
			}
			ans.push_back(a[imax]);
			used[imax] = 1;
			f = __gcd(f, a[imax]);
		}
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
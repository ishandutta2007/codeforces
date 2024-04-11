#include<bits/stdc++.h>
using namespace std;

signed main()
{
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
		vector <int> ans;
		for(int i = 0; i < n; i++)
		{
			if(i < n - 1 && a[i] == a[i + 1])
			{
				ans.push_back(a[i]);
				ans.push_back(a[i + 1]);
				i++;
			}
			else if(a[i] == 0)
			{
				ans.push_back(0);
			}
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
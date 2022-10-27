#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> q(n);
		for(int i = 0; i < n; i++)
		{
			cin >> q[i];
		}
		vector <bool> used(n + 1);
		int st = 1;
		vector <int> ans;
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			if(i == 0 || q[i] > q[i - 1])
			{
				ans.push_back(q[i]);
				used[q[i]] = true;
			}
			else
			{
				while(used[st])
				{
					st++;
				}
				ans.push_back(st);
				if(st > q[i])
				{
					flag = false;
					break;
				}
				used[st] = true;
			}
		}
		if(!flag)
		{
			cout << -1;
		}
		else
		{
			for(int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
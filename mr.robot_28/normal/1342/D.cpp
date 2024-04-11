#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	vector <int> c(k);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < k; i++)
	{
		cin >> c[i];
	}
	vector <vector <int> > ans;
	for(int i = n - 1; i >= 0; i--)
	{
		if(ans.size() == 0)
		{
			ans.push_back({a[i] + 1});
		}
		else
		{
			int l = -1, r = ans.size();
			while(r - l > 1){
				int midd = (r + l) / 2;
				if(c[a[i]] <= ans[midd].size())
				{
					l = midd;
				} 
				else
				{
					r = midd;
				}
			}
			if(r == ans.size())
			{
				ans.push_back({a[i] + 1});
			}
			else
			{
				ans[r].push_back(a[i] + 1);
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i =0; i < ans.size(); i++)
	{
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
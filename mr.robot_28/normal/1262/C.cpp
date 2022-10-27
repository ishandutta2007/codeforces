#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		k--;
		vector <pair <int, int> > ans;
		for(int i = 0; i < 2 * k; i += 2)
		{
				if(s[i] != '(')
				{
					int j = i + 1;
					for(; j < s.size(); j++)
					{
						if(s[j] == '('){
							break;
						}
					}
					for(int t = 1; t <= (j - i + 1) / 2; t++)
					{
						swap(s[i + t - 1], s[j - t + 1]);
					}
					ans.push_back({i + 1, j + 1});
				}
				if(s[i + 1] != ')')
				{
					int j = i + 2;
					for(; j < s.size(); j++)
					{
						if(s[j] == ')')
						{
							break;
						}
					}
					for(int t = 1; t <= (j - i) / 2; t++)
					{
						swap(s[i + t], s[j - t + 1]);
					}
					ans.push_back({i + 2, j + 1});
				}
		}
		for(int i = 2 * k; i < (s.size() - 2 * k) / 2 + 2 * k; i ++)
		{
			if(s[i] != '(')
			{
				int j = i + 1;
				for(; j < s.size(); j++)
				{
					if(s[j] == '('){
						break;
					}
				}
				for(int t = 1; t <= (j - i + 1) / 2; t++)
				{
					swap(s[i + t - 1], s[j - t + 1]);
				}
				ans.push_back({i + 1, j + 1});
			}
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
	return 0;
}
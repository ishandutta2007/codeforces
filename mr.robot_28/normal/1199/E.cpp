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
		int n, m;
		cin >> n >> m;
		vector <int> ans;
		vector <bool> used(3 * n, false);
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			if(!used[x - 1] && !used[y - 1])
			{
				used[x - 1] = true;
				used[y - 1] = true;
				ans.push_back(i + 1);
			}
		}
		if(ans.size() >= n)
		{
			cout << "Matching\n";
			for(int i = 0; i < n; i++)
			{
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else
		{
			cout << "IndSet\n";
			int cnt = 0;
			for(int i = 0; i < 3 * n; i++)
			{
				if(!used[i])
				{
					cout << i + 1 << " ";
					cnt++;
				}
				if(cnt == n)
				{
					break;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	vector <vector <int> > ans(n);
	stack <int> st1, st0;
	for(int i = 0; i < n; i++)
	{
		st1.push(i);
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			if(st1.size() == 0)
			{
				cout << -1;
				return 0;
			}
			ans[st1.top()].push_back(i + 1);
			st0.push(st1.top());
			st1.pop();
		}
		else
		{
			if(st0.size() == 0)
			{
				cout << -1;
				return 0;
			}
			ans[st0.top()].push_back(i + 1);
			st1.push(st0.top());
			st0.pop();
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(ans[i].size() != 0)
		{
			cnt++;
			if(s[ans[i].back() - 1] == '1')
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt << "\n";
	for(int i = 0;  i < n; i++)
	{
		if(ans[i].size() == 0)
		{
			continue;
		}
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

signed main() {	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	vector <int> tim(n);
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		tim[i] = 3600 * ((s[0] - '0') * 10 + (s[1] - '0')) + 60 * ((s[3] - '0') * 10 + (s[4] - '0')) + ((s[6] - '0') * 10 + (s[7] - '0'));
	}
	vector <int> ans(n);
	int cnt = 0;
	vector <bool> used(n);
	bool flag = 0;
	for(int i = 0; i< n;i++)
	{
		int c = 0;
		for(int j = 0;j < i; j++)
		{
			if(tim[j] + t - 1 >= tim[i] && !used[ans[j]])
			{
				used[ans[j]] = 1;
				c++;
			}
		}
		if(c >= m - 1)
		{
			flag = 1;
		}
		if(c < m)
		{
			ans[i] = cnt + 1;
			cnt++;
		}
		else
		{
			ans[i] = ans[i - 1];
		}
		for(int j = 0; j < i;j++)
		{
			used[ans[j]] = 0;
		}
	}
	if(flag)
	{
		cout << cnt << "\n";
		for(int i = 0; i < n; i++)
		{
			cout << ans[i] << "\n";
		}
	}
	else
	{
		cout << "No solution";
	}
    return 0;
}
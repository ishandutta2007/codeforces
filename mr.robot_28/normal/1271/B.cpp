#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	string s1;
	s1 = s;
	vector <int> ans1;
	vector <int> ans;
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] != 'W')
		{
			if(s[i + 1] == 'B'){
				s[i + 1] = 'W';
			}
			else
			{
				s[i + 1] = 'B';
			}
			ans.push_back(i + 1);
			s[i] = 'W';
		}
		if(s1[i] != 'B')
		{
			if(s1[i + 1] == 'W'){
				s1[i + 1] = 'B';
			}
			else
			{
				s1[i + 1] = 'W';
			}
			ans1.push_back(i + 1);
			s1[i] = 'B';
		}
	}
	if(s[n - 2] != s[n - 1] && s1[n - 1] != s1[n - 2])
	{
		cout << -1;
	}
	else if(s[n - 2] == s[n - 1])
	{
		cout << ans.size() << "\n";
		for(int i = 0;  i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
	}
	else
	{
		cout << ans1.size() << "\n";
		for(int i = 0; i < ans1.size(); i++)
		{
			cout << ans1[i] << " ";
		}
	}
	return 0;
}
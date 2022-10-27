#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	int n;
	cin >> n;
	bool flag = 0;
	vector <bool> used(26, true), used1(26);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		char t;
		string s;
		cin >> t >> s;
		if(flag && (t == '!' || t == '?'))
		{
			cnt++;
		}
		if(t == '?')
		{
			used[s[0] - 'a'] = 0;
		}
		else if(t == '.')
		{
			for(int j = 0; j < s.size(); j++)
			{
				used[s[j] - 'a'] = 0;
			}
		}
		else
		{
			for(int j = 0; j < 26; j++)
			{
				used1[j] = 0;
			}
			for(int j = 0; j < s.size(); j++)
			{
				used1[s[j] - 'a'] = 1;
			}
			for(int j = 0; j < 26; j++)
			{
				if(used[j])
				{
					used[j] = used1[j];
				}
			}
		}
		int cnt1 = 0;
		for(int j = 0; j < 26; j++)
		{
			if(used[j])
			{
				cnt1++;
			}
		}
		if(cnt1 == 1)
		{
			flag = 1;
		}
	}
	if(cnt == 0)
	{
		cout << 0;
		return 0;
	}
	cout << cnt - 1;
	return 0;
}
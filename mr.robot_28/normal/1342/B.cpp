#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '0')
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		if(cnt1 * cnt2 == 0)
		{
			cout << s << "\n";
			continue;
		}
		string ans = "";
		for(int i = 0; i < s.size(); i++)
		{
			ans += s[i];
			if(i != s.size() - 1 && s[i + 1] == s[i])
			{
				if(s[i] == '0')
				{
					ans += '1';
				}
				else
				{
					ans += '0';
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
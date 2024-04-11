#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int bal = 0;
		int cnt1 = 0;
		int can = 0;
		for(int j = i; j < s.size(); j++)
		{
			if(s[j] == ')' && bal == 0 && cnt1 == 0)
			{
				break;
			}
			if(s[j] == ')')
			{
				if(bal > 0)
				{
					bal--;
				}
				else
				{
					cnt1--;
				}
			}
			else if(s[j] == '(')
			{
				bal++;
			}
			else
			{
					cnt1++;
			}
			if(cnt1 >= bal && (j - i) % 2 == 1)
			{
				ans++;
			}
			while(cnt1 > bal)
			{
				cnt1--;
				bal++;
			}
		}
	}
	cout << ans;
    return 0;
}
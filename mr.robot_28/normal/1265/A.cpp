#include <bits/stdc++.h>
using namespace std;
vector <int> pred1, pred2;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		bool flag = true;
		for(int i = 0; i < s.size(); i++)
		{
			if(i < s.size() - 1 && s[i] == s[i + 1] && s[i] != '?')
			{
				flag = false;
				break;
			}
			else if(s[i] == '?')
			{
				set <int> t;
				if(i != 0)
				{
					t.insert(s[i - 1] - 'a');
				}
				if(i < s.size() - 1 && s[i + 1] != '?')
				{
					t.insert(s[i + 1] - 'a');
				}
				for(int j = 0; j < 3; j++)
				{
					if(t.find(j) == t.end())
					{
						char e = j + 'a';
						s[i] = e;
						break;
					}
				}
			}
		}
		if(flag)
		{
			cout << s << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
    return 0;
}
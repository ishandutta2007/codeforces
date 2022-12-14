#include <bits/stdc++.h>
using namespace std;
map<string, int> mp1, mp2;
int test, n; 
string s[111111], t;
bool flag;
int main()
{
	ios::sync_with_stdio(false);
	cin >> test;
	while(test--)
	{
		mp1.clear(); mp2.clear(); flag = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			if (mp1.find(s[i]) == mp1.end()) mp1[s[i]] = i;
			mp2[s[i]] = i;
			if (s[i].size() == 1 || (s[i].size() == 2 && s[i][0] == s[i][1]) || (s[i].size() == 3 && s[i][0] == s[i][2])) flag = 1;
		}
		if (flag) printf("YES\n");
		else 
		{
			for (int i = 1; i <= n; i++)
			{
				if (s[i].size() == 2) 
				{
					t = s[i].substr(1) + s[i].substr(0, 1);
					if (mp1.find(t) != mp1.end())
					{
						flag = 1;
						break;
					}
				}
				else
				{
					t = s[i].substr(2) + s[i].substr(1, 1) + s[i].substr(0, 1);
					//cout << t << endl;
					if (mp1.find(t) != mp1.end())
					{
						flag = 1;
						break;
					}
					t = s[i].substr(1, 1) + s[i].substr(0, 1);
					//cout << t << endl;
					if (mp2.find(t) != mp2.end() && mp2[t] > i)
					{
						flag = 1;
						break;
					}
					t = s[i].substr(2) + s[i].substr(1, 1);
					//cout << t << endl;
					if (mp1.find(t) != mp1.end() && mp1[t] < i)
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
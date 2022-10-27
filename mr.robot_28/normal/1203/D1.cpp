#include<bits/stdc++.h>
using namespace std;
signed main()
{
	string s, t;
	cin >> s >> t;
	vector <int> pref(t.size());
	vector <int> post(t.size());
	int j = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(t[j] == s[i])
		{
			pref[j] = i;
			j++;
		}
		if(j == t.size())
		{
			break;
		}
	}
	j = t.size() - 1;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(t[j] == s[i])
		{
			post[j] = i;
			j--;
		}
		if(j == -1)
		{
			break;
		}
	}
	int MAX = post[0];
	for(int i = 0; i < t.size() - 1; i++)
	{
		MAX = max(MAX, post[i + 1] - pref[i] - 1);
	}
	MAX = max(MAX, int(s.size() - 1 - pref[t.size() - 1]));
	cout << MAX;
	return 0;
}
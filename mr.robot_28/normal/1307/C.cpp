#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	string s;
	cin >> s;
	vector <vector <int> > t(26, vector <int> (26));
	vector <int> cnt(26);
	for(int i =  s.size() - 1; i >= 0; i--)
	{
		for(int p = 0; p < 26; p++)
		{
			t[s[i] - 'a'][p] += cnt[p];
		}
		cnt[s[i] - 'a']++;
	}
	int ans = 0;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			ans = max(ans, t[i][j]);
		}
	}
	for(int i = 0; i < 26; i++)
	{
		ans = max(ans, cnt[i]);
	}
	cout << ans;
    return 0;
}
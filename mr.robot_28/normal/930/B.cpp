#include<bits/stdc++.h>
 
using namespace std;
#define double long double
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	vector <vector <int> > pos(26);
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
		pos[s[i] - 'a'].push_back(i);
	}
	double ans = 0;
	double n1 = s.size();
	for(int i = 0; i < 26; i++)
	{
		int cnt1 = 0;
		for(int j = 1; j < n; j++)
		{
			vector <int> count(26);
			int cnt = 0;
			for(int k = 0; k < pos[i].size(); k++)
			{
				count[s[(pos[i][k] + j) % n] - 'a']++;
			}
			for(int p = 0; p < 26; p++)
			{
				if(count[p] == 1)
				{
					cnt++;
				}
			}
			cnt1 = max(cnt1, cnt);
		}
		ans += cnt1 / n1;
	}
	cout << fixed << setprecision(7) << ans;
	return 0;
}
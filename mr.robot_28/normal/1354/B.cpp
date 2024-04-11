#include <bits/stdc++.h>
 
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		vector <int> p(4, -1);
		int ans = s.size() + 1;
		for(int i = 0; i < s.size(); i++)
		{
			p[s[i] - '0'] = i;
			int last = i;
			for(int j = 1; j <= 3; j++)
			{
				last = min(last, p[j]);
			}
			if(last != -1)
			{
				ans = min(ans, i - last + 1);
			}
		}
		if(ans == s.size() + 1)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << ans << "\n";
		}
	}
    return 0;
}
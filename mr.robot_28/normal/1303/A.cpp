#include<bits/stdc++.h>
 
using namespace std;
#define double long double
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
		int l = s.size(), r = 0, cnt = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '1')
			{
				l = min(l, i);
				r = i;
				cnt++;
			}
		}
		if(l <= r)
		{
			cout << r - l + 1 - cnt << "\n";
		}
		else
		{
			cout << 0 <<"\n";
		}
	}
	return 0;
}
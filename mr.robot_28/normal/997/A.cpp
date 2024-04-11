#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '0' && (i == 0 || s[i - 1] == '1'))
		{
			cnt++;
		}
	}
	if(cnt == 0)
	{
		cout << 0;
		return 0;
	}
	cout << min(x, y) * (cnt - 1) + y;
	return 0; 
}
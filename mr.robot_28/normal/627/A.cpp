#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int s, x;
	cin >> s >> x;
	if(s < x)
	{
		cout << 0;
		return 0;
	}
	int x1 = x;
	int ans = 0;
	vector <bool> used(60, false);
	int cnt = 0;
	while(x1 > 0)
	{
		if(x1 % 2)
		{
			used[cnt] = true;
		}
		cnt++;
		ans += (x1 % 2);
		x1 = x1 / 2;
	}
	ans = pow(2, ans) - 2;
	s = s - x;
	cnt = 0;
	if(s > 0)
	{
		ans += 2;
	}
	while(s > 0)
	{
		if(s % 2 == 1)
		{
			if(cnt == 0 || used[cnt - 1])
			{
				cout << 0;
				return 0;
			}
		}
		cnt++;
		s = s / 2;
	}
	cout << ans;
    return 0;
}
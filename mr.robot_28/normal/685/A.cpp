#include<bits/stdc++.h>
 
using namespace std;


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int n1 = n - 1, m1 = m - 1;
	int cnt1 = 1, cnt2 = 1;
	while(n1 > 6)
	{
		cnt1++;
		n1 = n1 / 7;
	}
	while(m1 > 6)
	{
		cnt2++;
		m1 = m1 / 7;
	}
	if(cnt1 + cnt2 > 7)
	{
		cout << 0;
	}
	else
	{
		int allc = cnt1 + cnt2;
		int t1 = pow(7, m1);
		vector <int> POWER(allc + 1);
		POWER[0] = 1;
		for(int i = 1; i <= allc; i++)
		{
			POWER[i] = POWER[i - 1] * 7;
		}
		vector <bool> used(7);
		int ans = 0;
		for(int mask1 = 0; mask1 < n; mask1++)
		{
			for(int mask2 = 0; mask2 < m; mask2++)
			{
				for(int i = 0; i < 7; i++)
				{
					used[i] = 0;
				}
				bool flag = 1;
				for(int i = 0; i < cnt1; i++)
				{
					if(used[mask1 / POWER[i] % 7])
					{
						flag = 0;
					}
					used[mask1 / POWER[i] % 7] = 1;
				}
				for(int i = 0; i < cnt2; i++)
				{
					if(used[mask2 / POWER[i] % 7])
					{
						flag = 0;
					}
					used[mask2 / POWER[i] % 7] = 1;
				}
				if(flag)
				{
					ans++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
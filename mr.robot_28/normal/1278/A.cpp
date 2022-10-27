#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string p, h;
		cin >> p >> h;
		vector <int> cnt(26, 0);
		for(int i = 0; i < p.size(); i++)
		{
			cnt[p[i] -  'a']--;
		}
		int j = 0;
		bool flag = false;
		for(int i = 0; i < h.size(); i++)
		{
			cnt[h[i] - 'a']++;
			while(cnt[h[i] - 'a'] > 0)
			{
				cnt[h[j] - 'a']--;
				j++;
			}
			if(i - j + 1 == p.size())
			{
				flag = true;
			}
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
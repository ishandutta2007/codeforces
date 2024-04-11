#include <bits/stdc++.h>
                  
using namespace std;

signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	set <int> st1, st2;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			cnt1++;
		}
		if(t[i] == '0')
		{
			cnt2++;
		}
		if(s[i] != t[i])
		{
			if(s[i] == '0')
			{
				st1.insert(i);
			}
			else
			{
				st2.insert(i);
			}
		}
	}
	if(cnt1 != cnt2)
	{
		cout << -1;
		return 0;
	}
	int ans = 0;
	while(st1.size() != 0 || st2.size() != 0)
	{
		ans++;
		int ind = 0;
		if(st1.size() != 0 && (st2.size() == 0 || *st2.begin() > *st1.begin())){
			while(st1.size() != 0)
			{
				set <int> :: iterator it, it1;
				it = st1.lower_bound(ind);
				if(it == st1.end())
				{
					break;
				}
				it1 = st2.lower_bound(*it);
				if(it1 == st2.end())
				{
					break;
				}
				ind = *it1 + 1;
				st1.erase(it);
				st2.erase(it1);
			}
		}
		else
		{
			while(st2.size() != 0)
			{
				set <int> :: iterator it, it1;
				it = st2.lower_bound(ind);
				if(it == st2.end())
				{
					break;
				}
				it1 = st1.lower_bound(*it);
				if(it1 == st1.end())
				{
					break;
				}
				ind = *it1 + 1;
				st2.erase(it);
				st1.erase(it1);
			}
		}
	}
	cout << ans;
	return 0;
}
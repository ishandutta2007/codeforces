/**
 *    author:  Mohamed.Abo_Okail
 *    created: 14/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	ll t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		vector <ll> v(n);
		set <ll> st;
		map <ll, ll> mp, mpp;
		ll ans = 1e9;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			st.insert(v[i]);
			mp[v[i]]++;
			if(mp[v[i]] >= 2)
			{
				ans = min(ans, (i - mpp[v[i]]));
				mp[v[i]]--;
			}
			mpp[v[i]] = i;
		}
		
		if(n == st.size())
			cout << -1 << endl;
		else
			cout << (ans + 1) << endl;
		
	}
}
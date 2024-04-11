/**
 *    author:  Mohamed.Abo_Okail
 *    created: 12/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n >> k;
		vector <ll> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		ll cnt1 = v[n - 1] - k;
		ll cnt2 = v[0] + k;
		cout << ((cnt1 > cnt2) ? -1 : max(cnt1, cnt2)) << endl;
	}
}
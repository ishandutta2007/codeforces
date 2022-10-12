/**
 *    author:  Mohamed.Abo_Okail
 *    created: 16/11/2019
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
		vector <ll> a(n), b(n);
		set <ll> st;
		int inx1 = 0, inx2 = 0;
		bool bb = 1;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++)
		{
			if(a[i] != b[i])
			{
				inx1 = i;
				break;
			}
		}
		for (int i = (n - 1); i >= 0; i--)
		{
			if(a[i] != b[i])
			{
				inx2 = i;
				break;
			}
		}
		for (int i = inx1; i <= inx2; i++)
		{
			st.insert(b[i] - a[i]);
			if(b[i] < a[i])
				bb = 0;
		}
 
		if(st.size() <= 1 && bb)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
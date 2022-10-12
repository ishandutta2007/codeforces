/**
 *    author:  Mohamed.Abo_Okail
 *    created: 04/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	ll t; cin >> t;
	while(t--)
	{
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		ll ans = a * n;
		if(ans > s)
			ans = (s / n) * n;
		ans += b;
		cout << ((ans >= s) ? "YES" : "NO") << endl;
	}

}
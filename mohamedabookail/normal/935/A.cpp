/**
 *    author:  Mohamed.Abo_Okail
 *    created: 05/11/2019
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
	
	ll n; cin >> n;
	ll ans = 0;
	for (int i = 1; i <= (n / 2); i++)
	{
		if((n - i) % i == 0) ans++;
	}

	cout << ans << endl;
}
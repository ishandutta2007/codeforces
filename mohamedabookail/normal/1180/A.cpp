/**
 *    author:  Mohamed.Abo_Okail
 *    created: 31/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans += (i - 1) * 4;
	}
	cout << ans << endl;
}
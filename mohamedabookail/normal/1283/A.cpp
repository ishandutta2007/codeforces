/**
 *    author:  Mohamed.Abo_Okail
 *    created: 28/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		cout << ((23 - n) * 60) + (60 - m) << endl;
	}
}
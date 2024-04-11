/**
 *    author:  Mohamed.Abo_Okail
 *    created: 02/01/2020
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
	    ll n, a, b;
	    cin >> n >> a >> b;
		cout << min((n * a), (n / 2 * b + n % 2 * a)) << endl;
	}
}
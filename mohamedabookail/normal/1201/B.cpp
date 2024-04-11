/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	ll mx = -1, sum = 0;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		sum += a;
		mx = max(mx, a);
	}
	if(!(sum % 2) && sum - mx >= mx) {
		cout << "YES" << endl;
	} 
	else {
		cout << "NO" << endl;
	}
}
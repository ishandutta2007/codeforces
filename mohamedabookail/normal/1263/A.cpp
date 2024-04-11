/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O1/2O2O
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
		ll ar[3];
		cin >> ar[0] >> ar[1] >> ar[2];
		sort(ar, ar + 3);
		if(ar[2] >= (ar[0] + ar[1])) {
			cout << ar[0] + ar[1] << endl;
		}
		else {
			cout << (ar[0] + ar[1] + ar[2]) / 2 << endl;
		}
	}
}
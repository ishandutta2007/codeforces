/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll ar[3], n;
		cin >> ar[0] >> ar[1] >> ar[2] >> n;
		sort(ar, ar + 3);
		ll nemo = (ar[0] + ar[1]);
		ll cnt = ar[2] * 2;
		ll ans = cnt - nemo;
		n -= ans;
		if(n < 0) {
			cout << "NO" << endl;
		}
		else if(n % 3 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
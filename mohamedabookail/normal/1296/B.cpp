/**
 *    author:  Mohamed Abo_Okail
 *    created: O4/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll nemo = ((n / 10) * 10);
		ll cnt = ((n / 10) + (n % 10));
		while(cnt > 9) {
			nemo += ((cnt / 10) * 10);
			cnt = ((cnt / 10) + (cnt % 10));
		}
		cout << (cnt ? nemo + cnt : nemo) << o_o;
	}
}
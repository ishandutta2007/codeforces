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
		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo % 2) {
				a += oo;
				b++;
			}
		}
		if(a % 2) cout << "YES";
		else if(b != n && b != 0) cout << "YES";
		else cout << "NO";
		cout << o_o;
	}
}
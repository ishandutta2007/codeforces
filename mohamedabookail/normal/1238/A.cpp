/**
 *    author:  Mohamed Abo_Okail
 *    created: 29/O1/2O2O
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
		ll a, b; cin >> a >> b;
		if(a - 1 == b) { cout << "NO" << o_o; }
		else { cout << "YES" << o_o; }
	}
}
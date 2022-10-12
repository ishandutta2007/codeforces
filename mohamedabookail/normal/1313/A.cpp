/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int ar[3]; cin >> ar[0] >> ar[1] >> ar[2];
		int ans = 0; sort(ar, ar + 3);
		if(ar[0]) ans++, ar[0]--;
		if(ar[1]) ans++, ar[1]--;
		if(ar[2]) ans++, ar[2]--;
		if(ar[2] && ar[1]) ans++, ar[2]--, ar[1]--;
		if(ar[2] && ar[0]) ans++, ar[2]--, ar[0]--;
		if(ar[1] && ar[0]) ans++, ar[1]--, ar[0]--;
		if(ar[0] && ar[1] && ar[2]) ans++;
		cout << ans << o_o;
	}
}
/**
*    author:  Mohamed Abo_Okail
*    created: O2/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

int main() {
	std::ios_base::sync_with_stdio(0);
	ll a, b, n; cin >> a >> b >> n;
	bool bol = 0;
	while(n) {
		if(bol) {
			n -= _gcd(b, n);
		}
		else {
			n -= _gcd(a, n);
		}
		if(!n) {
			cout << bol << endl;
		}
		bol = !bol;
	}
}
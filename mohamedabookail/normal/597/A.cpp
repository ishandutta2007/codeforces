/**
 *    author:  Mohamed Abo_Okail
 *    created: O9/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

ll _solve(ll a, ll b, ll k) {
	return b / k - max(a - 1, 0ll) / k;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll k, a, b; cin >> k >> a >> b;
	if(a >= 0 || b <= 0) {
		if(b <= 0) {
			a = abs(a);
			b = abs(b);
			if(a > b) swap(a, b);
		}
		cout << _solve(a, b, k) + (!a ? 1 : 0) << endl;
	}
	else {
		cout << _solve(1, abs(a), k) + _solve(1, b, k) + 1 << endl;
	}
}
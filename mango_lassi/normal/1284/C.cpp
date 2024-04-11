#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll m;
	cin >> n >> m;

	// Q: In how many is [a, a+k) framed?
	// A: In (n-k+1) * (n-k)! * k!
	// 	choose elements inside, then permute elements
	// There are n-k+1 segments of length k

	vector<ll> fact(n+1, 1);
	for (int i = 2; i <= n; ++i) fact[i] = (ll)fact[i-1] * i % m;

	ll res = 0;
	for (int k = 1; k <= n; ++k) {
		ll cou = n-k+1;
		ll vals = cou;
		ll mult = fact[n-k] * fact[k] % m;
		
		ll add = (cou * vals) % m * mult;

		res = (res + add) % m;
	}
	cout << res << '\n';
}
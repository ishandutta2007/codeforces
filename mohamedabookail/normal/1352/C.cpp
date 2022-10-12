/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O5/2O2O
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
int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		int flag = k / (n - 1), mod = k % (n - 1);
		cout << n * flag + mod - (!mod ? 1 : 0) << endl;
	}
}
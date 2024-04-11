/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O2/2O2O
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
	int ar[3], d;
	cin >> ar[0] >> ar[1] >> ar[2] >> d;
	sort(ar, ar + 3);
	cout << max(d - (ar[1] - ar[0]), 0) + max(d - (ar[2] - ar[1]), 0) << o_o;
}
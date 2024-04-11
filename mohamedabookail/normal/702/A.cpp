/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O2/2O2O
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
	int n; cin >> n;
	vector < ll > v(n);
	int mx = -1, cnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		if(v[i] > v[i - 1]) {
			cnt++;
		}
		else {
			mx = max(mx, cnt);
			cnt = 1;
		}
	}
	cout << max(mx, cnt) << o_o;
}
/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) ll(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		int n, x; cin >> n >> x;
		vector < int > v(n);
		int sm = 0, cnt = 0, a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i]; sm += v[i];
			cnt += !(v[i] % x);
		}
		for (int i = 0; i < n; i++) {
			a++;
			if(v[i] % x) break;
		}
		for (int i = n - 1; i >= 0 ; i--) {
			b++;
			if(v[i] % x) break;
		}
		cout << (cnt == n ? -1 : (sm % x ? n : n - (min(a, b) == 0 ? max(a, b) : min(a, b)))) << endl;
	}
}
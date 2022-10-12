/**
*    author:  Mohamed Abo_Okail
*    created: 24/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < vector < int > > v(n, vector < int > (n));
	int flag = 1;
	for (int i = 0; i < n; i++) {
		if(!(i & 1)) {
			for (int j = 0; j < n; j++) {
				v[j][i] = flag ++;
			}
		}
		else {
			for (int j = n - 1; j >= 0 ; j--) {
				v[j][i] = flag ++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
			if(j != n - 1) cout << ' ';
		}
		cout << endl;
	}
}
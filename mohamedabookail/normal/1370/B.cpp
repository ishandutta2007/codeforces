/**
 *    author:  Mohamed Abo_Okail
 *    created: 2O/O6/2O2O
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
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		vector < int > v(n * 2), a, b;
		for (int i = 0; i < n * 2; i++) {
			cin >> v[i];
			if(v[i] & 1) a.push_back(i + 1);
			else b.push_back(i + 1);
		}
		int x = 0, y = 0, cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if(x + 1 < a.size()) {
				cout << a[x] << ' ' << a[x + 1] << endl;
				x += 2;
				cnt++;
			}
			if(cnt == n - 1) break;
			if(y + 1 < b.size()) {
				cout << b[y] << ' ' << b[y + 1] << endl;
				y += 2;
				cnt++;
			}
			if(cnt == n - 1) break;
		}
	}
}
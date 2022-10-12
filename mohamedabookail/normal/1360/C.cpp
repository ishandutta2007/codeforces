/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O5/2O2O
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
		int n; cin >> n;
		vector < int > v(n);
		int even = 0, odd = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] & 1) odd++; else even++;
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++) {
			if(v[i] - 1 == v[i - 1]) {
				cnt++;
				i++;
			}
		}
		cout << (((even & 1) + (odd & 1)) / 2 <= cnt ? "YES" : "NO") << endl;
	}
}
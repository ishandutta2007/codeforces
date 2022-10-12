/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O6/2O2O
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
	vector < int > v(n);
	deque < int > dq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if(i & 1) dq.push_front(v[i]);
		else dq.push_back(v[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << dq[i] << ' ';
	}
	cout << endl;
}
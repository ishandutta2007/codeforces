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
	vector < int > v(n);
	int a = 0, b = 0, indx = n - 1, ca = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		if(i > indx) break;
		if(a <= b) a += v[i], ca ++;
		else b += v[indx], indx --, i --, cb ++;;
	}
	cout << ca << ' ' << cb << endl;
}
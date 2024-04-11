/**
*    author:  Mohamed Abo_Okail
*    created: 21/1O/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll _fact(ll n) {
	if(n <= 1) return 1;
	return n * _fact(n - 1);
}

int main() {
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	cout << _fact(n) * 2 / (n * n) << endl;
}
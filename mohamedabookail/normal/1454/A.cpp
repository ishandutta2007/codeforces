/**
*    author:  Mohamed Abo_Okail
*    created: 24/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		cout << n << ' ';
		for (int i = 1; i < n; i++) cout << i << ' ';
		cout << endl;
	}
}
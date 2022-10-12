/**
*    author:  Mohamed Abo_Okail
*    created: 24/1O/2O2O
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
		ll n, m; cin >> n >> m;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			sum += oo;
		}
		cout << (sum == m ? "YES" : "NO") << endl;
	}
}
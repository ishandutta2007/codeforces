/**
*    author:  Mohamed Abo_Okail
*    created: O6/O9/2O2O
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
		vector < ll > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		reverse(all(v));
		for (int i = 0; i < n; i++) {
			cout << v[i];
			if(i != n - 1) cout << ' ';
		}
		cout << endl;
	}
}
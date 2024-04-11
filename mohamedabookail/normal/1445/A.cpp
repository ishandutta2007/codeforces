/**
*    author:  Mohamed Abo_Okail
*    created: O1/11/2O2O
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
		ll n, x; cin >> n >> x;
		vector < ll > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(all(a));
		sort(all(b));
		reverse(all(b));
		bool bol = 1;
		for (int i = 0; i < n; i++) {
			if(a[i] + b[i] > x) bol = 0;
		}
		cout << (bol ? "YES" : "NO") << endl;
	}
}
/**
*    author:  Mohamed Abo Okail
*    created: 26/O6/2O22
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		set < ll > a;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.insert(x);
		}
		cout << sz(a) - ((n - sz(a)) & 1) << endl;
	}
}
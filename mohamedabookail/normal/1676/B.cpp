/**
*    author:  Mohamed Abo Okail
*    created: 1O/O5/2O22
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
		int n;
		cin >> n;
		ll mn = 1e9, sum = 0, x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			sum += x;
			mn = min(mn, x);
		}
		cout << sum - (n * mn) << endl;
	}
}
/**
*    author:  Mohamed Abo Okail
*    created: 2O/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector < int > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int mn = min(a[i], k);
			a[i] -= mn;
			k -= mn;
			a[n - 1] += mn;
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}
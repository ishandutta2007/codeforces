/**
*    author:  Mohamed Abo Okail
*    created: 21/O5/2O21
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
	
	int n, m; cin >> n >> m;
	vector < ll > a(n);
	for (int i = 0; i < n; i++) {
		ll mn = 1e9;
		for (int j = 0; j < m; j++) {
			ll x; cin >> x;
			mn = min(mn, x);
		}
		a[i] = mn;
	}
	cout << *max_element(all(a)) << endl;
}
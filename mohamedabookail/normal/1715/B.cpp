/**
*    author:  Mohamed Abo Okail
*    created: 2O/O9/2O22
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
		ll n, k, b, s;
		cin >> n >> k >> b >> s;
		unsigned long long cur = k * b;
		cur += n * (k - 1);
		if(s > cur || s / k < b) {
			cout << -1 << endl;
			continue;
		}
		vector < ll > a(n , 0);
		a[n - 1] = min(k * b + (k - 1), s);
		s -= min(k * b + (k - 1), s);
		for (int i = 0; i < n && s; i++) {
			a[i] = min(s, k - 1);
			s -= min(s, k - 1);
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}
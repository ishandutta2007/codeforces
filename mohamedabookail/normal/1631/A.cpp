/**
*    author:  Mohamed Abo Okail
*    created: 27/O1/2O22
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
		vector < ll > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if(a[i] < b[i]) swap(a[i], b[i]);
		}
		sort(all(a));
		sort(all(b));
		cout << a[n - 1] * b[n - 1] << endl;
	}
}
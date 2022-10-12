/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if(n == 1) {
			cout << (a[0] > 1 ? "NO" : "YES") << endl;
			continue;
		}
		sort(all(a));
		cout << (a[n - 1] - a[n - 2] > 1 ? "NO" : "YES") << endl;
	}
}
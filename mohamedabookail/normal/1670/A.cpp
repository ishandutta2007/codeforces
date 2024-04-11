/**
*    author:  Mohamed Abo Okail
*    created: O9/O5/2O22
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
		vector < ll > a(n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt += (a[i] < 0);
			a[i] = abs(a[i]);
		}
		bool ok = 1;
		for (int i = 1; i < cnt; i++) {
			ok &= a[i] <= a[i - 1];
		}
		for (int i = cnt + 1; i < n; i++) {
			ok &= a[i] >= a[i - 1];
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
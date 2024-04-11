/**
*    author:  Mohamed Abo Okail
*    created: O5/1O/2O21
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
		int n, x; cin >> n >> x;
		vector < ll > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b = a;
		sort(all(b));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] == b[i]);
		}
		if(cnt == n) {
			cout << "YES" << endl;
			continue;
		}
		if(x == n) {
			cout << "NO" << endl;
			continue;
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				if(i < x && n - i - 1 < x) {
					ok = 0;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
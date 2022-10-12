/**
*    author:  Mohamed Abo Okail
*    created: 24/11/2O21
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
		vector < ll > a(n), aa;
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n / 2; i++) {
			if(a[i] != a[n - i - 1]) {
				aa.push_back(a[i]);
				aa.push_back(a[n - i - 1]);
				break;
			}
		}
		for (int i = 0; i < sz(aa); i++) {
			int x = n - 1;
			bool ok2 = 1;
			for (int j = 0; j < n; j++) {
				if(j >= x) break;
				if(a[j] == aa[i]) continue;
				if(a[x] == aa[i]) {
					j--;
					x--;
					continue;
				}
				if(a[j] != a[x]) {
					ok2 = 0;
					break;
				}
				x--;
			}
			if(ok2) {
				ok = 1;
				break;
			}
		}
		cout << (ok || sz(aa) == 0 ? "YES" : "NO") << endl;
	}
}
/**
*    author:  Mohamed Abo Okail
*    created: 2O/O2/2O22
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
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int cnt = 0;
		for (int i = 1; i < n - 1; i++) {
			if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
				cnt++;
				a[i + 1] = a[i];
				if(i + 2 < n) {
					a[i + 1] = max(a[i + 1], a[i + 2]);
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}
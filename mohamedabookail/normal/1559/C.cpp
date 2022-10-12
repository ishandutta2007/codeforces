/**
*    author:  Mohamed Abo Okail
*    created: 15/O8/2O21
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
		vector < int > a(n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt += a[i] == 1;
		}
		if(cnt == n || cnt == 0) {
			if(cnt == n) {
				cout << n + 1 << ' ';
				for (int i = 1; i <= n; i++) {
					cout << i << ' ';
				}
				cout << endl;
			}
			else {
				for (int i = 1; i <= n + 1; i++) {
					cout << i << ' ';
				}
				cout << endl;
			}
		}
		else {
			if(a[0] == 1) {
				cout << n + 1 << ' ';
				for (int i = 1; i <= n; i++) {
					cout << i << ' ';
				}
			}
			else {
				bool ok = 0;
				for (int i = 0; i < n; i++) {
					cout << i + 1 << ' ';
					if(i + 1 < n && a[i] == 0 && a[i + 1] == 1 && !ok) {
						cout << n + 1 << ' ';
						ok = 1;
					}
				}
			}
			cout << endl;
		}
	}
}
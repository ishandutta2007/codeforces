/**
*    author:  Mohamed Abo Okail
*    created: 22/O4/2O22
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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if(n == 1) {
			cout << "YES" << endl;
			continue;
		}
		sort(all(a));
		bool ok = 1;
		ll any = a[1] - a[0];
		if(any == 1) {
			any = a[1] + 1;
		}
		else if(any == 2) {
			any = a[1];
		}
		else if(any == 3) {
			any = a[1] - 1;
		}
		else {
			ok = 0;
		}
		for (int i = 2; i < n && ok; i++) {
			if(a[i] - any == 0) {
				any = a[i] + 1;
			}
			else if(a[i] - any == 1) {
				any = a[i];
			}
			else if(a[i] - any == 2) {
				any = a[i] - 1;
			}
			else {
				ok = 0;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
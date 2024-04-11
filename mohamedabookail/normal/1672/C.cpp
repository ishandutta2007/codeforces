/**
*    author:  Mohamed Abo Okail
*    created: 23/O4/2O22
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
		int l = -1, r = -1;
		for (int i = 1; i < n; i++) {
			if(a[i] == a[i - 1] && l == -1) {
				l = i;
			}
			if(a[i] == a[i - 1]) {
				r = i + 1;
			}
		}
		if(l + r == -2) {
			cout << 0 << endl;
		}
		else {
			int any = (r - l + 1);
			cout << (any < 4 ? any - 2 : any - 3) << endl;
		}
	}
}
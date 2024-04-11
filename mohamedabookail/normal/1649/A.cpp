/**
*    author:  Mohamed Abo Okail
*    created: O6/O3/2O22
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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int r = -1, l = -1;
		for (int i = 0; i < n; i++) {
			if(!a[i] && l == -1) {
				l = i - 1;
			}
			if(!a[i]) {
				r = i + 1;
			}
		}
		cout << r - l << endl;
	}
}
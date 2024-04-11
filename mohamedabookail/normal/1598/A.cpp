/**
*    author:  Mohamed Abo Okail
*    created: 1O/1O/2O21
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
		string a, b; cin >> a >> b;
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if(a[i] == '1' && b[i] == '1') {
				ok = 0;
			}
		}
		if(b[n - 1] == '1') ok = 0;
		cout << (ok ? "YES" : "NO") << endl;
	}
}
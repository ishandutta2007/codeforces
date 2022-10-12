/**
*    author:  Mohamed Abo Okail
*    created: 21/O9/2O22
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
		vector < string > a(n);
		map < string , bool > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]] = 1;
		}
		for (int i = 0; i < n; i++) {
			bool ok = 0;
			for (int j = 0; j < sz(a[i]) - 1 && !ok; j++) {
				string x = a[i].substr(0, j + 1);
				string y = a[i].substr(j + 1, sz(a[i]));
				ok |= (mp[x] && mp[y]);
			}
			cout << ok;
		}
		cout << endl;
	}
}
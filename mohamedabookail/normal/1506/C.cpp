/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		string a, b; cin >> a >> b;
		int mx = 0;
		map < string , bool > mp;
		for (int i = 0; i < sz(b); i++) {
			string x = "";
			for (int j = i; j < sz(b); j++) {
				x.push_back(b[j]);
				mp[x] = 1;
			}
		}
		for (int i = 0; i < sz(a); i++) {
			string x = "";
			for (int j = i; j < sz(a); j++) {
				x.push_back(a[j]);
				if(mp[x]) {
					mx = max(mx, sz(x));
				}
			}
		}
		cout << sz(a) + sz(b) - mx * 2 << endl;
	}
}
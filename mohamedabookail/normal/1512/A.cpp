/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O21
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
		int n; cin >> n;
		vector < ll > a(n);
		map < ll, ll > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if(mp[a[i]] == 1) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
}
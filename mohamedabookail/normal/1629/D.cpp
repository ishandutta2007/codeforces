/**
*    author:  Mohamed Abo Okail
*    created: 22/O1/2O22
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

	int t;
	cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < string > a(n);
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(sz(a[i]) == 1) {
				ok = 1;
			}
			if(sz(a[i]) == 2) {
				if(a[i][0] == a[i][1]) {
					ok = 1;
				}
			}
			if(sz(a[i]) == 3) {
				if(a[i][0] == a[i][2]) {
					ok = 1;
				}
			}
		}
		if(ok) {
			cout << "YES" << endl;
			continue;
		}
		for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
			for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
				string x = "", y = "";
				x += ch1;
				x += ch2;
				y += ch2;
				y += ch1;
				bool ok1 = 0, ok2 = 0;
				map < char, bool > mp;
				for (int i = 0; i < n; i++) {
					if(sz(a[i]) == 2 && a[i] == x) {
						ok1 = 1;
						continue;
					}
					if(sz(a[i]) == 3) {
						if(x[0] == a[i][0] && x[1] == a[i][1]) {
							ok2 = 1;
							mp[a[i][2]] = 1;
							continue;
						}
					}
					if(ok1) {
						if(sz(a[i]) == 2 && a[i] == y) {
							ok = 1;
							break;
						}
						if(sz(a[i]) == 3) {
							if(y[0] == a[i][1] && y[1] == a[i][2]) {
								ok = 1;
								break;
							}
						}
					}
					if(ok2) {
						if(sz(a[i]) == 2) {
							if(y[0] == a[i][0] && y[1] == a[i][1]) {
								ok = 1;
								break;
							}
						}
						if(sz(a[i]) == 3) {
							if(y[0] == a[i][1] && y[1] == a[i][2] && mp[a[i][0]]) {
								ok = 1;
								break;
							}
						}
					}
				}
				if(ok) break;
			}
			if(ok) break;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
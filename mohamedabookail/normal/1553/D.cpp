/**
*    author:  Mohamed Abo Okail
*    created: 22/O7/2O21
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
		string a, b;
		cin >> a >> b;
		if(sz(b) > sz(a)) {
			cout << "NO" << endl;
			continue;
		}
		if(sz(a) == sz(b)) {
			cout << (a == b ? "YES" : "NO") << endl;
			continue;
		}
		reverse(all(a));
		reverse(all(b));
		int indx = 0, cntt = 0;
		for (int i = 0; i < sz(a); i++) {
			if(indx < sz(b) && b[indx] == a[i] && cntt % 2 == 0) {
				a[i] = '0';
				indx++;
				cntt = 0;
			}
			if(a[i] != '0') {
				cntt++;
			}
		}
		if(indx != sz(b)) {
			cout << "NO" << endl;
			continue;
		}
		bool ok = 1, okk = 1;
		reverse(all(a));
		int cnt = 0;
		for (int i = 0; i < sz(a); i++) {
			if(a[i] != '0') {
				cnt++;
			}
			else {
				if(okk) {
					okk = 0;
				}
				else {
					if(cnt & 1) {
						ok = 0;
					}
				}
				cnt = 0;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
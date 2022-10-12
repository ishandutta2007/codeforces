/**
*    author:  Mohamed Abo Okail
*    created: 14/O5/2O22
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
	
	ll n, q;
	cin >> n >> q;
	map < ll , ll > row, col;
	map < string , bool > mp;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int a, b;
			cin >> a >> b;
			row[a]++;
			col[b]++;
		}
		if(t == 2) {
			int a, b;
			cin >> a >> b;
			row[a]--;
			col[b]--;
			if(!row[a] || !col[b]) {
				mp.clear();
			}
		}
		if(t == 3) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			bool ok = 1;
			if(a > c) swap(a, c);
			if(b > d) swap(b, d);
			string s = "";
			s += to_string(a);
			s += to_string(b);
			s += to_string(c);
			s += to_string(d);
			if(mp[s] == 1) {
				cout << "Yes" << endl;
				continue;
			}
			if(c - a <= d - b) {
				for (int i = a; i <= c && ok; i++) {
					ok &= (row[i] >= 1);
					ok &= (row[c] >= 1);
					c--;
				}
				if(!ok) {
					ok = 1;
					for (int i = b; i <= d && ok; i++) {
						ok &= (col[i] >= 1);
						ok &= (col[d] >= 1);
						d--;
					}
				}
			}
			else {
				for (int i = b; i <= d && ok; i++) {
					ok &= (col[i] >= 1);
					ok &= (col[d] >= 1);
					d--;
				}
				if(!ok) {
					ok = 1;
					for (int i = a; i <= c && ok; i++) {
						ok &= (row[i] >= 1);
						ok &= (row[c] >= 1);
						c--;
					}
				}
			}
			if(ok) {
				mp[s] = 1;
			}
			cout << (ok ? "Yes" : "No") << endl;
		}
	}
}
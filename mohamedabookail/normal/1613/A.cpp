/**
*    author:  Mohamed Abo Okail
*    created: 04/12/2O21
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
		string a, b; int x, y;
		cin >> a >> x >> b >> y;
		if(sz(a) + x > sz(b) + y) {
			cout << '>' << endl;
		}
		else if(sz(a) + x < sz(b) + y) {
			cout << '<' << endl;
		}
		else {
			string s(abs(sz(a) - sz(b)), '0');
			if(sz(a) < sz(b)) {
				a += s;
			}
			else {
				b += s;
			}
			bool ok = 0;
			for (int i = 0; i < sz(a); i++) {
				if(a[i] > b[i]) {
					cout << '>' << endl;
					ok = 1;
					break;
				}
				if(a[i] < b[i]) {
					cout << '<' << endl;
					ok = 1;
					break;
				}
			}
			if(!ok) {
				cout << '=' << endl;
			}
		}
	}
}
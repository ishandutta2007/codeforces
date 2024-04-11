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
		string s; cin >> s;
		string x;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] > s.back()) {
				x.push_back(s[i]);
			}
			else {
				x.push_back(s.back());
				s.pop_back();
				i--;
			}
		}
		reverse(all(x));
		bool ok = 1;
		for (int i = 0; i < sz(x); i++) {
			ok &= (x[i] - 'a') == i;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
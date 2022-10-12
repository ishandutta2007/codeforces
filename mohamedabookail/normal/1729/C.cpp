/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		int mn = abs((s[0] - '0') - (s[sz(s) - 1] - '0'));
		vector < pair < char , int > > a;
		for (int i = 1; i < sz(s) - 1; i++) {
			if(s[0] <= s[sz(s) - 1]) {
				if(s[i] >= s[0] && s[i] <= s[sz(s) - 1]) {
					a.push_back(make_pair(s[i], i + 1));
				}
			}
			else {
				if(s[i] <= s[0] && s[i] >= s[sz(s) - 1]) {
					a.push_back(make_pair(s[i], i + 1));
				}
			}
		}
		sort(all(a));
		vector < int > ar;
		if(s[0] <= s[sz(s) - 1]) {
			ar.push_back(1);
			for (int i = 0; i < sz(a); i++) {
				ar.push_back(a[i].second);
			}
			ar.push_back(sz(s));
		}
		else {
			ar.push_back(1);
			for (int i = sz(a) - 1; i >= 0; i--) {
				ar.push_back(a[i].second);
			}
			ar.push_back(sz(s));
		}
		cout << mn << ' ' << sz(ar) << endl;
		for (int i = 0; i < sz(ar); i++) {
			cout << ar[i] << ' ';
		}
		cout << endl;
	}
}
/**
*    author:  Mohamed Abo Okail
*    created: 13/O4/2O22
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
		map < char , int > mp;
		for (int i = 0; i < sz(b); i++) {
			mp[b[i]]++;
		}
		string ans = "";
		for (int i = sz(a) - 1; i >= 0 ; i--) {
			if(mp[a[i]]) {
				ans = a[i] + ans;
				mp[a[i]]--;
			}
		}
		cout << (ans == b ? "YES" : "NO") << endl;
	}
}
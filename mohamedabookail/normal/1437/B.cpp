/**
*    author:  Mohamed Abo_Okail
*    created: 27/1O/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		string s; cin >> s;
		ll cnt = 0;
		for (int i = 1; i < n; i++) {
			if(s[i] == s[i - 1]) {
				cnt++;
			}
		}
		cout << (cnt + 1) / 2 << endl;
	}
}
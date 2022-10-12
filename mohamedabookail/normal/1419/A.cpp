/**
*    author:  Mohamed Abo_Okail
*    created: 19/O9/2O2O
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
		int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
		for (int i = 0; i < sz(s); i++) {
			if((i + 1) & 1) {
				if((s[i] - '0') % 2 == 0) a1++;
				else a2++;
			}
			else {
				if((s[i] - '0') % 2 == 0) b1++;
				else b2++;
			}
		}
		bool bol = 1;
		while(n-- > 1) {
			if(bol) {
				if(a1) a1--;
				else if(a2) a2--;
			}
			else {
				if(b2) b2--;
				else if(b1) b1--;
			}
			bol = !bol;
		}
		cout << (a1 + b1 > a2 + b2 ? 2 : 1) << endl;
	}
}
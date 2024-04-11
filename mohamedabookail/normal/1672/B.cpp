/**
*    author:  Mohamed Abo Okail
*    created: 23/O4/2O22
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
		stack < char > st;
		bool ok = 1;
		for (int i = 0; i < sz(s); i++) {
			if(s[i] == 'A') {
				st.push('A');
			}
			else {
				if(st.empty()) {
					ok = 0;
					break;
				}
				st.pop();
			}
		}
		cout << (ok && s.back() == 'B' ? "YES" : "NO") << endl;
	}
}
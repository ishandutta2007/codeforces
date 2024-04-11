/**
*    author:  Mohamed Abo Okail
*    created: 21/O4/2O22
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
		ll n;
		cin >> n;
		string s; cin >> s;
		bool ok = 1, okk = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			cnt1 += (s[i] == 'B');
			cnt2 += (s[i] == 'R');
			if(s[i] == 'W') {
				okk = 1;
				if((cnt1 > 0 && cnt2 == 0) || (cnt1 == 0 && cnt2 > 0)) {
					ok = 0;
				}
				if((cnt1 == 1 && cnt2 == 0) || (cnt1 == 0 && cnt2 == 1)) {
					ok = 0;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
		if((cnt1 > 0 && cnt2 == 0) || (cnt1 == 0 && cnt2 > 0)) {
			ok = 0;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
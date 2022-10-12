/**
*    author:  Mohamed Abo Okail
*    created: 12/11/2O21
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
		int n; cin >> n;
		string s; cin >> s;
		int lo = 0, hi = sz(s) - 1;
		vector < ll > ans;
		while(lo <= hi) {
			if(s[hi] == '1') {
				hi--;
				continue;
			}
			if(s[lo] == '0') {
				lo++;
				continue;
			}
			ans.push_back(lo + 1);
			ans.push_back(hi + 1);
			lo++;
			hi--;
		}
		sort(all(ans));
		if(sz(ans)) {
			cout << 1 << endl;
		}
		cout << sz(ans);
		for (int i = 0; i < sz(ans); i++) {
			cout << ' ' << ans[i];
		}
		cout << endl;
	}
}
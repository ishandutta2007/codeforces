/**
*    author:  Mohamed Abo Okail
*    created: 21/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		vector < int > a;
		int cnt = 0, ans = 0;
		s += '0';
		for (int i = 0; i < sz(s); i++) {
			cnt += s[i] == '1';
			if(s[i] == '0') {
				a.push_back(cnt);
				cnt = 0;
			}
		}
		sort(all(a)); reverse(all(a));
		for (int i = 0; i < sz(a); i++) {
			ans += ((i & 1) == 0 ? a[i] : 0);
		}
		cout << ans << endl;
	}
}
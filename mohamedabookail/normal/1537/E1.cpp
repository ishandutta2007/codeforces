/**
*    author:  Mohamed Abo Okail
*    created: 19/01/2O22
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

	ll n, k;
	cin >> n >> k;
	string s; cin >> s;
	string ans(5e3, 'z');
	for (int i = 0; i < n; i++) {
		string x = s;
		while(sz(x) < k) {
			x = x + s;
		}
		if(sz(x) > k) {
			x.erase(x.begin() + k, x.end());
		}
		ans = min(ans, x);
		s.pop_back();
	}
	cout << ans << endl;
}
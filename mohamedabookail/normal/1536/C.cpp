/**
*    author:  Mohamed Abo Okail
*    created: O6/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		map < pair < ll, ll > , ll > mp;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			cnt1 += s[i] == 'D';
			cnt2 += s[i] == 'K';
			int a = cnt1 / _gcd(cnt1, cnt2);
			int b = cnt2 / _gcd(cnt1, cnt2);
			mp[make_pair(a, b)]++;
			cout << mp[make_pair(a, b)] << ' ';
		}
		cout << endl;
	}
}
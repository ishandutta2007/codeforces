/**
*    author:  Mohamed AboOkail
*    created: 10/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n;
	cin >> n;
	map < long long, long long > mp;
	long long mx = 0, mn = 1e9;
	for (int i = 0; i < n; i++) {
		long long oo;
		cin >> oo;
		mp[oo]++;
		mx = max(mx, oo);
		mn = min(mn, oo);
	}
	cout << mx - mn << ' ' << (mx != mn ? mp[mx] * mp[mn] : (mp[mx] * (mp[mx] - 1) / 2)) << "\n";
}
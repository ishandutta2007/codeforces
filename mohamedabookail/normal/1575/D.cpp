/**
*    author:  Mohamed Abo Okail
*    created: O5/1O/2O21
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
	
	int x = 0;
	vector < ll > a;
	vector < string > aa;
	map < string , bool > mp;
	a.push_back(0);
	aa.push_back("0");
	mp["0"] = 1;
	while(a.back() < 1e8 - 25) {
		x += 25;
		a.push_back(x);
		aa.push_back(to_string(x));
		mp[aa.back()] = 1;
	}
	string s; cin >> s;
	bool ok = 1;
	for (int i = 0; i < sz(s); i++) {
		ok &= (s[i] >= '0' && s[i] <= '9');
	}
	if(ok) {
		cout << (mp[s] ? 1 : 0) << endl;
		return 0;
	}
	if(s[0] == '0') {
		cout << 0 << endl;
		return 0;
	}
	ll lo = 0, hi = sz(aa) - 1, mid = 0, indx = -1;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(sz(aa[mid]) < sz(s)) {
			lo = mid + 1;
		}
		else {
			indx = mid;
			hi = mid - 1;
		}
	}
	ll ans = 0;
	for (int i = indx; i < sz(aa); i++) {
		if(sz(aa[i]) > sz(s)) break;
		string ss = s;
		bool okk = 1;
		char ch = 'a';
		for (int j = 0; j < sz(s); j++) {
			if(ss[j] == '_') {
				ss[j] = aa[i][j];
			}
			if(ss[j] == 'X') {
				ss[j] = aa[i][j];
				if(ch == 'a') ch = aa[i][j];
				if(ch != aa[i][j]) okk = 0;
			}
		}
		if(ss == aa[i] && okk) {
			ans++;
		}
	}
	cout << ans << endl;
}
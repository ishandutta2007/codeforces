/**
*    author:  Mohamed Abo Okail
*    created: 11/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	string s; cin >> s;
	map < char, int > mp;
	vector < pair < int, int > > pr(3);
	bool ok = 1;
	for (int i = 0; i < sz(s); i++) {
		mp[s[i]]++;
		if(s[i] == 'a') {
			if(mp['a'] == 1) {
				pr[0].first = i;
				pr[0].second = i;
			}
			else {
				pr[0].second = i;
			}
		}
		if(s[i] == 'b') {
			if(mp['b'] == 1) {
				pr[1].first = i;
				pr[1].second = i;
			}
			else {
				pr[1].second = i;
			}
		}
		if(s[i] == 'c') {
			if(mp['c'] == 1) {
				pr[2].first = i;
				pr[2].second = i;
			}
			else {
				pr[2].second = i;
			}
		}
	}
	if(!mp['a'] || !mp['b'] || !mp['c']) {
		ok = 0;
	}
	if(mp['a'] != mp['c'] && mp['b'] != mp['c']) {
		ok = 0;
	}
	if(pr[0].second > pr[1].first || pr[1].second > pr[2].first) {
		ok = 0;
	}

	cout << (ok ? "YES": "NO") << endl;
}
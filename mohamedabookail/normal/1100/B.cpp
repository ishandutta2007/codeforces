/**
*    author:  Mohamed AboOkail
*    created: 19/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector < int > a(m);
	multiset < int > s;
	map < int, int > mp;
	string ans(m, '0');
	int cur = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		s.insert(0);
	}
	for (int i = 0; i < m; i++) {
		s.erase(s.find(mp[a[i]]));
		mp[a[i]]++;
		s.insert(mp[a[i]]);
		if(*s.begin() > cur) {
			ans[i] = '1';
			cur++;
		}
	}
	cout << ans << "\n";
}
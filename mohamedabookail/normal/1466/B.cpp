/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < int > a(n);
		map < int, bool > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if(!mp[a[i]]) mp[a[i]] = 1;
			else if(!mp[a[i] + 1]) mp[a[i] + 1] = 1;
		}
		cout << mp.size() << endl;
	}
}
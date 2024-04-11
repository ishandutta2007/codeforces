/**
*    author:  Mohamed AboOkail
*    created: 28/01/2O21
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
		vector < long long > a(n);
		map < long long, long long > mp;
		long long mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			mx = max(mx, mp[a[i]]);
		}
		cout << mx << "\n";
	}
}
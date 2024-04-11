/**
*    author:  Mohamed AboOkail
*    created: 04/01/2O21
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
		map < int, int > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		int x = mp[1], y = mp[2];
		long long sum = x + y * 2;
		if(sum & 1) {
			cout << "NO" << endl;
			continue;
		}
		if(((sum / 2) & 1) && !x) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}
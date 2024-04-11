/**
*    author:  Mohamed AboOkail
*    created: 16/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector < long long > a;
	map < long long , bool > mp;
	for (long long i = 1; i <= 10000; i++) {
		a.push_back(pow(i, 3));
		mp[pow(i, 3)] = 1;
	}
	int t;
	cin >> t;
	while(t--) {
		long long n;
		cin >> n;
		bool ok = 0;
		for (int i = 0; i < a.size(); i++) {
			if(mp[n - a[i]]) {
				ok = 1;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}
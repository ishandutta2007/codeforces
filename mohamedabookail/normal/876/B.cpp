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
	
	int n, k, m;
	cin >> n >> k >> m;
	vector < int > a(n);
	map < int, int > mp;
	long long ans = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i] % m]++;
		if(mp[a[i] % m] >= k) {
			ans = a[i] % m;
		}
	}
	if(ans != -1) {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			if(a[i] % m == ans) {
				cout << a[i] << ' ';
				k--;
			}
			if(!k) break;
		}
	}
	else cout << "No" << endl;
}
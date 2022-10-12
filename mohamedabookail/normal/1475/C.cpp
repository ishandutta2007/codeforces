/**
*    author:  Mohamed AboOkail
*    created: 25/01/2O21
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
		int a, b, k;
		cin >> a >> b >> k;
		vector < int > x(k), y(k);
		map < int, int > mp1, mp2;
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			cin >> x[i];
			mp1[x[i]]++;
		}
		for (int i = 0; i < k; i++) {
			cin >> y[i];
			mp2[y[i]]++;
		}
		for (int i = 0; i < k; i++) {
			long long cur = k - 1;
			cur -= mp1[x[i]] - 1;
			cur -= mp2[y[i]] - 1;
			ans += max(0LL, cur);
		}
		cout << ans / 2 << "\n";
	}
}
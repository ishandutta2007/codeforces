/**
*    author:  Mohamed AboOkail
*    created: 18/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if(i) a[i] += a[i - 1];
	}
	int q;
	cin >> q;
	while(q--) {
		int oo;
		cin >> oo;
		int lo = 0, hi = n - 1, mid = 0, ans = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(a[mid] >= oo) {
				ans = mid + 1;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}
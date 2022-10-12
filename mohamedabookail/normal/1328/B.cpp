/**
*    author:  Mohamed AboOkail
*    created: 02/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
long long ok(long long n) {
	return n * (n + 1) / 2;
}

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		string s(n, 'a');
		int a = 0, b = 0;
		long long lo = 1, hi = n, mid = 0, ans = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(k <= ok(mid)) {
				ans = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		s[s.size() - ans - 1] = 'b';
		s[s.size() - ans + (ok(ans) - k)] = 'b';
		cout << s << endl;
	}
}
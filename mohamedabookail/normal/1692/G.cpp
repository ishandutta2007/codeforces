/**
*    author:  Mohamed Abo Okail
*    created: 27/O6/2O22
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector < int > a(n), b(n , 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			if(a[i] * 2 <= a[i - 1]) {
				b[i] = 0;
			}
		}
		int ans = 0, cnt = 1;
		for (int i = 1; i < n; i++) {
			if(b[i] == 1) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			ans += (cnt >= k + 1);
		}
		cout << ans << endl;
	}
}
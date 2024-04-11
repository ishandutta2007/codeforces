/**
*    author:  Mohamed Abo Okail
*    created: 14/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a, b;
		for (int i = 1; i <= 9; i++) {
			a.push_back(i);
			b.push_back(i);
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				b[j] = b[j] * 10 + j + 1;
				a.push_back(b[j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < sz(a); i++) {
			ans += (a[i] <= n);
		}

		cout << ans << endl;
	}
}
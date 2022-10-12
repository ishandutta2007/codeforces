/**
*    author:  Mohamed Abo Okail
*    created: O9/O4/2O22
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
	
	int n;
	cin >> n;
	ll x, mod = 32768;
	while(n--) {
		cin >> x;
		ll ans = 1e9, cnt = 0;
		for (int i = x; i <= x + 50; i++) {
			ll s = i;
			cnt = 0;
			for (int j = 0; j < 20; j++) {
				s %= mod;
				if(s == 0) {
					ans = min(ans, cnt + i - x);
				}
				s *= 2;
				cnt++;
			}
		}
		cout << ans << ' ';
	}
}
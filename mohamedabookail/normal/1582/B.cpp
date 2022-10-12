/**
*    author:  Mohamed Abo Okail
*    created: 24/1O/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
long long nCr(long long n, long long r) {
	long long ans = 1;
	long long div = 1; 
	for (long long i = r + 1; i <= n; i++) {
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll one = 0, zero = 0;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			one += (x == 1);
			zero += (x == 0);
		}
		ll ans = one;
		for(int i = 1; i <= zero; i++) {
			ans += nCr(zero, i) * one;
		}
		cout << ans << endl;
	}
}
/**
*    author:  Mohamed Abo Okail
*    created: 29/1O/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
ll ok(ll mid) {
	return mid * (mid + 1) / 2 + 1;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		if(k == 1) {
			cout << n - 1 << endl;
			continue;
		}
		ll sum = 1, cnt = 0, x = 1;
		while(x <= k) {
			if(sum >= n) break;
			sum += x;
			x *= 2;
			cnt++;
		}
		if(sum >= n) {
			cout << cnt << endl;
			continue;
		}
		cout << cnt + (n - sum + k - 1) / k << endl;
	}
}
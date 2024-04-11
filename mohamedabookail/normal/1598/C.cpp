/**
*    author:  Mohamed Abo Okail
*    created: 1O/1O/2O21
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
		int n; cin >> n;
		vector < ll > a(n);
		map < ll, ll > mp;
		ll sum = 0, cur = 0, ans = 0, flag = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			mp[a[i]]++;
		}
		flag = sum % n;
		if(sum == 0) {
			cout << 1LL * n * (n - 1) / 2 << endl;
			continue;
		}
		if(flag * 2 != n && flag) {
			cout << 0 << endl;
			continue;
		}
		cur = sum / n * 2 + (flag ? 1 : 0);
		for (int i = 0; i < n; i++) {
			ll x = cur - (a[i] % cur);
			if(x == (a[i] % cur)) {
				ll curr = mp[x];
				ans += curr * (curr - 1) / 2;
				mp[x] = 0;
			}
			else {
				if(mp[x]) {
					ans += 1LL * mp[x] * mp[(a[i] % cur)];
					mp[x] = 0;
					mp[(a[i] % cur)] = 0;
				}
			}
		}
		cout << ans << endl;
	}
}
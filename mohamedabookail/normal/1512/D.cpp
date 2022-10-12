
/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a(n + 2);
		map < ll, ll > mp;
		for (int i = 0; i < n + 2; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		sort(all(a));
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		if(sum == a[n] || sum == a[n + 1]) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << ' ';
			}
			cout << endl;
			continue;
		}
		bool ok = 0;
		sum += a[n];
		if(sum > a[n + 1] && mp[sum - a[n + 1]] && (mp[sum - a[n + 1]] >= 2 || sum - a[n + 1] != a[n + 1])) {
			for (int i = 0; i <= n; i++) {
				if(sum - a[n + 1] == a[i] && !ok) {
					ok = 1;
					continue;
				}
				cout << a[i] << ' ';
			}
			cout << endl;
			continue;
		}
		cout << -1 << endl;
	}
}
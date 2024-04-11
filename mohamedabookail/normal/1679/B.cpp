/**
*    author:  Mohamed Abo Okail
*    created: 14/O5/2O22
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
	
	ll n, q;
	cin >> n >> q;
	vector < ll > a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll last = 0;
	map < ll , bool > mp;
	while(q--) {
		int s;
		cin >> s;
		if(s == 1) {
			ll ind, x;
			cin >> ind >> x;
			if(last != 0 && mp[ind] == 0) {
				a[ind - 1] = last;
				mp[ind] = 1;
			}
			sum -= a[ind - 1];
			sum += x;
			a[ind - 1] = x;
		}
		else {
			ll x;
			cin >> x;
			last = x;
			sum = x * n;
			mp.clear();
		}
		cout << sum << endl;
	}
}
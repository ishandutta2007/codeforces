/**
*    author:  Mohamed Abo Okail
*    created: 14/O4/2O21
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
 
	ll n; cin >> n;
	vector < ll > a(n), b(n), c(n);
	vector < pair < ll, pair < ll, ll > > > pr(n);
	for (int i = 0; i < n; i++) {
		cin >> pr[i].second.first;
	}
	for (int i = 0; i < n; i++) {
		cin >> pr[i].second.second;
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		pr[i].first = abs(pr[i].second.first - pr[i].second.second);
		sum += pr[i].first;
	}
	if(sum == 0) {
		return cout << sum << endl, 0;
	}
	sort(all(pr));
	reverse(all(pr));
	for (int i = 0; i < n; i++) {
		a[i] = pr[i].second.first;
		b[i] = pr[i].second.second;
		c[i] = pr[i].first;
	}
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < min(n, 1000LL); j++) {
			if(abs(a[i] - b[j]) + abs(a[j] - b[i]) < c[i] + c[j]) {
				mx = max(mx, (c[i] + c[j]) - abs(a[i] - b[j]) - abs(a[j] - b[i]));
			}
			ll cur = j + 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
			cur += 1e3;
			if(cur < n && abs(a[i] - b[cur]) + abs(a[cur] - b[i]) < c[i] + c[cur]) {
				mx = max(mx, (c[i] + c[cur]) - abs(a[i] - b[cur]) - abs(a[cur] - b[i]));
			}
		}
	}
	cout << sum - mx << endl;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int t, n;
	ll w;
	ll x, y, z;
	ll s, ans;
	vector<int>b;
	vector<pair<ll,int> >a;
	cin >> t;
	rep(tt, t) {
		cin >> n >> w;
		a.clear();
		b.clear();
		rep(i, n) {
			cin >> x;
			a.pb({ x,i });
		}
		sort(all(a), greater<pair<ll, int> >());
		s = 0;
		rep(i, n) {
			if ((s + a[i].first) <= w) {
				b.pb(a[i].second + 1);
				s += a[i].first;
			}
		}
		w = (w + 1) / 2;
		if (s < w) {
			cout << -1 << endl;
		}
		else {
			n = b.size();
			cout << n << endl;
			rep(i, n - 1)cout << b[i] << " ";
			cout << b[n - 1] << endl;
		}

	}
	return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	ll t, n, k, x;
	ll sz;
	ll cnt;
	vector<ll>a;
	cin >> t;
	rep(tt, t) {
		cin >> n >> k;
		k--;
		a.clear();
		x = k;
		rep3(i, n - 1, 1) {
			if (x % 2 == 0)a.pb(i);
			x /= 2;
		}
		if (x > 0)cout << -1 << endl;
		else {
			a.pb(0);
			reverse(all(a));
			a.pb(n);
			sz = a.size();
			cnt = 0;
			rep(i, sz - 1) {
				rep3(j, a[i + 1], a[i] + 1) {
					cout << j;
					cnt++;
					if (cnt < n)cout << " ";
					else cout << endl;
				}
			}
		}
	}
	return 0;
}
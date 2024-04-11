#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
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
	vector<pll>a;
	ll x;
	ll n, t, cur, st;
	ll c0, c1;
	bool v = true;
	cin >> t;
	rep(tt, t) {
		v = true;
		cin >> n;
		a.clear();
		rep(i, n) {
			cin >> x;
			a.pb({ x,i });
		}
		sort(all(a));
		cur = 0;
		while (cur < n) {
			st = cur;
			c0 = 0;
			c1 = 0;
			while (cur < n) {
				if (a[st].first != a[cur].first)break;
				x = abs(cur - a[cur].second);
				if (x % 2 == 1) {
					if (cur % 2 == 1)c1++;
					else c0++;
				}
				cur++;
			}
			if (c0 != c1)v = false;
		}
		if (v)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
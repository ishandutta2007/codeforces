#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
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
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int t;
	int x, y;
	int n, k;
	vi a, b;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		a.clear();
		b.clear();
		rep(i, n) {
			cin >> x;
			a.pb(x);
			a.pb(100);
		}
		rep(i, n) {
			cin >> x;
			b.pb(x);
			b.pb(0);
		}
		sort(all(a));
		sort(all(b), greater<int>());
		x = 0;
		y = 0;
		rep(i, n) {
			x += a[i];
			if (i % 4 == 3)x -= a[(i / 4)];
			if (i % 4 != 3)y += b[3 * (i / 4) + (i % 4)];
		}
		k = n;
		rep2(i, n, 2 * n - 1) {
			if (x >= y) {
				k = i - n;
				break;
			}
			x += a[i];
			if (i % 4 == 3)x -= a[(i / 4)];
			if (i % 4 != 3)y += b[3 * (i / 4) + (i % 4)];
		}
		cout << k << endl;
	}
	return 0;
}
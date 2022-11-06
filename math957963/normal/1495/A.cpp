#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define EPS (long double)0.000001
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
	vector<int>a, b;
	int t, n;
	int xx, yy;
	long double x, y, z, ans;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		a.clear();
		b.clear();
		rep(i, (2 * n)) {
			cin >> xx >> yy;
			xx = abs(xx);
			yy = abs(yy);
			if (xx==0)a.pb(yy);
			else b.pb(xx);
		}
		sort(all(a));
		sort(all(b));
		ans = 0;
		rep(i, n) {
			x = (long double)a[i];
			y = (long double)b[i];
			z = sqrt((x*x) + (y*y));
			ans += z;
		}
		cout << ans << endl;
	}

	return 0;
}
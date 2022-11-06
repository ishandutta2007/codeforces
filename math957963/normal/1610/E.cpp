#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007
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
	int n;
	vector<ll>a;
	int b[N];
	int z;
	ll x, y;
	int ans;
	int l, r, m, cur, curx;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		a.clear();
		rep(i, n) {
			cin >> x;
			a.pb(x);
		}
		sort(all(a));
		x = MOD * 2;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] != x) {
				x = a[i];
				z = i;
			}
			b[i] = z;
		}
		ans = 2;
		rep(i, n - 1) {
			cur = i + 1;
			curx = 2;
			if (a[i] == a[i + 1]) {
				cur = b[i + 1];
				curx = b[i + 1] - i + 1;
			}
			while ((a[n - 1] - a[i]) >= (a[cur] - a[i]) * 2) {
				if (cur >= n - 1)break;
				l = cur;
				r = n - 1;
				x = (a[cur] - a[i]) * 2;
				while ((r - l) > 1) {
					m = (l + r) / 2;
					if (a[m] - a[i] >= x)r = m;
					else l = m;
				}
				cur = r;
				curx++;
			}
			ans = max(ans, curx);
		}
		cout << n - ans << endl;
	}
	return 0;
}
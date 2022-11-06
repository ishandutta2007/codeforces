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
	int t, n, m, x, d;
	vector<vi>a;
	int cnt[N];
	vi c;
	vector<pii>b;
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		a.clear();
		b.clear();
		rep(i, n) {
			c.clear();
			rep(j, m) {
				cin >> x;
				c.pb(x);
			}
			sort(all(c));
			a.pb(c);
			rep(j, m) {
				b.pb({ c[j],i });
			}
		}
		sort(all(b));
		rep(i, n)cnt[i] = 0;
		rep(i, m) {
			cnt[b[i].second]++;
		}
		d = 0;
		rep(i, n) {
			rep(j, m - 1) {
				x = (j + m - d) % m;
				cout << a[i][x] << " ";
			}
			x = (m + m - 1 - d) % m;
			cout << a[i][x] << endl;
			d += cnt[i];
		}
	}

	return 0;
}
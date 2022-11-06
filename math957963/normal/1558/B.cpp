#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N (1<<18)
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


int dp[4000010];
vector<int>a;
int main() {
	int n, m, k;
	int sz, cf;
	ll x, y, z;
	ll s, t;
	cin >> n >> m;
	dp[0] = 1;
	s = 0;
	t = 0;
	rep2(ii, 2, n) {
		s = (s + dp[ii - 2]) % m;
		t = (t + 1) % m;
		k = ii;
		a.clear();
		a.push_back(1);
		for (int i = 2; (i*i) <= k; i++) {
			if (k%i == 0) {
				sz = a.size();
				cf = 1;
				while (k%i == 0) {
					cf *= i;
					k /= i;
					rep(j, sz)a.pb(a[j] * cf);
				}
			}
		}
		if (k > 1) {
			sz = a.size();
			rep(j, sz)a.pb(a[j] * k);
		}
		sz = a.size();
		rep(j, sz) {
			if ((a[j] > 1) && (a[j] < ii)) {
				t = (t + m - dp[a[j] - 2]) % m;
				t = (t + dp[a[j]-1]) % m;
			}
		}
		x = (s + t) % m;
		dp[ii - 1] = ((int)x);
	}
	cout << dp[n - 1] << endl;



	return 0;
}
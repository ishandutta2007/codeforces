#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 998244353
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
	ll n, m;
	cin >> n >> m;

	vector<vector<ll> >a(n, vector<ll>(m));
	rep(i, n)rep(j, m)cin >> a[i][j];

	ll s[N];
	ll cnt[N];
	ll ans = 0;
	rep(i, N) {
		s[i] = 0;
		cnt[i] = 0;
	}
	rep(i, n) {
		rep(j, m) {
			ans += (i*cnt[a[i][j]]) - s[a[i][j]];
			cnt[a[i][j]]++;
			s[a[i][j]] += i;
		}
	}
	rep(i, N) {
		s[i] = 0;
		cnt[i] = 0;
	}
	rep(j, m) {
		rep(i, n) {
			ans += (j*cnt[a[i][j]]) - s[a[i][j]];
			cnt[a[i][j]]++;
			s[a[i][j]] += j;
		}
	}

	cout << ans << endl;
	return 0;
}
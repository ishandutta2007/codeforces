#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;

const ll MX = 1e9 + 1000;
const int K = 500000;

const ll K2 = MX / K + 10;

int n;
ll k;
ll a[1200];
vector < pair<ll, pair<ll, ll> > > vv;
map<ll, pair<ll, ll> > mm;

ll get(ll d, ll a) {
	ll g = a % d;
	if (g)
		return d - g;
	else
		return 0;
}
int main() {
	cout.setf(ios::fixed); cout.precision(15);
#ifdef LOCAL
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	ll go = 0;
	for (int i = 0; i < n; ++i)
		go += a[n - 1] - a[i];
	if (go <= k) {
		cout << a[n - 1] + (k - go) / n << "\n";
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i <= K; ++i) {
		ll cur = 0;
		for (int j = 0; j < n; ++j) {
			ll g = a[j] % i;
			if (g)
				cur += i - g;
		}
		if (cur <= k) {
			ans = max(ans, (ll)i);
		}
	}
	

	for (int i = 0; i < n; ++i) {
		for (ll x = 0; x <= min(K2, a[i]); ++x) {
			ll l = a[i] / (x + 1) + 1;
			ll r;
			if (x == 0)
				r = MX;
			else
				r = a[i] / x;
			if (l > r)
				continue;
			if (l < r) {
				mm[l].first += get(l, a[i]);
				mm[l].second += x + 1;
				mm[r - 1].second -= x + 1;
				mm[r].first -= get(r - 1, a[i]);
			}
			mm[r].first += get(r, a[i]);
			mm[r + 1].first -= get(r, a[i]);
		}
	}
	for (auto x : mm) {
		vv.push_back(x);
	}
	ll d = 0;
	ll now = 0;
	ll ans2 = 0;

	for (int i = 0; i < vv.size() - 1; ++i) {
		now += vv[i].second.first;
		now += d;
		d += vv[i].second.second;
		if (d > 0) {
			if (now <= k) {
				ans2 = max(ans2, vv[i].first);
				ans2 = max(ans2, min(vv[i].first + (k - now) / d, vv[i + 1].first - 1));
			}
		}
		else if (d < 0) {
			ll go = vv[i + 1].first - 1;
			if (now + d * (go - vv[i].first) <= k)
				ans2 = max(ans2, go);
		}
		else {
			if (now <= k) {
				ans2 = max(ans2, vv[i].first);
				ans2 = max(ans2, vv[i + 1].first - 1);
			}
		}
		ll go = vv[i + 1].first - vv[i].first - 1;
		now += d * go;
	}
	if (ans2 > K) {
		ans = max(ans, ans2);
	}
	cout << ans << "\n";
	return 0;
}
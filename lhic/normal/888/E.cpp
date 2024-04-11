#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

vector<ll> v1;
vector<ll> v2;
ll m;
ll a[40];
int n;

void run(int l, int r, vector<ll> &vv, ll now) {
	if (l == r) {
		vv.push_back(now);
		return;
	}
	run(l + 1, r, vv, now);
	now += a[l];
	if (now >= m)
		now -= m;
	run(l + 1, r, vv, now);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] %= m;
	}
	int go = n / 2;
	run(0, go, v1, 0);
	run(go, n, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll ans = 0;
	if (v1.size())
		ans = max(ans, v1.back());
	if (v2.size())
		ans = max(ans, v2.back());
	reverse(v2.begin(), v2.end());
	int now = 0;
	for (ll i: v1) {
		while (now < v2.size() && v2[now] + i >= m)
			++now;
		if (now < v2.size())
			ans = max(ans, i + v2[now]);
	}
	cout << ans << "\n";
	return 0;
}
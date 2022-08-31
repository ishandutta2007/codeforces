#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define DBN(n) cerr << #n << "=" << n << "\n";
#define DB(n) cerr << #n << "=" << n << " ";
#define FI(n) for (int i = 0; i < (n); ++i)
#define FJ(n) for (int j = 0; j < (n); ++j)
#define FK(n) for (int k = 0; k < (n); ++k)
#define FQ(n) for (int q = 0; q < (n); ++q)

using ll = long long;

int a[101];
	int n;
	ll k;

bool check(int d) {
	ll s = 0;
	for (int i = 0; i < n; ++i) {
		int f = a[i] / d * d;
		if (f != a[i]) {
			f += d;
		}
		s += f - a[i];
	}
	return s <= k;
}
int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	ll ans = 1;
	FI(n) {
		cin >> a[i];
	}
	const int T = 100000;
	for (int j = 2; j <= T; ++j) {
		if (check(j)) {
			ans = j;
		}
	}
	FI(n) {
		for (int j = 2; j <= 40000; ++j) {
			int t = a[i] / j;
			if (t > j && t > T && t * j == a[i]) {
				if (check(t)) {
					ans = max(ans, (ll)t);
				}
			}
		}
		if (check(a[i])) {
			ans = max(ans, (ll)a[i]);
		}
	}
	vector<ll> v;
	FI(n) {
		int x = a[i];
		for (int d = 1; d * d <= x; ++d) {
			int from = x / d;
			if (from + 1 > T) {
				v.push_back(from + 1);
			}
		}
	}
	sort(v.begin(), v.end());
	v.push_back(2e11);
	FI(n) {
		k += a[i];
	}
	ll z = 0;
	FI(n) {
		z += a[i] / T + 1;
	}
	ll cur = T;
	for (int i = 0; i < v.size(); ++i) {
		ll next = v[i];
		if (next != cur) {
			ll w = k / z;
			if (w >= cur) {
				ans = max(ans, min(next - 1, w));
			}
		}
		cur = next;
		--z;
	}
	cout << ans << endl;
	
	return 0;
}
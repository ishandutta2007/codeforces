#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	vector<int> cou(n+1, 0), nxt(n+1, n);
	for (int i = 0; i < n; ++i) cou[i+1] = cou[i] + (str[i] == '1');
	for (int i = n-1; i >= 0; --i) nxt[i] = (str[i] == '1' ? i : nxt[i+1]);
	int h = min(n, 200);

	// interval [a, b] works with multiplier k if k * ones[a] - a == k * ones[b] - b
	// for k <= sqrt(n), calculate k * ones[i] - i for all
	// for k > sqrt(n), the intervals can contain at most sqrt(n) ones
	
	ll res = 0;
	for (int k = 1; k <= h; ++k) {
		vector<ll> vals(n+1);
		for (int i = 0; i <= n; ++i) vals[i] = (ll)k * cou[i] - i;
		sort(vals.begin(), vals.end());

		for (int i = 0; i < n;) {
			int j = i+1;
			while(j <= n && vals[i] == vals[j]) ++j;
			ll d = j-i;
			res += d * (d-1) / 2;
			i = j;
		}
	}

	for (int a = 0; a < n; ++a) {
		int b = nxt[a];
		for (int c = 1; b < n; ++c) {
			int bp = nxt[b+1];
			int mx = max(b, a + (h+1) * c - 1);
			if (mx >= n) break; // Happens at least when the set has n/h ones

			// Count number of possible endpoints mx <= t < bp s.t. t-a+1 == 0 (mod c) -> t == a-1 (mod c)
			int d = bp - mx - 1;
			int d0 = (a-1 - mx) % c;
			if (d0 < 0) d0 += c;
			if (d >= d0) res += 1 + (d-d0) / c;
			b = bp;
		}
	}
	cout << res << '\n';
}
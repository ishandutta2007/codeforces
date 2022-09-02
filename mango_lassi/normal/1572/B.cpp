#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void apply(int i, vector<int>& as, vector<int>& ans) {
	int v = as[i] ^ as[i+1] ^ as[i+2];
	as[i] = v;
	as[i + 1] = v;
	as[i + 2] = v;
	ans.push_back(i);
}

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	// Parity of number of ones cannot change
	// Parity of number of zeroes cannot change
	// If input is all ones, impossible

	int oc = 0;
	for (int a : as) {
		if (a == 1) ++oc;
	}

	bool works = 1;
	vector<int> ans;
	if ((oc & 1) || (oc == n)) {
		works = 0;
	} else {
		if (n == 3) {
			if (oc > 0) apply(0, as, ans);
		} else {
			int s = 0;
			while(s < n) {
				while(as[s] == 0) ++s;
				
				int lz = s;
				while(as[lz] && lz < n) ++lz;
				while(((lz - s) % 2) && (lz < n - 1)) {
					apply(lz - 1, as, ans);
					if (as[lz] == 0) --lz;
					else {
						while(as[lz] && lz < n) ++lz;
					}
				}
				if (lz == n) {
					if (s == 0) {
						works = 0;
						break;
					} else {
						for (int i = s-1; i + 2 < n; i += 2) apply(i, as, ans);
						break;
					}
				}
				while(lz > s) {
					apply(lz - 2, as, ans);
					lz -= 2;
				}
			}
		}
	}

	if (works) {
		cout << "YES\n";
		cout << ans.size() << '\n';
		for (int i : ans) cout << i + 1 << ' '; cout << '\n';
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
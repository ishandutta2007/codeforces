#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int nxtBit(int b) {
	return (b == 0 ? 1 : 2*b);
}

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& v : as) cin >> v;

	int res = 0;
	ll invs = 0;
	vector<vector<int>> buckets = {as};
	while(true) {
		int bit = 0;
		for (const vector<int>& vec : buckets) {
			for (auto v : vec) {
				while(nxtBit(bit) <= v) bit = nxtBit(bit);
			}
		}
		if (bit == 0) break;

		ll off0 = 0, off1 = 0;
		vector<vector<int>> nxt_buckets;
		for (const vector<int>& vec : buckets) {
			int n = vec.size();

			ll off = 0;
			vector<int> zero, one;

			for (auto v : vec) {
				if (v & bit) {
					one.push_back(v ^ bit);
				} else {
					zero.push_back(v);
					off += one.size();
				}
			}
			if (! zero.empty()) nxt_buckets.push_back(zero);
			if (! one.empty()) nxt_buckets.push_back(one);

			off0 += off;
			off1 += (ll)zero.size() * (ll)one.size() - off;
		}

		if (off1 < off0) res |= bit;
		invs += min(off0, off1);
		buckets = nxt_buckets;

		/*
		cout << bit << ": " << res << ' ' << off0 << ' ' << off1 << '\n';
		for (auto vec : buckets) {
			cout << "\t";
			for (auto v : vec) cout << v << ' '; cout << '\n';
		}
		*/
	}
	cout << invs << ' ' << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
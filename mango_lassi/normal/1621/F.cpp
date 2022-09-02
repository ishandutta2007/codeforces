#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solveStart(bool p, ll a, ll b, ll c, vector<int>& len0, int zzc, int ooc, int fc, int gc) {
	if (p == 0) {
		// Do operation 2
		if (ooc == 0) return 0;
		return b + solveStart(p ^ 1, a, b, c, len0, zzc, ooc - 1, fc, gc);
	} else {
		ll res = (zzc > 0 ? a : 0);
		if (ooc == 0 && gc > 0) {
			return max(res, -c + solveStart(p ^ 1, a, b, c, len0, zzc, ooc + 1, fc, gc - 1));
		} else if (! len0.empty()) {
			--len0.back();
			if (len0.back() == 1) {
				len0.pop_back();
				++gc;
			}
			return a + solveStart(p ^ 1, a, b, c, len0, zzc - 1, ooc, fc, gc);
		} else if (zzc > 0) {
			return a + solveStart(p ^ 1, a, b, c, len0, zzc - 1, ooc, fc, gc);
		} else if (gc > 0) {
			return max(res, -c + solveStart(p ^ 1, a, b, c, len0, zzc, ooc + 1, fc, gc - 1));
		} else if (fc > 0) {
			return max(res, -c + solveStart(p ^ 1, a, b, c, len0, zzc, ooc, fc - 1, gc));
		} else {
			return res;
		}
	}
}

void solve() {
	int n;
	ll a, b, c;
	cin >> n >> a >> b >> c;

	string str;
	cin >> str;

	bool has_one = 0;
	for (int i = 0; i < str.size(); ++i) has_one |= (str[i] == '1');
	if (! has_one) {
		if (n >= 2) cout << a << '\n';
		else cout << 0 << '\n';
		return;
	}

	vector<int> len0; // Lengths of segments of 0's, not including the first or last segment
	int zzc = 0, ooc = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && str[j] == str[i]) ++j;
		if (str[i] == '0') {
			zzc += (j - i - 1);
			if (i > 0 && j < n) len0.push_back(j - i);
		} else {
			ooc += (j - i - 1);
		}
		i = j;
	}
	sort(len0.rbegin(), len0.rend());
	int gc = 0;
	while(! len0.empty() && len0.back() == 1) {
		++gc;
		len0.pop_back();
	}

	int fc = 0;
	if (str[0] == '0') ++fc;
	if (str.back() == '0') ++fc;

	vector<int> len0_2 = len0;
	ll off0 = solveStart(0, a, b, c, len0, zzc, ooc, fc, gc);
	ll off1 = solveStart(1, a, b, c, len0_2, zzc, ooc, fc, gc);
	cout << max(off0, off1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
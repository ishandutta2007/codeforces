#include <bits/stdc++.h>
using namespace std;

vector<long long> pw(64);

long long solve(long long l,long long r) {
	if (l == r) return l;
	int b = upper_bound(pw.begin(), pw.end(), r) - pw.begin() - 1;
	if (r >= pw[b + 1] - 1) return pw[b + 1] - 1;
	if (l >= pw[b]) return solve(l - pw[b], r - pw[b]) + pw[b];
	return pw[b] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	pw[0] = 1;
	for (int i = 1; i <= 63; ++i) pw[i] = pw[i - 1] + pw[i - 1];
	int q; cin >> q;
	while (q--) {
		long long l, r; cin >> l >> r;
		cout << solve(l, r) << '\n';
	}
}
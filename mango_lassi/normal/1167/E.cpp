#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = (int)1e6;
const int X = 1 + (int)1e6;
int lm[X];
int rm[X];
int hi[N];

int minr(int v) {
	if (rm[v] == -1) return -1;
	return (hi[rm[v]] <= v ? -1 : hi[rm[v]]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// Find for every value its rightmost and leftmost appearance
	// Find for every value the largest value with a more left appearance than its most right appearance
	// Using this, find smallest possible r. Then for every l, find minimum required r.

	int n, x;
	cin >> n >> x;
	for (int i = 0; i <= x; ++i) {
		lm[i] = n;
		rm[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		lm[v] = min(i, lm[v]);
		rm[v] = max(i, rm[v]);
		hi[i] = -1;
	}
	for (int i = 0; i <= x; ++i) {
		if (lm[i] < n) hi[lm[i]] = i;
	}
	for (int i = 1; i < n; ++i) {
		hi[i] = max(hi[i], hi[i-1]);
	}
	
	int r = 1;
	for (int i = x; i >= r; --i) {
		int ri = minr(i);
		if (ri >= i) r = i;
		else r = max(r, ri);
	}

	int ra = -1;
	ll res = 0;
	for (int l = 1; l <= x; ++l) {
		r = max(r, l);
		res += x-r+1;
		if (lm[l] <= ra) break;
		ra = max(ra, rm[l]);
		r = max(r, minr(l));
	}
	cout << res << '\n';
}
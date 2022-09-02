#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n), fst(n+1, n+1);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		fst[as[i]] = min(fst[as[i]], i);
	}

	// Impossible to color as[0]
	// -> look where the last appearance x of value as[0] is. Can definitely color all in range (0, x)
	// 	doing so makes us unable to color x. Is this bad? NO, as if we coloured as[0], we'd have to leave something else in (0, x) uncoloured instead.
	
	int res = 0;
	for (int i = n-1, x = n-1; i >= 0;) {
		x = min(x, fst[as[i]]);
		if (x < i) {
			res += i-x-1;
			int y = x;
			for (int y = x; i > y; --i) x = min(x, fst[as[i]]);
		} else {
			--i;
		}
	}
	cout << res << '\n';
}
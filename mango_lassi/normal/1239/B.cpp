#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 3 * (int)1e5;
ll dp[N+1][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	int c0 = 0;
	for (auto c : str) {
		if (c == ')') ++c0;
	}

	if (2*c0 == n) {
		// Answer is number of occurrences of minimum element
		// By changing two indices, we can decrement a interval by two or increment a interval by two
		// If we increment, we want to increment from first appearance of minimum element to its last appearance,
		// otherwise we can only make the count smaller. If we decrement, we want to decrement between some two appearances
		// of the minimum element, but do not necessarily want to decrement fully.


		int cur = 0;
		int minv = n;
		for (int i = 0; i < n; ++i) {
			cur += (str[i] == '(' ? 1 : -1);
			minv = min(minv, cur);
		}

		ll base = 0;
		for (int i = 0; i < n; ++i) {
			cur += (str[i] == '(' ? 1 : -1);
			if (cur == minv) ++base;
		}

		// Decrement by 2
		pair<ll, pair<int, int>> res = {base, {n-1, n-1}};
		pair<ll, pair<int, int>> off1 = {-n, {-1, -1}};
		pair<ll, pair<int, int>> off2 = {-n, {-1, -1}};
		for (int i = 0; i < n; ++i) {
			cur += (str[i] == '(' ? 1 : -1);
			if (str[i] == '(') {
				off1 = max(off1, {0, {i, -1}});
				off2 = max(off2, {base, {i, -1}});
			} else if (str[i] == ')') {
				off1.second.second = i;
				off2.second.second = i;
				res = max(res, off1);
				res = max(res, off2);
			}
			if (cur == minv) {
				off1 = {-n, {-1, -1}};
				off2 = {-n, {-1, -1}};
			} else if (cur == minv + 1) {
				++off1.first;
				off2 = {-n, {-1, -1}};
			} else if (cur == minv + 2) {
				++off2.first;
			}
		}

		// Increment by 2
		int i0 = n;
		int i1 = -1;
		for (int i = 0; i < n; ++i) {
			cur += (str[i] == '(' ? 1 : -1);
			if (cur == minv) {
				i0 = min(i0, i);
				i1 = max(i1, i);
			}
		}
		if (i1 < n-1) {
			int v1 = 0;
			int v2 = 0;
			for (int i = 0; i < n; ++i) {
				cur += (str[i] == '(' ? 1 : -1);
				if (i < i0 || i1 < i) {
					if (cur == minv + 1) ++v1;
					else if (cur == minv + 2) ++v2;
				} else {
					if (cur == minv) ++v2;
				}
			}

			if (v1 == 0) {
				pair<ll, pair<int, int>> off = {v2, {i0, i1 + 1}};
				res = max(res, off);
			} else {
				pair<ll, pair<int, int>> off = {v1, {i0, i1 + 1}};
				res = max(res, off);

				for (int i = 0; i < n; ++i) {
					cur += (str[i] == '(' ? 1 : -1);
					if (cur == minv + 1) {
						i0 = min(i0, i);
						i1 = max(i1, i);
					}
				}
				if (i1 < n-1) {
					v1 = 0;
					v2 = 0;
					for (int i = 0; i < n; ++i) {
						cur += (str[i] == '(' ? 1 : -1);
						if (i < i0 || i1 < i) {
							if (cur == minv + 1) ++v1;
							else if (cur == minv + 2) ++v2;
						} else {
							if (cur == minv) ++v2;
						}
					}

					off = {v2, {i0, i1 + 1}};
					res = max(res, off);
				}
			}
		}

		cout << res.first << '\n';
		cout << res.second.first+1 << ' ' << res.second.second+1 << '\n';
	} else {
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
	}
}
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long ll;
const ll inf = 1e+9 + 7;
const ll lim = 1000100;
pair<int, int> ar[lim];
int dp[lim];

int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll l, s;
	int i, j, n, k, m, r, a, b, c, x, y, z;
	ll res = 0;
	cin >> n >> l >> k;
	for (i = 0; i < n; ++i) {
		cin >> ar[i].first;
		ar[i].second = i;
	}
	sort(ar, ar + n);

	int ptr;
	for (j = 0; (j < k) && (j < (l + n - 1) / n); ++j) {
		s = !j;
		ptr = 0;
		for (i = 0; i < n; ++i) {
			if (!ptr) {
				s = (s + dp[i]) % inf;
				for (ptr = i; (ptr < n - 1) && (ar[ptr].first == ar[ptr + 1].first); ++ptr)
					s = (s + dp[ptr + 1]) % inf;
				ptr -= i;
				++ptr;
			}
			if (ptr)
				--ptr;
			dp[i] = s;
			res = (res + ll(dp[i]) * ((l / n - j + (ar[i].second < l % n)) % inf)) % inf;
		}
	}

	cout << res;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, ka, kb;
	string s;
	cin >> n >> ka >> kb >> s;

    // sort characters of string by first occurrence
	int p = 0;
	vector<int> id(26, -1);
	vector<char> mp(26);
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		if (id[c] == -1) {
			mp[p] = s[i];
			id[c] = p++;
		}
	}
    // dp arrays for first occurrence, last occurrence, number of occurrences for each bitmask
	vector<int> l(1 << p, n), r(1 << p, -1), count(1 << p);
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		if (l[1 << id[c]] == n) {
			l[1 << id[c]] = i;
        }
		r[1 << id[c]] = i;
		++count[1 << id[c]];
	}

    // dp[mask] = true if it's possible for everything in mask to transform to a common character
	vector<bool> dp(1 << p);
	dp[0] = true;
	for (int m = 0; m < (1 << p); ++m) {
		for (int i = 0, m2 = 0; i < p; ++i) {
			if (m >> i & 1) {
				m2 |= 1 << i;
                // try ways to split the mask along the sorted order
                if(dp[m2] && dp[m ^ m2]) {
                    dp[m] = true;
                }
				l[m] = min(l[m ^ 1 << i], l[1 << i]);
				r[m] = max(r[m ^ 1 << i], r[1 << i]);
				count[m] = count[m ^ 1 << i] + count[1 << i];
			}
        }
        // try ways to root at some vertex in the mask
		for (int i = 0; i < p; ++i) {
			if((m >> i & 1) && dp[m ^ 1 << i] && kb * count[m] >= (r[m] - l[m] + 1) * ka) {
                dp[m] = true;
            }
        }
	}

	set<char> ans;
	for (int i = 0; i < p; ++i) {
		if (dp[((1 << p) - 1) ^ (1 << i)]) {
			ans.insert(mp[i]);
        }
    }

	cout << ans.size();
	for (auto i : ans) cout << " " << i;
	cout << "\n";
}
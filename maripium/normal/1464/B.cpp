#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string S; cin >> S;
	int N = int(S.size());
	int64_t X, Y; cin >> X >> Y;
	if (X > Y) {
		// flip
		for (int i = 0; i < N; ++i) {
			if (S[i] == '0') S[i] = '1';
			else if (S[i] == '1') S[i] = '0';
		}
		swap(X, Y);
	}
	// cout << S << '\n';
	// if different += X
	// if 10 += (Y - X)
	string T = S;
	for (int z = 0; z < N; ++z) if (S[z] == '?') T[z] = '1';
	int64_t cur = 0;
	{
		int num1 = 0;
		for (int z = 0; z < N; ++z) if (T[z] == '1') {
			num1 ++;
		} else cur += num1;
	}
	int64_t ans;
	int pref0 = 0;
	int suff0 = count(T.begin(), T.end(), '0');
	int pref1 = 0;
	int suff1 = count(T.begin(), T.end(), '1');
	ans = X * suff0 * suff1 + (Y-X) * cur;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '0') {
			--suff0;
			++pref0;
		} else if (S[i] == '1') {
			--suff1;
			++pref1;
		} else {
			--suff1;
			cur = cur - suff0 + pref1;
			++pref0;
			ans = min(ans, X * (pref0 + suff0) * (pref1 + suff1) + (Y-X) * cur);
		}
	}
	cout << ans << '\n';
	return 0;
}
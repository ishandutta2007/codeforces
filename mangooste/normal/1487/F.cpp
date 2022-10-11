#include <bits/stdc++.h>
using namespace std;

void setmin(int &a, const int &b) {
	if (a > b) a = b;
}

int main() {
	string s;
	getline(cin, s);
	s = "0" + s;

	int n = s.size();
	constexpr int INF = 1e9, S = 22, F = 10 * (S + 1);
	vector dp(n + 1, vector(2 * F + 1, vector(2 * S + 1, INF)));
	for (int x = -F; x <= F; x++) dp[n][x + F][S] = 0;

	for (int i = n - 1; i >= 0; i--)
		for (int take = -F; take <= F; take++)
			for (int extra = -S; extra <= S; extra++)
				for (int after = -S; after <= S; after++) {
					int need = (s[i] - '0') - after + extra * 10;
					if (abs(need) > F) continue;
					setmin(dp[i][take + F][extra + S], dp[i + 1][need + F][after + S] + abs(need - take) * (n - i));
				}

	cout << dp[0][F][S] << '\n';
}
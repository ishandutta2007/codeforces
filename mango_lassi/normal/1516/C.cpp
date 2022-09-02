#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100;
const int H = 2000 * N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// odd sum -> impossible
	// all even -> divide by two
	// -> 0 or 1 removals

	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];

	bitset<H + 1> dp;
	dp[0] = 1;

	
	for (int i = 1; i <= n; ++i) {
		bitset<H + 1> nxt;
		for (int j = 0; j <= H; ++j) {
			if (dp[abs(j - vals[i-1])]) nxt[j] = 1;
			if (j + vals[i-1] <= H && dp[j + vals[i-1]]) nxt[j] = 1;
		}
		dp = nxt;
	}

	if (dp[0]) {
		int ind = -1;
		while(ind == -1) {
			for (int i = 0; i < n; ++i) {
				if (vals[i] & 1) ind = i;
				else vals[i] /= 2;
			}
		}
		cout << 1 << '\n';
		cout << ind + 1<< '\n';
	} else {
		cout << 0 << '\n';
	}
}
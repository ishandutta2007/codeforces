#include <iostream>

const int N = 200;
const int LOG = 26;
int dp [2][N + 1][N * LOG + 1];
int a[N];
int b[N];

int main() {
	int n, k;
	std::cin >> n >> k;
	
	for (int i = 0; i < n; ++i) {
		long long v;
		std::cin >> v;
		a[i] = 0;
		while(v % 2 == 0) {
			++a[i];
			v /= 2;
		}
		b[i] = 0;
		while(v % 5 == 0) {
			++b[i];
			v /= 5;
		}
		//std::cout << a[i] << ' ' << b[i] << '\n';
	}

	dp[0][0][0] = 1;
	int curr_max = 0;
	int next_max = 0;
	for (int i = 0; i < n; ++i) {
		int curr = i % 2;
		int next = 1 - curr;
		//std::cout << "i: " << i << ' ' << curr << ' ' << next << '\n';
		curr_max = next_max;
		for (int s = std::max(0, i+k-n); (s <= i) && (s <= k); ++s) {
			for (int c = 0; c <= curr_max; ++c) {
				if (dp[curr][s][c]) {
					//std::cout << i << ' ' << s << ' ' << c << ' ' << dp[curr][s][c] << '\n';
					next_max = c+b[i];
					dp[next][s+1][c+b[i]] = dp[curr][s][c] + a[i];
					dp[next][s][c] = std::max(dp[next][s][c], dp[curr][s][c]);
				}
			}
		}
	}

	/*
	for (int i = 0; i < 2; ++i) {
		std::cout << "i=" << i << "\n";
		for (int s = 0; s <= k; ++s) {
			std::cout << "s=" << s << '\n';
			for (int c = 0; c < next_max; ++c) {
				std::cout << dp[i][s][c] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	*/

	int max = 0;
	for (int c = 0; c <= next_max; ++c) {
		max = std::max(max, std::min(c, dp[n % 2][k][c] - 1));
	}
	std::cout << max << '\n';
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const long long N = 55;
const long long B = 111;
const long long inf = 1e15;
long long avs[N];
long long bvs[N];
long long dp[2][N + 1][N * B + 1];

void clear(long long j) {
	for (long long i = 0; i <= N; ++i) {
		for (long long s = 0; s <= N * B; ++s) dp[j][i][s] = inf;
	}
}

int main() {
	long long n;
	std::cin >> n;
	std::vector<std::pair<long long, long long>> els;
	for (long long i = 0; i < n; ++i) std::cin >> avs[i];
	for (long long i = 0; i < n; ++i) std::cin >> bvs[i];
	for (long long i = 0; i < n; ++i) {
		long long a = avs[i];
		long long b = bvs[i];
		els.push_back({-a, -b});
	}
	std::sort(els.begin(), els.end());
	for (long long i = 0; i < n; ++i) {
		els[i] = {-els[i].first, -els[i].second};
	}
	
	clear(0);
	clear(1);
	dp[0][0][0] = 0;
	
	long long bit = 0;
	for (long long s = 0; s < els.size();) {
		long long oth = bit ^ 1;
		clear(oth);

		long long e = s + 1;
		long long pw = els[s].first;
		for (; e < els.size(); ++e) {
			if (els[e].first != pw) break;
		}
		long long len = e - s;
		std::vector<long long> px_sum (len + 1);
		px_sum[0] = 0;
		for (long long i = s; i < e; ++i) {
			px_sum[i - s + 1] = px_sum[i - s] + els[i].second;
		}

		for (long long i = 0; i <= s; ++i) {
			for (long long k = 0; k <= std::min(i, len); ++k) {
				long long ia = i + len - 2 * k;
				for (long long sum = 0; sum <= B * s; ++sum) {
					long long ib = sum + px_sum[len - k];
					long long offer = dp[bit][i][sum] + (len - k) * pw;
					if (offer < dp[oth][ia][ib]) {
						dp[oth][ia][ib] = offer;
					}
				}
			}
		}

		s = e;
		bit ^= 1;
	}

	long long best_pw = inf;
	long long best_proc = 0;
	for (long long i = 0; i <= N; ++i) {
		for (long long sum = 0; sum <= N * B; ++sum) {
			long long pw = dp[bit][i][sum];
			long long proc = sum;
			if ((best_pw == inf) || ((pw < inf) && (best_pw * proc > pw * best_proc))) {
				best_pw = pw;
				best_proc = proc;
			}
		}
	}

	// Prlong long best_pw / best_proc * 1000 rounded up
	long long ab = best_pw * 1000 + (best_proc - 1);
	long long ip = ab / best_proc;
	std::cout << ip << '\n';
}
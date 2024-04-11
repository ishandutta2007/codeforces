#include <iostream>
#include <vector>

const int N = 10;
long long dp[1<<20];
int cou[N];
int ini_mask;

std::vector<int> decode(int mask) {
	std::vector<int> ans (N);
	for (int i = 0; i < N; ++i) {
		ans[i] = mask % (cou[i] + 1);
		mask /= (cou[i] + 1);
	}
	return ans;
}
int encode(const std::vector<int>& ref) {
	int ans = 0;
	for (int i = N-1; i >= 0; --i) {
		ans *= (cou[i] + 1);
		ans += ref[i];
	}
	return ans;
}

long long solve(int mask) {
	if (dp[mask] != -1) return dp[mask];
	std::vector<int> vals = decode(mask);

	// Check base case
	dp[mask] = 1;
	for (int i = 0; i < N; ++i) {
		if (cou[i] && (vals[i] == cou[i])) dp[mask] = 0;
	}
	


	for (int i = (mask == ini_mask ? 1 : 0); i < N; ++i) {
		if (vals[i] > 0) {
			--vals[i];
			dp[mask] += solve(encode(vals));
			++vals[i];
		}
	}
	
	/*
	std::cout << "Solve: ";
	for (int i = 0; i < N; ++i) std::cout << vals[i] << ' '; std::cout << ", ans: " << dp[mask] << "\n";
	*/

	return dp[mask];
}

int main() {
	long long num;
	std::cin >> num;
	
	while(num > 0) {
		++cou[num % N];
		num /= N;
	}

	std::vector<int> ini_state (N);
	for (int i = 0; i < N; ++i) {
		ini_state[i] = cou[i];
	}
	ini_mask = encode(ini_state);

	for (int i = 0; i <= ini_mask; ++i) dp[i] = -1;
	std::cout << solve(ini_mask) << '\n';
}
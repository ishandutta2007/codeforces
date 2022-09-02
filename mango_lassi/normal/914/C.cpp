#include <iostream>
#include <string>

const long long N = 2001;
const long long mod = (1e9) + 7;
long long moves[N];

long long popc(long long num) {
	long long res = 0;
	while(num) {
		if (num & 1) ++res;
		num >>= 1;
	}
	return res;
}

// after i bits, how many have j bits set to one, and are <= than bitstr
long long lebi[N][N];
// -||- but are >
long long mobi[N][N];

int main() {
	moves[1] = 0;
	for (long long i = 2; i < N; ++i) {
		moves[i] = 1 + moves[popc(i)];
	}

	std::string str;
	std::cin >> str;
	long long n = str.size();

	lebi[0][0] = 1;
	mobi[0][0] = 0;
	for (long long i = 0; i < n; ++i) {
		for (long long j = 0; j <= i; ++j) {
			if (str[n-1-i] == '1') {
				// add zero
				lebi[i+1][j] += lebi[i][j] + mobi[i][j];
				lebi[i+1][j] %= mod;
				// add one
				lebi[i+1][j+1] += lebi[i][j];
				lebi[i+1][j+1] %= mod;
				mobi[i+1][j+1] += mobi[i][j];
				mobi[i+1][j+1] %= mod;
			} else {
				// add zero
				lebi[i+1][j] += lebi[i][j];
				lebi[i+1][j] %= mod;
				mobi[i+1][j] += mobi[i][j];
				mobi[i+1][j] %= mod;
				// add one
				mobi[i+1][j+1] += lebi[i][j] + mobi[i][j];
				mobi[i+1][j+1] %= mod;
			}
		}
	}

	long long k;
	std::cin >> k;

	if (k == 0) {
		std::cout << "1\n";
	} else {
		--lebi[n][1];
		long long res = 0;
		for (long long j = 1; j <= n; ++j) {
			if (moves[j] + 1 == k) {
				res += lebi[n][j];
				res %= mod;
			}
		}
		res %= mod;
		std::cout << res << '\n';
	}
}
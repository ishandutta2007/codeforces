#include <iostream>

long long inf = 1e16;
const int N = 1e5;
long long nums[3 * N];
long long vals[3 * N];

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < 3 * n; ++i) {
		std::cin >> nums[i];
	}
	vals[0] = nums[0];
	vals[n] = nums[n] + vals[0];
	vals[2 * n] = nums[2 * n] + vals[n];
	long long max_up = vals[2 * n];
	long long max_down = vals[2 * n];
	long long a, b, c, d;
	for (int x = 1; x < n; ++x) {
		// normal version first
		a = vals[x - 1] + nums[x];
		b = vals[x - 1 + n] + nums[x + n];
		c = vals[x - 1 + 2 * n] + nums[x + 2 * n];
		d = max(b, c + nums[x + n]);
		vals[x + n] = d;
		vals[x] = max(a, d + nums[x]);
		d = max(b, a + nums[x + n]);
		vals[x + n] = max(vals[x + n], d);
		vals[x + 2 * n] = max(c, d + nums[x + 2 * n]);
		// calculate if backwards before
		d = nums[x] + nums[x + n] + nums[x + 2 * n];
		max_down += d;
		max_up += d;
		vals[x] = max(vals[x], max_up);
		vals[x + 2 * n] = max(vals[x + 2 * n], max_down);
		// new max downs and max ups
		max_down = max(max_down, vals[x - 1] + d);
		max_up = max(max_up, vals[x - 1 + 2 * n] + d);
		//std::cout << max_down << " " << max_up << "\n";
	}

	/*	
	for (int y = 0; y <3; ++y) {
		for (int x = 0; x < n; ++x) {
			std::cout << vals[x + y * n] << " ";
		}
		std::cout << "\n";
	}
	*/

	std::cout << vals[3 * n - 1] << "\n";
}
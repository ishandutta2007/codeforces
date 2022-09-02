#include <iostream>
#include <vector>
#include <string>

const int N = 2500;
const int inf = 1e9 + 7;
bool not_prime [N];
int count [N][N];
int w, h;

int get(int x, int y) {
	if ((x < 0) || (y < 0)) return 0;
	if (x >= w) x = w-1;
	if (y >= h) y = h-1;
	return count[x][y];
}

int abs(int v) {
	return v < 0 ? -v : v;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		std::string str;
		std::cin >> str;
		for (int x = 0; x < w; ++x) {
			if (str[x] == '1') {
				++count[x][y];
			}
		}	
	}

	// Find primes below max
	int max = std::max(w, h);
	if (max == 2500) --max;
	std::vector<int> list;
	for (int i = 2; i <= max; ++i) {
		if (! not_prime[i]) {
			for (int j = i * i; j <= max; j += i) {
				not_prime[j] = true;
			}
			list.push_back(i);
		}
	}

	for (int x = 1; x < w; ++x) {
		count[x][0] += count[x-1][0];
	}
	for (int y = 1; y < h; ++y) {
		count[0][y] += count[0][y-1];
	}
	for (int x = 1; x < w; ++x) {
		for (int y = 1; y < h; ++y) {
			count[x][y] += count[x-1][y] + count[x][y-1] - count[x-1][y-1];
		}
	}
	
	int res = inf;
	for (int i = 0; i < list.size(); ++i) {
		int k = list[i];
		int ans = 0;
		for (int x = 0; x * k < w; ++x) {
			int px = x * k - 1;
			int cx = px + k;
			for (int y = 0; y * k < h; ++y) {
				int py = y * k - 1;
				int cy = py + k;
				int amount = get( cx, cy ) - get( cx, py ) - get( px, cy ) + get( px, py );
				ans += std::min(amount, k * k - amount);
			}
		}
		if (ans < res) res = ans;
	}
	std::cout << res << '\n';
}
#include <iostream>
#include <vector>

const int N = 200000;
const long long mod = (1e9) + 7;
std::vector<int> conns [N];
bool handled [N];
bool stuck [N];

// -1 if cycle
// size otherwise, or 1 if handled
long long size(int i, int p) {
	if (stuck[i]) return -2;
	if (handled[i]) return -1;
	handled[i] = true;
	long long total = 1;
	for (int j = 0; j < conns[i].size(); ++j) {
		int t = conns[i][j];
		if (t != p) {
			long long sub = size(t, i);
			if (sub == -1) {
				total = -1;
			} else if (sub == -2) {
				total = -2;
			}
			if (total > 0) {
				total += sub;
			}
		}
	}
	return total;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		if (a == b) {
			stuck[a] = true;
			handled[a] = true;
		} else {
			conns[a].push_back(b);
			conns[b].push_back(a);
		}
	}
	long long res = 1;
	for (int i = 0; i < 2 * n; ++i) {
		if (! handled[i]) {
			long long sub = size(i, i);
			if (sub == -1) sub = 2;
			if (sub == -2) sub = 1;
			res = (res * sub) % mod;
		}
	}
	std::cout << res << '\n';
}
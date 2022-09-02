#include <iostream>
#include <string>

const int N = 100;
int inf = 100;
int flag [N][N];

int main() {
	int w, h;
	std::cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		std::string str;
		std::cin >> str;
		for (int x = 0; x < w; ++x) {
			if (str[x] == 'R') {
				flag[x][y] = -3;
			} else if (str[x] == 'B') {
				flag[x][y] = 1;
			} else if (str[x] == 'G') {
				flag[x][y] = 2;
			} else {
				flag[x][y] = inf;
			}
		}
	}
	bool can = false;
	if (h % 3 == 0) {
		int len = h / 3;
		int total = 0;
		for (int p = 0; p < 3; ++p) {
			int part = flag[0][p * len];
			for (int y = p * len; y < (p+1) * len; ++y) {
				for (int x = 0; x < w; ++x) {
					if (flag[x][y] != part) part = inf;
				}
			}
			total += part;
		}
		if (total == 0) {
			can = true;
		}
	}
	if (w % 3 == 0) {
		int len = w / 3;
		int total = 0;
		for (int p = 0; p < 3; ++p) {
			int part = flag[p * len][0];
			for (int x = p * len; x < (p+1) * len; ++x) {
				for (int y = 0; y < h; ++y) {
					if (flag[x][y] != part) part = inf;
				}
			}
			total += part;
		}
		if (total == 0) {
			can = true;
		}
	}
	if (can) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}
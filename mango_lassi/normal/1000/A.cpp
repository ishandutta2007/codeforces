#include <iostream>
using namespace std;

const int N = 4;
const int M = 3;

int getInd(char c) {
	if (c == 'S') return 0;
	if (c == 'M') return 1;
	if (c == 'L') return 2;
}

int cou[N][M];
int tar[N][M];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		std::string str;
		cin >> str;
		++cou[(int)str.size() - 1][getInd(str.back())];
	}
	for (int i = 0; i < n; ++i) {
		std::string str;
		cin >> str;
		++tar[(int)str.size() - 1][getInd(str.back())];
	}
	int res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			res += std::abs(cou[i][j] - tar[i][j]);
		}
	}
	std::cout << res / 2 << '\n';
}
#include <iostream>
#include <string>

const int N = 1500;
const int M = N+1;
const int C = 26;
int seq [N];
int max [C][M];
int end [C][N][M];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	int q;
	std::cin >> q;

	for (int i = 0; i < n; ++i) {
		seq[i] = ((int)str[i] - (int)'a');
	}

	for (int c = 0; c < C; ++c) {
		end[c][0][0] = (seq[0] == c ? 1 : 0);
		for (int k = 1; k < n+1; ++k) {
			end[c][0][k] = 1;
		}
		for (int i = 1; i < n; ++i) {
			bool eq = (seq[i] == c);
			if (eq) {
				end[c][i][0] = end[c][i-1][0] + 1;
			} else {
				end[c][i][0] = 0;
			}
			for (int k = 1; k < n+1; ++k) {
				if (eq) {
					end[c][i][k] = end[c][i-1][k] + 1;
				} else {
					end[c][i][k] = end[c][i-1][k-1] + 1;
				}
			}
		}
		for (int k = 0; k < n+1; ++k) {
			for (int i = 0; i < n; ++i) {
				max[c][k] = std::max(max[c][k], end[c][i][k]);
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int mi; char ci;
		std::cin >> mi >> ci;
		std::cout << max[(int)ci - (int)'a'][mi] << '\n';
	}
}
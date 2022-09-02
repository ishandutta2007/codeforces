#include <iostream>

const int N = 12;
std::pair<int, int> comms[2][N];
bool first_match[2][N];
bool second_match[2][N];

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		if (b < a) std::swap(a, b);
		comms[0][i] = {a, b};
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		if (b < a) std::swap(a, b);
		comms[1][i] = {a, b};
	}
	int var_swaps = 0;
	int match_var = -100;
	for (int ia = 0; ia < n; ++ia) {
		for (int ib = 0; ib < m; ++ib) {
			if (comms[0][ia] == comms[1][ib]) continue;
			if (comms[0][ia].first == comms[1][ib].first) {
				first_match[0][ia] = true;
				first_match[1][ib] = true;
				if (match_var != comms[0][ia].first) {
					match_var = comms[0][ia].first;
					++var_swaps;
				}
			}
			if (comms[0][ia].first == comms[1][ib].second) {
				first_match[0][ia] = true;
				second_match[1][ib] = true;
				if (match_var != comms[0][ia].first) {
					match_var = comms[0][ia].first;
					++var_swaps;
				}
			}
			if (comms[0][ia].second == comms[1][ib].first) {
				second_match[0][ia] = true;
				first_match[1][ib] = true;
				if (match_var != comms[0][ia].second) {
					match_var = comms[0][ia].second;
					++var_swaps;
				}
			}
			if (comms[0][ia].second == comms[1][ib].second) {
				second_match[0][ia] = true;
				second_match[1][ib] = true;
				if (match_var != comms[0][ia].second) {
					match_var = comms[0][ia].second;
					++var_swaps;
				}
			}
		}
	}
	bool match_both = false;
	for (int ia = 0; ia < n; ++ia) {
		if (first_match[0][ia] && second_match[0][ia]) match_both = true;
	}
	for (int ib = 0; ib < m; ++ib) {
		if (first_match[1][ib] && second_match[1][ib]) match_both = true;
	}
	if (var_swaps <= 1) {
		std::cout << match_var << '\n';
	} else {
		if (match_both) {
			std::cout << "-1\n";
		} else {
			std::cout << "0\n";
		}
	}
}
#include <iostream>


const int N = 50;
int first[2*N];
int second[N];

int main() {
	int n, l;
	std::cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		std::cin >> first[i];
		first[i + n] = first[i] + l;
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> second[i];
	}

	bool same = false;
	for (int i = 0; i < n; ++i) {
		int dist = first[i] - second[0];
		bool success = true;
		for (int k = 0; k < n; ++k) {
			if (first[i + k] - second[k] != dist) {
				success = false;
				break;
			}
		}
		if (success) {
			same = true;
			break;
		}
	}
	if (same) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}
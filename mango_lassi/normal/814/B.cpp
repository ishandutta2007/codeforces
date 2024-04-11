#include <iostream>
#include <vector>

const int N = 1000;
int a [N];
int b [N];
int seq [N];
bool ban [N + 1];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	for (int i = 0 ; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	for (int i = 1; i <= n; ++i) {
		ban[i] = false;
	}
	std::vector<int> noteq;
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) {
			ban[a[i]] = true;
			seq[i] = a[i];
		} else {
			noteq.push_back(i);
		}
	}
	if (noteq.size() == 2) {
		if (ban[a[noteq[0]]]) {
			seq[noteq[0]] = b[noteq[0]];
			seq[noteq[1]] = a[noteq[1]];
		} else if (ban[b[noteq[0]]]) {
			seq[noteq[0]] = a[noteq[0]];
			seq[noteq[1]] = b[noteq[1]];
		} else if (ban[a[noteq[1]]]) {
			seq[noteq[0]] = a[noteq[0]];
			seq[noteq[1]] = b[noteq[1]];
		} else {
			seq[noteq[0]] = b[noteq[0]];
			seq[noteq[1]] = a[noteq[1]];
		}
		for (int i = 0; i < n; ++i) {
			std::cout << seq[i] << ' ';
		}
		std::cout << '\n';
	} else {
		int fill = 0;
		for (int i = 1; i <= n; ++i) {
			if (! ban[i]) {
				fill = i;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (seq[i] == 0) {
				std::cout << fill << ' ';
			} else {
				std::cout << seq[i] << ' ';
			}
		}
		std::cout << '\n';
	}
}
#include <iostream>
#include <string>

const int N = 1e5;
int forward[N + 1];
int backward[N + 1];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string a; std::string b;
	std::cin >> a >> b;

	int ind = 0;
	forward[0] = -1;
	for (int i = 0; i < b.size(); ++i) {
		while((ind < a.size()) && (a[ind] != b[i])) {
			++ind;
		}
		forward[i+1] = ind;
		++ind;
	}
	ind = a.size() - 1;
	backward[b.size()] = a.size();
	for (int i = b.size() - 1; i >= 0; --i) {
		while((ind >= 0) && (a[ind] != b[i])) {
			--ind;
		}
		backward[i] = ind;
		--ind;
	}
	int start = 0;
	int length = b.size();
	ind = 0;
	for (int i = 0; i <= b.size(); ++i) {
		if ((int)a.size() <= forward[i]) { break; }
		while((ind < i) || ((ind <= b.size()) && (forward[i] >= backward[ind]))) {
			++ind;
		}
		int len = ind - i;
		if (len < length) {
			length = len;
			start = i;
		}
	}
	if (length == b.size()) {
		std::cout << "-\n";
	} else {
		for (int i = 0; i < start; ++i) {
			std::cout << b[i];
		}	
		for (int i = start + length; i < b.size(); ++i) {
			std::cout << b[i];
		}
		std::cout << "\n";
	}
}
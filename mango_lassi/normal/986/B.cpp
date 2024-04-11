#include <iostream>

const int N = 10 + (1e6);
int vals[N];
int fenw[N];

void add(int i) {
	while(i < N) {
		++fenw[i];
		i += (i & -i);
	}
}
int sum(int i) {
	int res = 0;
	while(i > 0) {
		res += fenw[i];
		i -= (i & -i);
	}
	return res;
}


int main() {
	int n;
	std::cin >> n;
	long long invs = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> vals[i];
		add(vals[i]);
		invs += vals[i] - sum(vals[i]);
	}
	if ((invs % 2) == (n % 2)) {
		std::cout << "Petr\n";
	} else {
		std::cout << "Um_nik\n";
	}
}
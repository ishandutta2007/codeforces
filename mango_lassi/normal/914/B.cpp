#include <iostream>
using namespace std;

// exists a odd amount of some number:
const int N = (1e5) + 1;
int count[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++count[v];
	}
	bool conan = false;
	for (int i = 0; i < N; ++i) {
		if (count[i] & 1) conan = true;
	}
	if (conan) {
		cout << "Conan\n";
	} else {
		cout << "Agasa\n";
	}
}
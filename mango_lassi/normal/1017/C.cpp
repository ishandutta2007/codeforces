#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = (int)sqrt(n);
	if (a == 0) a = 1;
	for (int i = 0; i < n; i += a) {
		int len = min(n-i, a);
		for (int j = 0; j < len; ++j) {
			cout << i + len - j << ' ';
		}
	}
	cout << '\n';
}
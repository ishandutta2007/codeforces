
#include <iostream>

using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		n = (n % 10 ? n - 1 : n / 10);
	}
	cout << n;
}
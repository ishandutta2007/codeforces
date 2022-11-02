#include <iostream>

using namespace std;

int main() {
	int n = 1000;
	cout << 2*n+1 << "\n";
	for (int i = 1; i <= n; i++) {
		cout << i << " " << 1 << " " << i << " " << 2 << "\n";
	}
	cout << "1 1 1 2\n";
	for (int i = 1; i <= n; i++) {
		cout << i << " " << 1 << " " << i << " " << 2 << "\n";
	}
}
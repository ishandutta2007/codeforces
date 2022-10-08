#include <iostream>

using namespace std;

long long T, l, r;

int main() {
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> l >> r;
		cout << l << " " << 2 * l << endl;
	}
}
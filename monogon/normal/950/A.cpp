#include <iostream>

using namespace std;

int l, r, a;

int main() {
	cin >> l >> r >> a;
	int x = min(l, r);
	int y = min(abs(l - r), a);
	cout << 2 * (x + y + (a - y) / 2) << endl;
}
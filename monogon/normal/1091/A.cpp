#include <iostream>
#include <algorithm>

using namespace std;

int y, b, r;

int main() {
	cin >> y >> b >> r;
	cout << min(min(3 * y + 3, 3 * b), 3 * r - 3) << endl;
}
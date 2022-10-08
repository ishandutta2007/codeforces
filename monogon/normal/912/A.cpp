#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, x, y, z;

int main() {
	cin >> a >> b >> x >> y >> z;
	long long a2 = 2 * x + y;
	long long b2 = y + 3 * z;
	cout << (a2 > a ? a2 - a : 0) + (b2 > b ? b2 - b : 0) << endl;
}
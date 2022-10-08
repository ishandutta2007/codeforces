
#include <iostream>

using namespace std;

int n, m, a, x, y;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a;
		x += (a % 2);
	}
	for(int j = 0; j < m; j++) {
		cin >> a;
		y += (a % 2);
	}
	cout << (min(n - x, y) + min(m - y, x)) << endl;
}
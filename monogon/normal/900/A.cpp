#include <iostream>

using namespace std;

int n, x, y;
int l, r;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		l += (x < 0);
		r += (x > 0);
	}
	cout << (l <= 1 || r <= 1 ? "Yes" : "No") << endl;
}
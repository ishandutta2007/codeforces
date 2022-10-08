#include <iostream>

using namespace std;

int n, m, l, r, points;
bool b[100];

int main() {
	cin >> n >> m;
	points = m;
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		for(int j = l - 1; j < r; j++) {
			points -= !b[j];
			b[j] = true;
		}
	}
	cout << points << endl;
	for(int i = 0; i < m; i++) {
		if(!b[i]) {
			cout << (i + 1) << " ";
		}
	}
}

#include <iostream>

using namespace std;

int n, h, m, l, r, x;
int a[50];

int main() {
	cin >> n >> h >> m;
	for(int i = 0; i < n; i++) {
		a[i] = h;
	}
	for(int i = 0; i < m; i++) {
		cin >> l >> r >> x;
		for(int j = l - 1; j < r; j++) {
			a[j] = min(a[j], x);
		}
	}
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i] * a[i];
	}
	cout << sum << endl;
}
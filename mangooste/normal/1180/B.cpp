#include <iostream>
using namespace std;

int main() {
	int n, m = 0, i; cin >> n;
	int l[n];
	for (int k = 0; k < n; k++) {
		cin >> l[k];
		if (l[k] >= 0) l[k] = -l[k] - 1;
		if (l[k] < m) { m = l[k]; i = k; }
	}
	if (n % 2) l[i] = -l[i] - 1;
	for (int k = 0; k < n; k++) {
		cout << l[k] << ' ';
	}
}
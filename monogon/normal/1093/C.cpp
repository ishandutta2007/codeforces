#include <iostream>

using namespace std;

int n;
long long b[100000];
long long a[200000];

int main() {
	// max(a[i-1], b[i] - a[n-i-1])
	cin >> n >> b[0];
	a[0] = 0;
	a[n - 1] = b[0];
	for(int i = 1; i < n / 2; i++) {
		cin >> b[i];
		a[i] = max(a[i - 1], b[i] - a[n - i]);
		a[n - i - 1] = b[i] - a[i];
	}
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
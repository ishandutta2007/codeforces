#include <iostream>
#include <assert.h>
using namespace std;

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	int min = (n < m)? n : m;
	int k = min + 1;
	cout << k << endl;
	if (n < m) {
		for (int i = 0; i < k; i++) {
			cout << i << " " << m-i << endl;
		}
	}
	else {
		for (int i = 0; i < k; i++) {
			cout << i << " " << m-i << endl;
		}
	}
	return 0;
}
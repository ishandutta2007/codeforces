#include <iostream>
#include <string>
using namespace std;

const int L = 2222;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = L-1; i >= 0; --i) {
		if (i & 1) {
			if (i+1 < L) cout << "0";
		} else {
			cout << "9";
		}
	}
	cout << "9\n";

	for (int i = L-1; i >= 0; --i) {
		if (i & 1) {
			cout << "9";
		} else {
			if (i+1 < L) cout << "0";
		}
	}
	cout << "1\n";
}
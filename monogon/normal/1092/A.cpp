#include <iostream>

using namespace std;

int t, n, k;

int main() {
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n >> k;
		for(int j = 0; j < n; j++) {
			cout << (char) ('a' + (j % k));
		}
		cout << endl;
	}
}
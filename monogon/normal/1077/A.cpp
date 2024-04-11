#include <iostream>

using namespace std;

long long t, a, b, k;

int main() {
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> a >> b >> k;
		cout << (a * ((k + 1) / 2) - b * (k / 2)) << endl;
	}
}
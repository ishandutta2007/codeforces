#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
	cin >> n;
	for(int i = n / 2; i >= 1; i--) {
		if(__gcd(i, n - i) == 1) {
			cout << i << " " << (n - i) << endl;
			return 0;
		}
	}
}
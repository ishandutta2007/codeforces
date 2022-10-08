#include <iostream>

using namespace std;

int n, k, a, best = 1;

int main() {
	cin >> k >> n;
	for(int i = 0; i < k; i++) {
		cin >> a;
		if(n % a == 0 && a > best) {
			best = a;
		}
	}
	cout << (n / best) << endl;
}
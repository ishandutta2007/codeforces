#include <iostream>

using namespace std;

long long n, m, a, r;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a;
		cout << ((a + r) / m) << " ";
		r = (a + r) % m;
	}
}
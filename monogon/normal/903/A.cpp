#include <iostream>

using namespace std;

int n, x;

bool chicken(int x) {
	return x % 3 == 0 || (x >= 7 && chicken(x - 7));
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		cout << (chicken(x) ? "YES" : "NO") << endl;
	}
}
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		if (!((n - i) % 2) && !(((n - i) / 2 + i) % m)) {
			cout << (n - i) / 2 + i;
			return 0;
		}

	cout << -1;
	return 0;
}
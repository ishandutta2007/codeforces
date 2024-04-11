#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (m * a <= b)
		cout << a * n;
	else {
		int res = (n / m) * b;
		n %= m;
		if (a * n <= b)
			res += a * n;
		else
			res += b;
		cout << res;
	}
	return 0;
}
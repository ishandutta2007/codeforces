#include <iostream>
#include <cstdlib>
//#include <vector>
using namespace std;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (!(x % i))
			return false;
	return true;
}

long long modpow(int base, int pow, int mod) {
	if (pow == 0)
		return 1;
	if (pow & 1)
		return base * modpow(base, pow - 1, mod) % mod;
	long long res = modpow(base, pow / 2, mod);
	return res * res % mod;
}

int main() {
	int n;
	cin >> n;
	//vector<bool> here(n, false);
	if (n == 4) {
		cout << "YES\n1\n3\n2\n4";
		return 0;
	}

	if (!isPrime(n)) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		int res = (i == 0 ? 1 : (i == n - 1 ? n : (modpow(i, n - 2, n) * (i + 1) % n)));
		cout << res << '\n';
		//if (here[res - 1])
		//	cout << res << '\n';
		//here[res - 1] = true;
	}

	return 0;
}
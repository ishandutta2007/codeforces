#include <iostream>
#include <cstdlib>
using namespace std;

long long amount(long long n) {
	return n * (n - 1) / 2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long n, m;
	cin >> n >> m;
	cout << amount(n / m + 1) * (n % m) + amount(n / m) * (m - (n % m)) << ' ' << amount(n - m + 1);
}
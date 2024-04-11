#include <iostream>

using namespace std;

long long n;

int main() {
	cin >> n;
	cout << (n % 3 == 0 ? "1 1 " : n % 3 == 1 ? "1 2 " : "2 2 ") << (n - (n % 3) - 2) << endl;
}
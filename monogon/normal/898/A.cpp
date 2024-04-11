#include <iostream>
#include <cmath>

using namespace std;

int n;

int main() {
	cin >> n;
	cout << (int) (10 * round(n / 10.0)) << endl;
}
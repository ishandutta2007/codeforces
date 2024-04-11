
#include <iostream>

using namespace std;

int n;

int f(int m) {
	m++;
	while(m % 10 == 0) {
		m /= 10;
	}
	return m;
}

int main() {
	cin >> n;
	int count = 0;
	while(n >= 10) {
		count++;
		n = f(n);
	}
	cout << (count + 9) << std::endl;
}
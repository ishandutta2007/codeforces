#include <iostream>

using namespace std;

long long n, a;
long long m1, m2;

int main() {
	cin >> n;
	cin >> a;
	m1 = m2 = a;
	for(int i = 1; i < n; i++) {
		cin >> a;
		m1 = min(a, m1);
		m2 = max(a, m2);
	}
	cout << (m2 - m1 + 1 - n) << endl;
}
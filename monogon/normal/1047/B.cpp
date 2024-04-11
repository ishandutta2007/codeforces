#include <iostream>

using namespace std;

int n;
long long a, b, m;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		m = max(m, a + b);
	}
	cout << m << endl;
}
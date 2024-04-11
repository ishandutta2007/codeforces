#include <iostream>

using namespace std;

int n, a, b, x, A;

int main() {
	cin >> n >> a;
	A++;
	for(int i = 1; i < n; i++) {
		cin >> x;
		A += (x == a);
		if(x != a && b == 0) {
			b = x;
		}else if(x != a && b > 0 && x != b) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if(a > 0 && b > 0 && A == n / 2) {
		cout << "YES" << endl << a << " " << b << endl;
	}else {
		cout << "NO" << endl;
	}
}
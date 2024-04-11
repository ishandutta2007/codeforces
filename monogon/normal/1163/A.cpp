
#include <iostream>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	if(m == 0) {
		cout << 1 << endl;
	}else if(m <= n / 2) {
		cout << m << endl;
	}else {
		cout << (n - m) << endl;
	}
}
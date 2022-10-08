
#include <iostream>

using namespace std;

int n;
long long a;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		cout << (a % 2 ? a : a - 1) << " ";
	}
	cout << endl;
}
#include <iostream>

using namespace std;

int n;
bool b[1000];

int main() {
	cin >> n;
	int f1 = 1;
	int f2 = 1;
	while(f1 <= n) {
		b[f1 - 1] = true;
		int temp = f1 + f2;
		f1 = f2;
		f2 = temp;
	}
	for (int i = 0; i < n; ++i) {
		cout << (b[i] ? 'O' : 'o');
	}
	cout << endl;
}
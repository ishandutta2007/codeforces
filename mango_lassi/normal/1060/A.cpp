#include <iostream>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n >> str;
	int eg = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '8') ++eg;
	}
	cout << min(eg, n / 11) << '\n';
}
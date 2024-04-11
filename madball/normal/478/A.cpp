#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sum = 0, cur;
	for (int i = 0; i < 5; i++) {
		cin >> cur;
		sum += cur;
	}
	if ((sum % 5) || (sum == 0))
		cout << -1;
	else
		cout << sum / 5;
	return 0;
}
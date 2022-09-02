#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int res = 0;
	while(((1<<res) - 1) < n) ++res;
	cout << res << '\n';
}
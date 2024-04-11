#include <iostream>
#include <cmath>

using namespace std;

int n, a, sum;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		sum += abs(a);
	}
	cout << sum << endl;
}
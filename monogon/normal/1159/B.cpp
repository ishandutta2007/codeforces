
#include <iostream>

using namespace std;

int n;
long long a, k;

int main() {
	cin >> n;
	k = 1e9;
	for(int i = 0; i < n; i++) {
		cin >> a;
		k = min(k, a / max(i, n - i - 1));
	}
	cout << k << endl;
}
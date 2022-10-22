#include <bits/stdc++.h>

using namespace std;

long long n, m;
int main() {
	cin >> n >> m;
	if (m == 1) {
		cout << n - 1 << '\n';
	}
	else {
		cout << n * (m - 1) << '\n';
	}
}
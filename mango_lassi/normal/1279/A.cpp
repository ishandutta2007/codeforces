#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= b + c + 1 && b <= a + c + 1 && c <= a + b + 1) cout << "Yes\n";
		else cout << "No\n";
	}
}
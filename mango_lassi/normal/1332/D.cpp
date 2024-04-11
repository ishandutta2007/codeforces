#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int H = 1 << 17;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	int x = k | H;

	cout << 3 << ' ' << 3 << '\n';
	cout << x << ' ' << x << ' ' << k << '\n';
	cout << x << ' ' << H << ' ' << x << '\n';
	cout << k << ' ' << x << ' ' << k << '\n';
}
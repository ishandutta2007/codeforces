#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int ta, tb;
	for (int i = 0; i < k; ++i) cin >> ta >> tb;
	for (int i = 0; i < k; ++i) cin >> ta >> tb;

	cout << (n-1) + (m-1) + n*m << '\n';
	for (int i = 0; i < n-1; ++i) cout << "U";
	for (int i = 0; i < m-1; ++i) cout << "L";

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m-1; ++x) cout << ((y & 1) ? "L" : "R");
		cout << "D";
	}
	cout << '\n';
}
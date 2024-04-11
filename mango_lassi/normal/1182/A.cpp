#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 1) cout << 0 << '\n';
	else cout << (1ll << (n/2)) << '\n';
}
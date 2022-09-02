#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int cou(int v) {
	int res = 0;
	while(v > 0) {
		res += (v % 10) % 4;
		v /= 10;
	}
	return res % 4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while(cou(n) != 0) ++n;
	cout << n << '\n';
}
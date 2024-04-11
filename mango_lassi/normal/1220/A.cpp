#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	int zc = 0;
	int nc = 0;
	for (auto c : str) {
		if (c == 'z') ++zc;
		if (c == 'n') ++nc;
	}
	for (int i = 0; i < nc; ++i) cout << 1 << ' ';
	for (int i = 0; i < zc; ++i) cout << 0 << ' ';
	cout << '\n';
}
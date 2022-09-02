#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, ini;
	cin >> n >> ini;

	int sum1 = ini;
	int sum2 = ini;
	vector<int> res = {1};
	for (int i = 1; i < n; ++i) {
		int c;
		cin >> c;
		if (2*c <= ini) {
			res.push_back(i+1);
			sum1 += c;
		}
		sum2 += c;
	}
	if (sum1 * 2 > sum2) {
		cout << res.size() << '\n';
		for (auto i : res) cout << i << ' '; cout << '\n';
	} else {
		cout << "0\n";
	}
}
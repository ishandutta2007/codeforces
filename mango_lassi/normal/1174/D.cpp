#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	vector<bool> bans(1<<N, false);
	bans[x] = true;
	bans[0] = true;

	vector<int> res;
	for (int i = 1; i < (1<<n); ++i) {
		if (! bans[i]) {
			res.push_back(i);
			bans[i] = true;
			bans[i ^ x] = true;
		}
	}
	cout << res.size() << '\n';
	int xv = 0;
	for (auto v : res) {
		cout << (xv ^ v) << ' ';
		xv = v;
	}
	cout << '\n';
}
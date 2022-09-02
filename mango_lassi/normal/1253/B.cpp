#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int M = 1e6;
int lst[M];
bool act[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < M; ++i) lst[i] = -1;

	int cou = 0;
	bool fail = false;
	vector<int> res = {0};
	for (int i = 0; i < n; ++i) {
		int j = abs(as[i]) - 1;
		if (as[i] > 0) {
			if (lst[j] >= i - res.back() || act[j]) fail = true;
			++cou;
		} else {
			if (! act[j]) fail = true;
			--cou;
		}
		lst[j] = i;
		act[j] ^= 1;

		++res.back();
		if (cou == 0) res.push_back(0);
	}
	if (cou != 0) fail = true;

	if (fail) {
		cout << -1 << '\n';
	} else {
		res.pop_back();
		cout << res.size() << '\n';
		for (auto c : res) cout << c << ' '; cout << '\n';
	}
}
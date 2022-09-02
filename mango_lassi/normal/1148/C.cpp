#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<pair<int, int>> res;
vector<int> cur;
vector<int> per;

void makeSwap(int i, int j) {
	swap(per[i], per[j]);
	cur[per[i]] = i;
	cur[per[j]] = j;
	res.push_back({i, j});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Sort last half expect last using first element
	// Sort first half expect first using last element
	// Sort first and last element

	int n;
	cin >> n;
	int h = n / 2;

	cur.resize(n, 0);
	per.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> per[i];
		--per[i];
		cur[per[i]] = i;
	}
	for (int i = 1; i < h; ++i) {
		if (cur[i] >= h) makeSwap(cur[i], 0);
		if (cur[i] < h) makeSwap(cur[i], n-1);
		makeSwap(cur[i], i);
	}
	for (int i = h; i < n-1; ++i) {
		if (cur[i] < h) makeSwap(cur[i], n-1);
		if (cur[i] >= h) makeSwap(cur[i], 0);
		makeSwap(cur[i], i);
	}
	if (per[0] != 0) makeSwap(0, n-1);

	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first+1 << ' ' << pr.second+1 << '\n';
}
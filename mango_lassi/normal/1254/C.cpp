#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll askArea(int i, int j, int k) {
	cout << 1 << ' ' << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
	ll res;
	cin >> res;
	return res;
}
int askSign(int i, int j, int k) {
	cout << 2 << ' ' << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	int n;
	cin >> n;

	// t1: ask abs(ai x aj + aj x ak + ak x ai)
	// t2: ask sign((aj - ai) x (ak - ai))

	// 1. Find last in n queries
	// 2. Query areas of 1, last, x for all x Sort into increasing and decreasing sides. 
	// 3. Query for every point whether it is to the left or right of furthest away point

	int lst = 1;
	for (int i = 2; i < n; ++i) {
		if (askSign(0, lst, i) > 0) lst = i;
	}
	vector<pair<ll, int>> ord;
	for (int i = 1; i < n; ++i) {
		if (i == lst) continue;
		ll d = askArea(0, lst, i);
		ord.push_back({d, i});
	}
	sort(ord.begin(), ord.end());

	vector<int> le = {lst}, ri = {0};
	int turn = ord.back().second;
	for (auto pr : ord) {
		if (pr.second == turn) continue;
		if (askSign(0, turn, pr.second) == 1) le.push_back(pr.second);
		else ri.push_back(pr.second);
	}
	reverse(le.begin(), le.end());
	ri.push_back(turn);

	cout << 0;
	for (auto v : ri) cout << ' ' << v+1;
	for (auto v : le) cout << ' ' << v+1;
	cout << endl;
}
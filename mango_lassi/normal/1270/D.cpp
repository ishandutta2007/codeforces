#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

pair<int, int> ask(const vector<int>& vec, int ban) {
	cout << "?";
	for (auto v : vec) {
		if (v == ban) continue;
		else cout << ' ' << v+1;
	}
	cout << endl;

	pair<int, int> res;
	cin >> res.first >> res.second;
	--res.first;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> que(k+1), vals(k+1);
	for (int i = 0; i < k+1; ++i) que[i] = i;
	for (int i = 0; i < k+1; ++i) vals[i] = ask(que, i).second;

	// When k = n-1, ask all intervals
	// Then, answer is number of values that were larger than the minimum

	int mn = vals[0];
	for (auto v : vals) mn = min(mn, v);

	// m produce larger than minimum
	// k+1 - m produce minimum

	int m = k+1;
	for (auto v : vals) {
		if (v == mn) --m;
	}
	cout << "! " << m << endl;
}
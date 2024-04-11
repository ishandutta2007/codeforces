#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

string rev(string str) {
	reverse(str.begin(), str.end());
	return str;
}

const int N = 100;
vector<int> conns[N];
bool used[N];

int count(int i) {
	if (used[i]) return 0;
	used[i] = 1;

	int res = 1;
	for (auto t : conns[i]) {
		res += count(t);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> strs(n);
	for (int i = 0; i < n; ++i) cin >> strs[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (strs[i] == rev(strs[j])) conns[i].push_back(j);
		}
	}
	
	string res, mid;
	for (int i = 0; i < n; ++i) {
		int cou = count(i);
		if (mid.empty() && (cou & 1) && (strs[i] == rev(strs[i]))) mid = strs[i];
		for (int j = 1; 2*j <= cou; ++j) {
			for (auto c : strs[i]) res.push_back(c);
		}
	}
	cout << 2 * res.size() + mid.size() << '\n';
	cout << res << mid << rev(res) << '\n';
}
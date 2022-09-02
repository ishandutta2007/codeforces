#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<int> solve(vector<pair<pair<int, int>, int>>& inc) {
	sort(inc.begin(), inc.end());
	int n = inc.size();
	vector<int> res(n);
	for (int i = 0; i < n; ++i) res[i] = inc[i].second;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<pair<pair<int, int>, int>> inc;
	vector<pair<pair<int, int>, int>> dec;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			inc.push_back({{a, b}, i});
		} else if (b < a) {
			dec.push_back({{a, b}, i});
		}
	}

	vector<int> s1 = solve(inc);
	vector<int> s2 = solve(dec);
	reverse(s1.begin(), s1.end());
	if (s1.size() < s2.size()) swap(s1, s2);

	cout << s1.size() << '\n';
	for (auto v : s1) cout << v+1 << ' '; cout << '\n';
}
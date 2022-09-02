#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int N = 2*(int)1e6;

int ind(char c) {
	if (c == 'a') return 0;
	if (c == 'e') return 1;
	if (c == 'i') return 2;
	if (c == 'o') return 3;
	if (c == 'u') return 4;
	else return -1;
}
pair<int, int> check(const string& str) {
	int cou = 0;
	int lst = -1;
	for (auto c : str) {
		if (ind(c) != -1) {
			++cou;
			lst = ind(c);
		}
	}
	int ind = cou + N*lst;
	return {cou, ind};
}

struct PairFinder {
	map<int, vector<int>> inds;
	vector<int> actives;

	pair<int, int> getPair() {
		if (actives.empty()) return {-1, -1};
		int i = actives.back();
		vector<int>& v = inds[i];

		pair<int, int> p;
		p.first = v.back();
		v.pop_back();
		p.second = v.back();
		v.pop_back();

		if (v.size() <= 1) actives.pop_back();
		return p;
	}
	void add(int i, int j) {
		inds[i].push_back(j);
		if (inds[i].size() == 2) actives.push_back(i);
	}
	vector<int> getOrphans() {
		vector<int> res;
		for (auto pr : inds) {
			if (pr.second.size() % 2 == 1) {
				res.push_back(pr.second[0]);
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> strs(n);
	vector<pair<int, int>> vals(n);
	PairFinder p1; // Count appears multiple times, last character at most once
	PairFinder p2; // Count and last character appear multiple times

	for (int i = 0; i < n; ++i) {
		cin >> strs[i];
		vals[i] = check(strs[i]);
		p2.add(vals[i].second, i);
	}

	vector<int> tmp = p2.getOrphans();
	for (auto i : tmp) {
		p1.add(vals[i].first, i);
	}

	vector<pair<pair<int, int>, pair<int, int>>> res;
	while(true) {
		auto sub = p2.getPair();
		if (sub.first == -1) break;

		auto sub2 = p1.getPair();
		if (sub2.first == -1) {
			sub2 = p2.getPair();
			if (sub2.first == -1) break;
		}
		res.push_back({{sub2.first, sub.first}, {sub2.second, sub.second}});
	}

	cout << res.size() << '\n';
	for (auto pr : res) {
		cout << strs[pr.first.first] << ' ' << strs[pr.first.second] << '\n';
		cout << strs[pr.second.first] << ' ' << strs[pr.second.second] << '\n';
	}
}
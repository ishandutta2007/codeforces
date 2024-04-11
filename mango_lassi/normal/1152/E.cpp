#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int bins(const vector<int>& vals, int v) {
	int low = 0;
	int high = (int)vals.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vals[mid] >= v) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

const int N = 2 * (int)1e5;
multiset<int> conns[N];

void dfs(int i, vector<int>& seq) {
	while(! conns[i].empty()) {
		auto it = conns[i].begin();
		int t = *it;
		conns[i].erase(it);
		conns[t].erase(conns[t].find(i));
		dfs(t, seq);
	}
	seq.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> bs(n-1);
	vector<int> cs(n-1);
	for (int i = 0; i < n-1; ++i) cin >> bs[i];
	for (int i = 0; i < n-1; ++i) cin >> cs[i];
	
	vector<int> comp;
	for (int i = 0; i < n-1; ++i) {
		comp.push_back(bs[i]);
		comp.push_back(cs[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	bool fail = false;
	for (int i = 0; i < n-1; ++i) {
		bs[i] = bins(comp, bs[i]);
		cs[i] = bins(comp, cs[i]);

		if (cs[i] < bs[i]) fail = true;

		conns[bs[i]].insert(cs[i]);
		conns[cs[i]].insert(bs[i]);
	}

	// Find any eulerian path
	int m = comp.size();
	vector<int> odds;
	for (int i = 0; i < m; ++i) {
		if (conns[i].size() & 1) odds.push_back(i);
	}

	int s = -1;
	int t = -1;
	if (odds.size() == 2) {
		s = odds[0];
		t = odds[1];
	} else if (odds.size() == 0) {
		s = 0;
		t = 0;
	} else {
		fail = true;
	}
	
	if (! fail) {
		vector<int> seq;
		dfs(s, seq);
		if (seq.size() != n) {
			fail = true;
		} else {
			for (auto i : seq) cout << comp[i] << ' '; cout << '\n';
		}
	}
	if (fail) {
		cout << "-1\n";
	}
}
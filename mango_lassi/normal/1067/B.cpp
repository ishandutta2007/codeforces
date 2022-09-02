#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 1e5;
vector<int> conns[N];
int cou[N];

bool test(int i, int p, int k) {
	if (k == 0) {
		if (conns[i].size() > 1) {
			// cout << "fail at " << i << '\n';
			return false;
		} else {
			return true;
		}
	} else {
		if ((conns[i].size() + (i == p)) < 4) {
			// cout << "too few edges at " << i << '\n';
			return false;
		}
		for (auto t : conns[i]) {
			if (t == p) continue;
			if (! test(t, i, k-1)) return false;
		}
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i+1 < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	// 1. Find center vertex
	vector<int> que;
	for (int i = 0; i < n; ++i) {
		cou[i] = conns[i].size();
		if (cou[i] <= 1) que.push_back(i);
	}
	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		for (auto t : conns[i]) {
			--cou[t];
			if (cou[t] == 1) que.push_back(t);
		}
	}

	int c = que.back();
	bool res = test(c, c, k);

	if (res) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
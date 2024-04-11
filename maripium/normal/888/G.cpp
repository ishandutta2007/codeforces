#include <bits/stdc++.h>
using namespace std;

struct Trie {
	struct Node {
		int to[2];
		Node() { to[0] = to[1] = 0; }
	};
	vector<Node> trie;
	Trie() { trie.push_back(Node()); }
	
	void add(int x) {
		int pr = 0;
		for (int b = 29; b >= 0; --b) {
			int t = (x >> b) & 1;
			if (trie[pr].to[t] == 0) {
				trie[pr].to[t] = trie.size();
				trie.push_back(Node());
			}
			pr = trie[pr].to[t];
		}
	}
	
	int get(int x) {
		int res = 0;
		int pr = 0;
		for (int b = 29; b >= 0; --b) {
			int t = (x >> b) & 1;
			if (trie[pr].to[t]) pr = trie[pr].to[t];
			else res += (1 << b), pr = trie[pr].to[t ^ 1];
		}
		return res;
	}
};

int n;
int a[200005];
long long res = 0;

void go(int b, vector<int> a) {
	vector<int> na[2];
	for (int x : a) {
		na[(x >> b) & 1].push_back(x);
	}
	if (na[0].size() > na[1].size()) na[0].swap(na[1]);
	if (na[0].size()) {
		Trie tr;
		for (int x : na[0]) tr.add(x);
		int mn = 2e9;
		for (int x : na[1]) mn = min(mn, tr.get(x));
		res += mn;
	}
	if (b) {
		go(b - 1, na[1]); if (na[0].size()) go(b - 1, na[0]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	go(29, vector<int>(a, a + n));
	cout << res << '\n';
}
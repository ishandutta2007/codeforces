#include <bits/stdc++.h>

using namespace std;

inline string to_string(char c) {
	string s;
	s.push_back(c);
	return s;
}

struct Node {
	bool can_delete_all = true;
	char first_cant = 0;
	bool more = false;

	string first = "";
	string last = "";
	int ans_len = 0;

	Node(bool can_delete_all = true, char first_cant = 0, bool more = false, string first = "", string last = "", int ans_len = 0)
		: can_delete_all(can_delete_all), first_cant(first_cant), more(more), first(first), last(last), ans_len(ans_len) 
	{}

	friend Node operator + (pair<int, char> p, Node n) {
		auto [len, c] = p;
		if (n.can_delete_all)
			return Node(len % 2 == 0, c, false, (len % 2 == 0 ? "" : to_string(c)), (len % 2 == 0 ? "" : to_string(c)), len % 2);

		auto add = [](string &first, string &last, int len, char c, int &ans_len) {
			ans_len += len;

			reverse(last.begin(), last.end());
			for (int i = 0; i < len && (int) last.size() < 2; i++)
				last.push_back(c);
			reverse(last.begin(), last.end());

			reverse(first.begin(), first.end());
			for (int i = 0; i < len && i < 12; i++)
				first.push_back(c);
			reverse(first.begin(), first.end());
			while ((int) first.size() > 12)
				first.pop_back();
		};

		if (c == n.first_cant) {
			if (n.more)
				add(n.first, n.last, len, c, n.ans_len);
			else
				add(n.first, n.last, len % 2, c, n.ans_len);
			return n;
		}

		if (c < n.first_cant) {
			add(n.first, n.last, len, c, n.ans_len);
			n.more = true;
			n.first_cant = c;
			return n;
		}

		assert(c > n.first_cant);
		if (len % 2 == 0)
			return n;

		add(n.first, n.last, 1, c, n.ans_len);
		n.more = false;
		n.first_cant = c;
		return n;
	}

	void print() {
		cout << ans_len << ' ';
		if (ans_len <= 10)
			cout << first << '\n';
		else
			cout << first.substr(0, 5) << "..." << last << '\n';
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = (int) s.size();
	vector<pair<int, int>> segs;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && s[i] == s[j])
			j++;
		segs.emplace_back(i, j);
		i = j;
	}
	int m = (int) segs.size();
	segs.emplace_back(n, n);

	vector<Node> dp(m + 1);
	for (int i = m - 1; i >= 0; i--)
		dp[i] = pair<int, char>{segs[i].second - segs[i].first, s[segs[i].first]} + dp[i + 1];

	int segi = 0;
	pair<int, char> cur;
	for (int i = 0; i < n; i++) {
		while (segs[segi].first < i)
			segi++;
		if (segs[segi].first == i) {
			dp[segi].print();
			cur = {segs[segi].second - segs[segi].first, s[segs[segi].first]};
		} else
			(cur + dp[segi]).print();
		cur.first--;
	}
}
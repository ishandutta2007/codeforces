#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class T>
string to_string(T v);

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	bool first = true;
	for (auto x : v) {
		if (!first)
			s += ", ";
		first = false;
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> poses(n);
		for (int i = 0; i < n; i++)
			poses[i].push_back(-1);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x--;
			poses[x].push_back(i);
		}
		for (int i = 0; i < n; i++)
			poses[i].push_back(n);
		vector<int> a(n + 1, n);
		for (int i = 0; i < n; i++) {
			int mx = 0;
			for (int j = 1; j < (int) poses[i].size(); j++)
				mx = max(mx, poses[i][j] - poses[i][j - 1]);
			// debug(i, mx);
			if (mx <= n)
				a[mx] = min(a[mx], i);
		}
		for (int i = 1; i <= n; i++)
			a[i] = min(a[i], a[i - 1]);
		for (int k = 1; k <= n; k++) {
			if (a[k] == n)
				cout << -1 << ' ';
			else
				cout << a[k] + 1 << ' ';
		}
		cout << '\n';
	}
}
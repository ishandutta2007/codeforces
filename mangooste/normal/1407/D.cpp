#include <bits/stdc++.h>

using namespace std;

template<class T>
string to_string(T v);

string to_string(string s)
{ return "\"" + s + "\""; }

string to_string(bool b)
{ return b ? "true" : "false"; }

template<class A, class B>
string to_string(pair<A, B> p)
{ return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

vector<int> getLess(int n, vector<int> a) {
	vector<int> left(n, -1);
	vector<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		while (st.size() && st.back().first > a[i])
			st.pop_back();
		if (st.size())
			left[i] = st.back().second;
		st.emplace_back(a[i], i);
	}
	return left;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector<int> lessLeft = getLess(n, a);
	for (auto &x : a)
		x *= -1;
	vector<int> greaterLeft = getLess(n, a);
	reverse(a.begin(), a.end());
	vector<int> greaterRight = getLess(n, a);
	for (auto &x : a)
		x *= -1;
	vector<int> lessRight = getLess(n, a);
	reverse(greaterRight.begin(), greaterRight.end());
	reverse(lessRight.begin(), lessRight.end());
	for (int i = 0; i < n; i++) {
		if (greaterRight[i] != -1)
			greaterRight[i] = n - 1 - greaterRight[i];
		if (lessRight[i] != -1)
			lessRight[i] = n - 1 - lessRight[i];
	}

	vector<vector<int>> from(n);
	for (int i = 0; i < n; i++) {
		if (lessLeft[i] != -1)
			from[i].push_back(lessLeft[i]);
		if (greaterLeft[i] != -1)
			from[i].push_back(greaterLeft[i]);
		if (lessRight[i] != -1)
			from[lessRight[i]].push_back(i);
		if (greaterRight[i] != -1)
			from[greaterRight[i]].push_back(i);
	}

	debug(lessLeft);
	debug(greaterLeft);
	debug(lessRight);
	debug(greaterRight);
	debug(from);

	const int INF = n - 1;
	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
		for (auto j : from[i])
			dp[i] = min(dp[i], dp[j] + 1);

	cout << dp.back() << '\n';
}
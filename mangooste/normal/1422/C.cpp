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
	string sep = "";
	for (auto x : v) {
		s += sep;
		sep = ", ";
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

const int MOD = (int) 1e9 + 7;

inline int add(int a, int b) {
	a += b;
	return a - MOD * (a >= MOD);
}

inline int mult(int a, int b) {
	return (long long) a * b % MOD;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = (int) s.size();
	int ans = 0;

	vector<int> p10(n + 1, 1);
	for (int i = 1; i <= n; i++)
		p10[i] = mult(p10[i - 1], 10);

	{
		int now = 0;
		for (int i = n - 1; i > 0; i--) {
			now = add(now, mult(p10[n - 1 - i], (int) (s[i] - '0')));
			// debug(i, now);
			ans = add(ans, mult(now, i));
		}
		// debug(ans);
	}

	{
		for (int i = 1; i <= n; i++)
			p10[i] = add(p10[i - 1], p10[i]);
		int now = 0;
		for (int i = 0; i < n - 1; i++) {
			now = mult(now, 10);
			now = add(now, (int) (s[i] - '0'));
			debug(i, now);
			debug(p10[n - 1 - i]);
			ans = add(ans, mult(now, p10[n - 2 - i]));
		}
	}

	cout << ans << '\n';
}
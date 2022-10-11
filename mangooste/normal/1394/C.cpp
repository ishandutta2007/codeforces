#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

namespace IO {
	template<class T>
	istream& operator >> (istream &in, vector<T> &vec) {
		for (auto &x : vec) in >> x;
		return in;
	}

	template<class T>
	ostream& operator << (ostream &out, vector<T> vec) {
		for (size_t i = 0; i < vec.size(); i++) {
			if (i) out << ' ';
			out << vec[i];
		}
		return out;
	}

	template<class A, class B>
	istream& operator >> (istream &in, pair<A, B> &p) {
		return in >> p.first >> p.second;
	}

	template<class A, class B>
	ostream& operator << (ostream &out, pair<A, B> p) {
		return out << p.first << ' ' << p.second;
	}
} // namespace IO

using namespace IO;

void debug_print() {
	cout << endl;
}

template<class A, class... B>
void debug_print(A a, B... b) {
	cout << ' ' << a;
	debug_print(b...);
}

#ifdef LOCAL
	#define debug(...) cout << '[' << #__VA_ARGS__ << "]:", debug_print(__VA_ARGS__)
#else
	#define debug(...) 42
#endif

vector<pair<int, int>> ps;

inline int get(pair<int, int> mid) {
	auto [xm, ym] = mid;
	int mx = 0;
	for (auto [x, y] : ps) {
		if ((x <= xm) == (y <= ym)) mx = max(mx, max(abs(x - xm), abs(y - ym)));
		else mx = max(mx, abs(x - xm) + abs(y - ym));
	}
	return mx;
}

int main(int agrc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pair<int, int> now = {0, 0};
		for (auto c : s) (c == 'N' ? now.first : now.second)++;
		ps.push_back(now);
	}
	sort(ps.begin(), ps.end());
	ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
	debug(ps);
	pair<int, int> mnx = ps[0], mny = ps[0];
	for (auto p: ps) {
		mnx = min(mnx, p);
		if (pair<int, int>{mny.second, mny.first} > pair<int, int>{p.second, p.first}) mny = p;
	}

	int L = -1, R = 5e5 + 1;
	pair<int, int> ans = {-1, -1};
	while (R - L > 1) {
		int mid = (L + R) / 2;
		debug(mid);

		int now = 0;
		for (auto [x, y] : ps) now = max(now, x + max(0, mny.second + mid - y));
		if (get({now - mid, mny.second + mid}) <= mid) {
			R = mid;
			ans = {now - mid, mny.second + mid};
			continue;
		}

		now = 0;
		for (auto [x, y] : ps) now = max(now, y + max(0, mnx.first + mid - x));
		if (get({mnx.first + mid, now - mid}) <= mid) {
			R = mid;
			ans = {mnx.first + mid, now - mid};
			continue;
		}

		L = mid;
	}
	cout << R << '\n' << string(ans.first, 'N') + string(ans.second, 'B') << '\n';
}
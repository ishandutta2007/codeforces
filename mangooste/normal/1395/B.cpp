#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		return out << '\n' << p.first << ' ' << p.second;
	}
} // namespace IO

using namespace IO;

#ifdef LOCAL
	#define show(x) cout << '[' << #x << "] = " << (x) << endl;
#else
	#define show(x) 42
#endif

int main(int agrc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<pair<int, int>> order;
	for (int i = 0; i < m; i++) {
		order.emplace_back(x, y);
		for (int j = 1; j <= n; j++) {
			if (j != x) order.emplace_back(j, y);
		}
		x = order.back().first;
		y = y % m + 1;
	}
	cout << order << '\n';
}
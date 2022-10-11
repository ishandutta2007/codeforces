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
		return out << p.first << ' ' << p.second;
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

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	cin >> a >> b;
	for (int ans = 0; ans < (1 << 9); ans++) {
		show(ans);
		bool ok = true;
		for (auto x : a) {
			int bad = 0;
			for (int i = 0; i < 9; i++) {
				if (!((ans >> i) % 2) && (x >> i) % 2) bad += (1 << i);
			}
			bool any = false;
			for (auto y : b) any |= !(bad & y);
			ok &= any;
		}
		if (ok) return cout << ans << '\n', 0;
	}
	assert(false);
}
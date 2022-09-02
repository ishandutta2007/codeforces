#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MOD = 998244353;

class SegTree {
	private:
		struct El {
			int p[2][2]; // Probability that leftmost is L/R and rightmost is L/R
			El() {
				p[0][0] = 0;
				p[0][1] = 0;
				p[1][0] = 0;
				p[1][1] = 0;
			}
			static El id() {
				El res;
				res.p[0][0] = 1;
				res.p[1][1] = 1;
				return res;
			}
		};
		static El combine(const El& le, const El& ri) {
			El res;
			for (int a = 0; a < 2; ++a) {
				for (int b = 0; b < 2; ++b) {
					for (int i = 0; i < 2; ++i) {
						res.p[a][b] = (res.p[a][b] + (ll)le.p[a][i] * ri.p[i][b]) % MOD;
					}
				}
			}
			return res;
		}
		void update(int i) {
			for (i >>= 1; i > 0; i >>= 1) seg[i] = combine(seg[2*i], seg[2*i+1]);
		}

		vector<El> seg;
		int h = 1;
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, El::id());
		}
		
		int prob(int i, int a, int b) {
			i += h;
			El backup = seg[i];
			for (int x = 0; x < 2; ++x) {
				for (int y = 0; y < 2; ++y) {
					if (x != a || y != b) seg[i].p[x][y] = 0;
				}
			}
			update(i);

			ll res = (seg[1].p[0][0] + seg[1].p[0][1]) % MOD;

			seg[i] = backup;
			update(i);
			return res;
		}
		void setv(int i, int a, int b, int c, int d) {
			i += h;
			seg[i].p[0][0] = a;
			seg[i].p[0][1] = b;
			seg[i].p[1][0] = c;
			seg[i].p[1][1] = d;
			update(i);
		}
		void zero(int i, int a, int b) {
			i += h;
			seg[i].p[a][b] = 0;
			update(i);
		}
};

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b > 0) return modPow(a*a % MOD, b / 2);
	return 1;
}

struct Atom {
	int xi, vi, pi;
};

struct Rat {
	ll a, b;

	// a / b < rhs.a / rhs.b?
	bool operator<(const Rat& rhs) const {
		return a * rhs.b < b * rhs.a;
	}
	ll modv() const { return a * modPow(b, MOD-2) % MOD; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	SegTree seg(n);

	vector<Atom> atoms(n);
	for (auto& v : atoms) cin >> v.xi >> v.vi >> v.pi;

	const ll HI = modPow(100, MOD - 2);
	for (int i = 0; i < n; ++i) {
		int prob0 = (100 - atoms[i].pi) * HI % MOD;
		int prob1 = atoms[i].pi * HI % MOD;
		seg.setv(i, prob0, prob1, prob0, prob1);
	}

	vector<pair<Rat, pair<int, pair<int, int>>>> que;
	for (int i = 0; i+1 < n; ++i) {
		ll dist = atoms[i+1].xi - atoms[i].xi;
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				ll vel = (a ? 1 : -1) * atoms[i].vi + (b ? -1 : 1) * atoms[i+1].vi;
				Rat r = {dist, vel};
				if (vel > 0) que.push_back({r, {i, {a, b}}}); // Collision eventually happens
			}
		}
	}
	sort(que.begin(), que.end());

	ll res = 0;
	for (auto pr : que) {
		ll t = pr.first.modv();
		int i = pr.second.first;
		int a = pr.second.second.first;
		int b = pr.second.second.second;

		ll prob = seg.prob(i+1, a, b);
		res = (res + prob * t) % MOD;
		seg.zero(i+1, a, b);

		// cerr << "event " << i << ' ' << a << ' ' << b << ": " << t << ' ' << prob << '\n';
	}
	cout << res << '\n';
}
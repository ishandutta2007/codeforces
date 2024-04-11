#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b^1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

class SegTree {
	private:
		struct El {
			int prod = 1;
			int rev_prod = 1;
			int exp = 0;
		};

		El combineEl(const El& le, const El& ri) {
			El res;
			res.prod = (ll)le.prod * ri.prod % MOD;
			res.rev_prod = (ll)le.rev_prod * ri.rev_prod % MOD;
			res.exp = (le.exp + (ll)le.prod * ri.exp) % MOD;
			return res;
		}

		struct Dat {
			bool cp = false;
			int add = 0;
			El le, ri;
		};
		Dat combine(const Dat& le, const Dat& ri) {
			Dat res;
			res.cp = le.cp || ri.cp;
			res.add = le.add + ri.add;
			if (res.add >= MOD) res.add -= MOD;

			if (le.cp) res.le = le.le;
			else res.le = combineEl(le.le, ri.le);
			if (ri.cp) res.ri = ri.ri;
			else res.ri = combineEl(le.ri, ri.le);

			if (le.cp && ri.cp) {
				El tmp = combineEl(le.ri, ri.le);
				res.add += (ll)tmp.exp * tmp.rev_prod % MOD;
				if (res.add >= MOD) res.add -= MOD;
			}
			return res;
		}

		vector<Dat> seg;
		int h = 1;

	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h);
		}
		void apply(int i, int prob, bool check) {
			i += h;
			if (prob != -1) {
				seg[i].ri.exp = 1;
				seg[i].ri.prod = prob;
				seg[i].ri.rev_prod = modPow(prob, MOD - 2);
			}
			check ^= seg[i].cp;
			if (check) {
				seg[i].cp = true;
				seg[i].le.prod = 1;
				seg[i].le.rev_prod = 1;
				seg[i].le.exp = 0;
			} else {
				seg[i].cp = false;
				seg[i].le = seg[i].ri;
			}
			for (i /= 2; i > 0; i /= 2) seg[i] = combine(seg[2*i], seg[2*i+1]);
		}
		int get() {
			return seg[1].add;
		}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	
	int inv = modPow(100, MOD - 2);
	vector<int> probs(n);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		probs[i] = (ll)p * inv % MOD;
	}

	SegTree seg(n+1);
	seg.apply(0, probs[0], true);
	for (int i = 1; i < n; ++i) seg.apply(i, probs[i], false);
	seg.apply(n, 1, true);

	for (; q; --q) {
		int x;
		cin >> x;
		seg.apply(x-1, -1, true);
		cout << seg.get() << '\n';
	}
}
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;

const int N = 21;
const int H = 1<<N;
bitset<H> masks[N]; // Locations with bit i set

struct MF {
	bitset<H> one, two;

	void operator-=(const MF& rhs) {
		two ^= (one & rhs.one) ^ (rhs.one ^ rhs.two);
		one ^= rhs.one;
	}
	void operator+=(const MF& rhs) {
		two ^= (one & rhs.one) ^ rhs.two;
		one ^= rhs.one;
	}
	MF operator*(const MF& rhs) {
		return {one & rhs.one, (one & rhs.two) ^ (two & rhs.one)};
	}
	MF operator<<(int d) const { return {one << d, two << d}; }
	MF operator&(const bitset<H>& mask) const { return {one & mask, two & mask}; }

	void print(int n) {
		for (int i = 0; i < n; ++i) {
			cout << (one[i] ? 1 : 0) + (two[i] ? 2 : 0);
		}
		cout << '\n';
	}
};

void mobius(int n, MF& f, bool inv = false) {
	for (int b = 0; b < N; ++b) {
		MF term = ((f << (1 << b)) & masks[b]);
		if (inv) f -= term;
		else f += term;
	}
}
vector<MF> tieredMobius(int n, const MF& f) {
	vector<MF> res(n+1);
	for (int m = 0; m < (1<<n); ++m) {
		int k = __builtin_popcount(m);
		res[k].one[m] = f.one[m];
		res[k].two[m] = f.two[m];
	}
	for (int k = 0; k <= n; ++k) mobius(n, res[k]);
	return res;
}
MF subsetConv(int n, const MF& f, const MF& g) {
	auto fc = tieredMobius(n, f);
	auto gc = tieredMobius(n, g);
	MF res;
	for (int s = 0; s <= n; ++s) {
		MF tmp;
		for (int j = 0; j <= s; ++j) tmp += fc[j] * gc[s-j];
		mobius(n, tmp, true);
		for (int m = 0; m < (1<<n); ++m) {
			if (__builtin_popcount(m) == s) {
				res.one[m] = tmp.one[m];
				res.two[m] = tmp.two[m];
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int b = 0; b < N; ++b) {
		for (int i = 0; i < H; ++i) {
			if (i & (1<<b)) masks[b][i] = 1;
		}
	}

	int n;
	cin >> n;
	MF f, g;
	string fv, gv;
	cin >> fv >> gv;
	for (int i = 0; i < (1<<n); ++i) {
		if (fv[i] == '1' || fv[i] == '3') f.one[i] = 1;
		if (fv[i] == '2' || fv[i] == '3') f.two[i] = 1;
		if (gv[i] == '1' || gv[i] == '3') g.one[i] = 1;
		if (gv[i] == '2' || gv[i] == '3') g.two[i] = 1;
	}
	subsetConv(n, f, g).print(1<<n);;
}
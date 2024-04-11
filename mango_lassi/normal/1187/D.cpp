#include <iostream>
#include <random>
#include <chrono>
#include <tuple>
using namespace std;
typedef long long ll;
const int INF = 1e9;

// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

struct Treap {
	const int pri;
	const int val;
	Treap* le = nullptr;
	Treap* ri = nullptr;
	int siz = 1;
	int minv;

	Treap(int v) : pri(rand<int>()), val(v), minv(v) {}
	~Treap() {
		delete le;
		delete ri;
	}

	void update() {
		siz = 1 + (le ? le->siz : 0) + (ri ? ri->siz : 0);
		minv = min(val, min(le ? le->minv : INF, ri ? ri->minv : INF));
	}
	void push() {} // Lazy update

	static Treap* join(Treap* a, Treap* b) {
		if (! a || ! b) return (a ? a : b);
		Treap* res = ((a->pri < b->pri) ? a : b);

		res->push();
		if (res == a) a->ri = join(a->ri, b);
		else          b->le = join(a, b->le);
		res->update();
		return res;
	}
	static pair<Treap*, Treap*> splitSiz(int as, Treap* x) {
		if (! x) return {nullptr, nullptr};
		int ls = 1 + (x->le ? x->le->siz : 0);
		Treap* oth;
		
		x->push();
		if (ls > as) {
			tie(oth, x->le) = splitSiz(as, x->le);
			x->update();
			return {oth, x};
		} else {
			tie(x->ri, oth) = splitSiz(as-ls, x->ri);
			x->update();
			return {x, oth};
		}
	}

	static pair<Treap*, Treap*> splitVal(int v, Treap* x) {
		if (! x) return {nullptr, nullptr};
		int lv = min(x->val, x->le ? x->le->minv : INF);
		Treap* oth;
		
		x->push();
		if (lv <= v) {
			tie(oth, x->le) = splitVal(v, x->le);
			x->update();
			return {oth, x};
		} else {
			tie(x->ri, oth) = splitVal(v, x->ri);
			x->update();
			return {x, oth};
		}
	}
};

bool solve() {
	int n;
	cin >> n;
	Treap* as = nullptr;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		as = Treap::join(as, new Treap(v));
	}
	vector<int> bs(n);
	for (int i = 0; i < n; ++i) cin >> bs[i];
	for (int i = 0; i < n; ++i) {
		Treap *le, *ri;
		tie(le, ri) = Treap::splitVal(bs[i], as);
		if (ri == nullptr) {
			delete le, delete ri;
			return false;
		}

		Treap* x;
		tie(x, ri) = Treap::splitSiz(1, ri);
		if (x->val != bs[i]) {
			delete le, delete ri, delete x;
			return false;
		}
		delete x;

		as = Treap::join(le, ri);
	}
	return true;
}

// No example usage since unaugmented this doesn't really do anything
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		bool res = solve();
		cout << (res ? "YES" : "NO") << '\n';
	}
}
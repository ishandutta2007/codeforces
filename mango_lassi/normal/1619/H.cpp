#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand() { return uniform_int_distribution<T>()(rng); }

struct Treap {
	const int pri, ind;
	Treap* le = nullptr;
	Treap* ri = nullptr;
	Treap* par = nullptr;
	int siz = 1;

	Treap(int id) : pri(rand<int>()), ind(id) {}

	void update() {
		siz = 1 + getSiz(le) + getSiz(ri);
		if (le) le->par = this;
		if (ri) ri->par = this;
	}

	static int getSiz(Treap* x) { return x ? x->siz : 0; }
	static Treap* join(Treap* a, Treap* b) {
		if (! a || ! b) return (a ? a : b);
		Treap* res = ((a->pri < b->pri) ? a : b);

		if (res == a) a->ri = join(a->ri, b);
		else          b->le = join(a, b->le);
		res->update();
		return res;
	}

	static pair<Treap*, Treap*> split(int as, Treap* x) {
		if (! x) return {nullptr, nullptr};
		if (x->le) x->le->par = nullptr;
		if (x->ri) x->ri->par = nullptr;
		int ls = 1 + (x->le ? x->le->siz : 0);
		Treap* oth;
		
		if (ls > as) {
			tie(oth, x->le) = split(as, x->le);
			x->update();
			return {oth, x};
		} else {
			tie(x->ri, oth) = split(as-ls, x->ri);
			x->update();
			return {x, oth};
		}
	}
	static pair<int, Treap*> getRoot(Treap* x) {
		int lc = getSiz(x->le);
		while(x->par) {
			if (x->par->ri == x) lc += 1 + getSiz(x->par->le);
			x = x->par;
		}
		return {lc, x};
	}
	static Treap* findKth(int k, Treap* x) {
		int nk = k - getSiz(x->le);
		if (nk < 0) return findKth(k, x->le);
		if (nk == 0) return x;
		else return findKth(nk - 1, x->ri);
	}
	static void printTreap(int d, Treap* x) {
		if (x) {
			for (int j = 0; j < d; ++j) cerr << ' ';
			cerr << x->ind << '\n';
			if (x->le) {
				for (int j = 0; j < d; ++j) cerr << ' ';
				cerr << "LE:\n";
				printTreap(d + 1, x->le);
			}
			if (x->ri) {
				for (int j = 0; j < d; ++j) cerr << ' ';
				cerr << "RI:\n";
				printTreap(d + 1, x->ri);
			}
		}
	}
};

void addLink(Treap* a, Treap* b) {
	a = Treap::getRoot(a).second;
	b = Treap::getRoot(b).second;
	if (a != b) Treap::join(a, b);
}
void breakLink(Treap* a) {
	auto pr = Treap::getRoot(a);
	Treap::split(pr.first + 1, pr.second);
}
void tryExtend(Treap* a, const vector<int>& ts, const vector<Treap*>& nodes) {
	a = Treap::getRoot(a).second;
	int len = a->siz;
	a = Treap::findKth(len - 1, a);

	Treap* b = nodes[ts[a->ind]];
	addLink(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> ts(n);
	for (int i = 0; i < n; ++i) {
		cin >> ts[i];
		--ts[i];
	}

	vector<Treap*> nodes;
	for (int i = 0; i < n; ++i) nodes.emplace_back(new Treap(i));
	for (int i = 0; i < n; ++i) addLink(nodes[i], nodes[ts[i]]);

	for (int qi = 0; qi < q; ++qi) {
		int op;
		cin >> op;
		if (op == 1) {
			int a, b;
			cin >> a >> b;
			--a; --b;

			breakLink(nodes[a]);
			breakLink(nodes[b]);
			swap(ts[a], ts[b]);
			addLink(nodes[a], nodes[ts[a]]);
			addLink(nodes[b], nodes[ts[b]]);
			tryExtend(nodes[a], ts, nodes);
			tryExtend(nodes[b], ts, nodes);
		} else {
			int a, k;
			cin >> a >> k;
			--a;
			
			auto pr = Treap::getRoot(nodes[a]);
			// Treap::printTreap(0, pr.second);

			int base = pr.first;
			int len = pr.second->siz;
			int tar = (k + base) % len;
			Treap* x = Treap::findKth(tar, pr.second);
			cout << x->ind + 1 << '\n';
		}
	}
	for (int i = 0; i < n; ++i) delete nodes[i];
}
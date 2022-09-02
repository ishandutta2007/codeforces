#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

mt19937 rng(0); // chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand() { return uniform_int_distribution<T>()(rng); }

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

struct Treap {
	const int pri, ts, col;
	ll val, add;
	Treap* le = nullptr;
	Treap* ri = nullptr;

	Treap(int timestamp, int colour, ll value) : pri(rand<int>()), ts(timestamp), col(colour), val(value), add(0) {}
	~Treap() {
		if (le) delete le;
		if (ri) delete ri;
	}
	void apply(ll v) {
		val += v;
		add += v;
	}
	void push() {
		if (le) le->apply(add);
		if (ri) ri->apply(add);
		add = 0;
	}

	static Treap* join(Treap* a, Treap* b) {
		if (! a || ! b) return (a ? a : b);
		Treap* res = ((a->pri < b->pri) ? a : b);

		res->push();
		if (res == a) a->ri = join(a->ri, b);
		else          b->le = join(a, b->le);
		return res;
	}

	// Split treap such that left returned tree contains all with timestamp < t
	static pair<Treap*, Treap*> split(Treap* x, int t) {
		if (! x) return {nullptr, nullptr};
		x->push();
		
		Treap* oth;
		if (x->ts < t) {
			tie(x->ri, oth) = split(x->ri, t);
			return {x, oth};
		} else {
			tie(oth, x->le) = split(x->le, t);
			return {oth, x};
		}
	}
	static pair<pair<int, int>, ll> getState(Treap* x, int t) {
		if (x == nullptr) return make_pair(make_pair(-1, -1), 0);
		x->push();

		if (t < x->ts) return getState(x->le, t);
		else {
			auto sub = getState(x->ri, t);
			if (sub.first.first <= x->ts) return make_pair(make_pair(x->ts, x->col), x->val);
			else return sub;
		}
	}
	static Treap* getFirst(Treap* x) {
		if (x == nullptr) return nullptr;
		x->push();

		if (x->le == nullptr) return x;
		return getFirst(x->le);
	}
	static Treap* getLast(Treap* x) {
		if (x == nullptr) return nullptr;
		x->push();

		if (x->ri == nullptr) return x;
		return getLast(x->ri);
	}
	static void print(Treap* x, int tabs = 0) {
		if (x == nullptr) return;
		if (tabs > 10) assert(false);

		for (int i = 0; i < tabs; ++i) cerr << "\t";
		cerr << x->ts << ' ' << x->col << ' ' << x->val << ' ' << x->add << endl;
	
		if (x->le) {	
			for (int i = 0; i < tabs; ++i) cerr << "\t";
			cerr << "le" << endl;
			print(x->le, tabs + 1);
		}
		if (x->ri) {
			for (int i = 0; i < tabs; ++i) cerr << "\t";
			cerr << "ri" << endl;
			print(x->ri, tabs + 1);
		}
	}
};

ll sumAdds(const vector<pair<pair<int, int>, ll>>& adds, int t0, int t1, int col) {
	int i0 = bins(adds, make_pair(make_pair(col, t0), -INF)) - 1;
	int i1 = bins(adds, make_pair(make_pair(col, t1 + 1), -INF)) - 1;
	if (i1 == -1 || adds[i1].first.first != col) return 0;
	return ((i0 == -1 || adds[i0].first.first != col) ? adds[i1].second : adds[i1].second - adds[i0].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<pair<pair<int, int>, int>> cols;
	vector<pair<pair<int, int>, ll>> adds;
	vector<pair<int, int>> qs;
	for (int qi = 0; qi < q; ++qi) {
		string str;
		cin >> str;
		if (str == "Color") {
			int a, b, c;
			cin >> a >> b >> c;
			cols.emplace_back(make_pair(a-1, qi), c);
			cols.emplace_back(make_pair(b, qi), -1);
		} else if (str == "Add") {
			int c;
			ll x;
			cin >> c >> x;
			adds.emplace_back(make_pair(c, qi), x);
		} else if (str == "Query") {
			int i;
			cin >> i;
			qs.emplace_back(i-1, qi);
		} else assert(false);
	}
	sort(cols.begin(), cols.end());
	sort(adds.begin(), adds.end());
	sort(qs.begin(), qs.end());

	for (int i = 1; i < adds.size(); ++i) {
		if (adds[i].first.first == adds[i-1].first.first) adds[i].second += adds[i-1].second;
	}

	vector<pair<int, ll>> ans;
	Treap* tmp0 = new Treap(-1, 1, 0);
	Treap* tmp1 = new Treap(q, 1, sumAdds(adds, 0, q-1, 1)); 
	Treap* cur = Treap::join(tmp0, tmp1);

	// Treap::print(cur);

	for (int i = 0, col_ind = 0, que_ind = 0; i < n; ++i) {
		// Update current state
		for (; col_ind < cols.size() && cols[col_ind].first.first == i; ++col_ind) {
			int qi = cols[col_ind].first.second;
			int c = cols[col_ind].second;
			if (c == -1) {
				Treap *le, *ri, *mid;
				tie(le, ri) = Treap::split(cur, qi);
				tie(mid, ri) = Treap::split(ri, qi + 1);
				Treap* pre = Treap::getLast(le);
				Treap* nxt = Treap::getFirst(ri);

				ri->apply(-1 * (sumAdds(adds, mid->ts, nxt->ts - 1, mid->col) - sumAdds(adds, mid->ts, nxt->ts - 1, pre->col)));
				delete mid;

				cur = Treap::join(le, ri);
			} else {
				Treap* le, *ri;
				tie(le, ri) = Treap::split(cur, qi);
				Treap* pre = Treap::getLast(le);
				Treap* nxt = Treap::getFirst(ri);
				
				Treap* mid = new Treap(qi, c, pre->val + sumAdds(adds, pre->ts, qi - 1, pre->col));
				ri->apply(sumAdds(adds, mid->ts, nxt->ts - 1, mid->col) - sumAdds(adds, mid->ts, nxt->ts - 1, pre->col));

				cur = Treap::join(le, mid);
				cur = Treap::join(cur, ri);
			}
			// Treap::print(cur);
		}

		// Answer queries
		for (; que_ind < qs.size() && qs[que_ind].first == i; ++que_ind) {
			int qi = qs[que_ind].second;
			auto base = Treap::getState(cur, qi);
			ll res = base.second + sumAdds(adds, base.first.first, qi, base.first.second);
			ans.emplace_back(qi, res);

			// cerr << "Query " << i << ' ' << qi << ": " << base.first.first << ' ' << base.first.second << ' ' << base.second << '\n';
		}
	}
	sort(ans.begin(), ans.end());
	for (auto pr : ans) cout << pr.second << '\n';
}
#include <bits/stdc++.h>
using namespace std;


template <typename T, class Compare = std::less<T>> class RangeMinQuery : private Compare {
	static const int BUCKET_SIZE = 32;
	static const int BUCKET_SIZE_LOG = 5;
	static_assert(BUCKET_SIZE == (1 << BUCKET_SIZE_LOG), "BUCKET_SIZE should be a power of 2");
	static const int CACHE_LINE_ALIGNMENT = 64;
	int n = 0;
	std::vector<T> data;
	std::vector<T> pref_data;
	std::vector<T> suff_data;
	std::vector<T> sparse_table;
	std::vector<uint32_t> range_mask;

private:
	int num_buckets() const {
		return n >> BUCKET_SIZE_LOG;
	}
	int num_levels() const {
		return num_buckets() ? 32 - __builtin_clz(num_buckets()) : 0;
	}
	int sparse_table_size() const {
		return num_buckets() * num_levels();
	}
private:
	const T& min(const T& a, const T& b) const {
		return Compare::operator()(a, b) ? a : b;
	}
	void setmin(T& a, const T& b) const {
		if (Compare::operator()(b, a)) a = b;
	}

	template <typename Vec> static int get_size(const Vec& v) { using std::size; return int(size(v)); }

public:
	RangeMinQuery() {}
	template <typename Vec> explicit RangeMinQuery(const Vec& data_, const Compare& comp_ = Compare())
		: Compare(comp_)
		, n(get_size(data_))
		, data(n)
		, pref_data(n)
		, suff_data(n)
		, sparse_table(sparse_table_size())
		, range_mask(n)
	{
		for (int i = 0; i < n; i++) data[i] = data_[i];
		for (int i = 0; i < n; i++) {
			if (i & (BUCKET_SIZE-1)) {
				uint32_t m = range_mask[i-1];
				while (m && !Compare::operator()(data[(i | (BUCKET_SIZE-1)) - __builtin_clz(m)], data[i])) {
					m -= uint32_t(1) << (BUCKET_SIZE - 1 - __builtin_clz(m));
				}
				m |= uint32_t(1) << (i & (BUCKET_SIZE - 1));
				range_mask[i] = m;
			} else {
				range_mask[i] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			pref_data[i] = data[i];
			if (i & (BUCKET_SIZE-1)) {
				setmin(pref_data[i], pref_data[i-1]);
			}
		}
		for (int i = n-1; i >= 0; i--) {
			suff_data[i] = data[i];
			if (i+1 < n && ((i+1) & (BUCKET_SIZE-1))) {
				setmin(suff_data[i], suff_data[i+1]);
			}
		}
		for (int i = 0; i < num_buckets(); i++) {
			sparse_table[i] = data[i * BUCKET_SIZE];
			for (int v = 1; v < BUCKET_SIZE; v++) {
				setmin(sparse_table[i], data[i * BUCKET_SIZE + v]);
			}
		}
		for (int l = 0; l+1 < num_levels(); l++) {
			for (int i = 0; i + (1 << (l+1)) <= num_buckets(); i++) {
				sparse_table[(l+1) * num_buckets() + i] = min(sparse_table[l * num_buckets() + i], sparse_table[l * num_buckets() + i + (1 << l)]);
			}
		}
	}

	T query(int l, int r) const {
		assert(l <= r);
		int bucket_l = (l >> BUCKET_SIZE_LOG);
		int bucket_r = (r >> BUCKET_SIZE_LOG);
		if (bucket_l == bucket_r) {
			uint32_t msk = range_mask[r] & ~((uint32_t(1) << (l & (BUCKET_SIZE-1))) - 1);
			int ind = (l & ~(BUCKET_SIZE-1)) + __builtin_ctz(msk);
			return data[ind];
		} else {
			T ans = min(suff_data[l], pref_data[r]);
			bucket_l++;
			if (bucket_l < bucket_r) {
				int level = (32 - __builtin_clz(bucket_r - bucket_l)) - 1;
				setmin(ans, sparse_table[level * num_buckets() + bucket_l]);
				setmin(ans, sparse_table[level * num_buckets() + bucket_r - (1 << level)]);
			}
			return ans;
		}
	}
};

template <typename T> using RangeMaxQuery = RangeMinQuery<T, std::greater<T>>;
namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

namespace ecnerwala {

using std::swap;

struct level_ancestor {
	int N;
	std::vector<int> preorder;
	std::vector<int> idx;
	std::vector<std::pair<int, int>> heavyPar; // heavy parent, distance
	level_ancestor() : N(0) {}

	level_ancestor(const std::vector<int>& par) : N(int(par.size())), preorder(N), idx(N), heavyPar(N) {
		std::vector<std::vector<int>> ch(N);
		for (int i = 0; i < N; i++) {
			if (par[i] != -1) ch[par[i]].push_back(i);
		}
		std::vector<int> sz(N);
		int nxt_idx = 0;
		for (int i = 0; i < N; i++) {
			if (par[i] == -1) {
				std::y_combinator([&](auto self, int cur) -> void {
					sz[cur] = 1;
					for (int nxt : ch[cur]) {
						self(nxt);
						sz[cur] += sz[nxt];
					}
					if (!ch[cur].empty()) {
						auto mit = max_element(ch[cur].begin(), ch[cur].end(), [&](int a, int b) { return sz[a] < sz[b]; });
						swap(*ch[cur].begin(), *mit);
					}
				})(i);
				std::y_combinator([&](auto self, int cur, int isRoot = true) -> void {
					preorder[idx[cur] = nxt_idx++] = cur;
					if (isRoot) {
						heavyPar[idx[cur]] = {par[cur] == -1 ? -1 : idx[par[cur]], 1};
					} else {
						assert(idx[par[cur]] == idx[cur]-1);
						heavyPar[idx[cur]] = heavyPar[idx[cur]-1];
						heavyPar[idx[cur]].second++;
					}
					bool chRoot = false;
					for (int nxt : ch[cur]) {
						self(nxt, chRoot);
						chRoot = true;
					}
				})(i);
			}
		}
	}

	int get_ancestor(int a, int k) const {
		assert(k >= 0);
		a = idx[a];
		while (a != -1 && k) {
			if (k >= heavyPar[a].second) {
				k -= heavyPar[a].second;
				assert(heavyPar[a].first <= a - heavyPar[a].second);
				a = heavyPar[a].first;
			} else {
				a -= k;
				k = 0;
			}
		}
		if (a == -1) return -1;
		else return preorder[a];
	}

	int lca(int a, int b) const {
		a = idx[a], b = idx[b];
		while (true) {
			if (a > b) swap(a, b);
			assert(a <= b);
			if (a > b - heavyPar[b].second) {
				return preorder[a];
			}
			b = heavyPar[b].first;
			if (b == -1) return -1;
		}
	}

	int dist(int a, int b) const {
		a = idx[a], b = idx[b];
		int res = 0;
		while (true) {
			if (a > b) swap(a, b);
			assert(a <= b);
			if (a > b - heavyPar[b].second) {
				res += b - a;
				break;
			}
			res += heavyPar[b].second;
			b = heavyPar[b].first;
			if (b == -1) return -1;
		}
		return res;
	}
};

} // namespace ecnerwala

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<tuple<int,int,int> > edges;
	for(int i = 0; i < n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({w, u, v});
	}

	sort(edges.begin(), edges.end());
	vector<int> val(2*n-1, 0);
	vector<int> cloc(n);
	for(int i = 0; i < n; i++) cloc[i] = i;
	int ccur = n;
	vector<int> par(2*n-1);

	UF uf(n);
	for(auto [w, u, v] : edges){
		int x = uf.find(u);
		int y = uf.find(v);
		uf.join(x, v);
		int p = ccur;
		ccur++;
		par[cloc[x]] = p;
		par[cloc[y]] = p;
		val[p] = w;
		cloc[x] = cloc[y] = p;
	}
	par[cloc[uf.find(0)]] = -1;

	auto lca = ecnerwala::level_ancestor(par);
	auto get_path = [&](int x, int y) -> int {
		if(x >= 0 && x < n && y >= 0 && y < n){
			return val[lca.lca(x, y)];
		} else {
			return -1;
		}
	};
	vector<int> cons_max(n, -1);
	for(int i = 0; i+1 < n; i++){
		cons_max[i] = get_path(i, i+1);
	}
	RangeMaxQuery<int> rmq_max(cons_max);
	auto get_interval_max = [&](int a, int b) -> int {
		if(a == b) return -1;
		return rmq_max.query(a, b-1);
	};
	map<int,int> cur_intervals;
	cur_intervals[-1e9] = -1e9;
	cur_intervals[1e9] = 1e9;
	multiset<int> cmax;
	cmax.insert(-1);
	auto ins_path = [&](int x, int y){
		if(x >= 0 && x < n && y >= 0 && y < n){
			cmax.insert(get_path(x, y));
		}
	};
	auto del_path = [&](int x, int y){
		if(x >= 0 && x < n && y >= 0 && y < n){
			cmax.erase(cmax.find(get_path(x, y)));
		}
	};

	auto insert_interval = [&](int x, int y) {
		pair<int,int> ival = {x, y};
		cur_intervals[x] = y;

		auto g = cur_intervals.find(x);
		auto [gl, gr] = ival;
		auto [fl, fr] = *prev(g);
		auto [hl, hr] = *next(g);
		del_path(fr, hl);
		ins_path(fr, gl);
		ins_path(gr, hl);
		cmax.insert(get_interval_max(gl, gr));
	};
	auto delete_interval = [&](int x, int y) {
		pair<int,int> ival = {x, y};
		auto g = cur_intervals.find(x);
		auto [gl, gr] = ival;
		auto [fl, fr] = *prev(g);
		auto [hl, hr] = *next(g);
		ins_path(fr, hl);
		del_path(fr, gl);
		del_path(gr, hl);
		cmax.erase(cmax.find(get_interval_max(gl, gr)));
		cur_intervals.erase(x);
	};
	auto set_false = [&](int l, int r){
		while(true){
			auto f = cur_intervals.lower_bound(l);
			if(f != cur_intervals.end()){
				auto [x, y] = *f;
				if(max(l, x) <= min(r, y)){
					delete_interval(x, y);
					if(x < l) insert_interval(x, l-1);
					if(r < y) insert_interval(r+1, y);
					continue;
				}
			}
			if(f != cur_intervals.begin()){
				f = prev(f);
				auto [x, y] = *f;
				if(max(l, x) <= min(r, y)){
					delete_interval(x, y);
					if(x < l) insert_interval(x, l-1);
					if(r < y) insert_interval(r+1, y);
					continue;
				}
			}
			break;
		}
	};
	auto set_true = [&](int l, int r){
		set_false(l, r);
		insert_interval(l, r);
	};	for(int i = 0; i < q; i++){
		int type;
		cin >> type;
		if(type == 1 || type == 2){
			int l, r;
			cin >> l >> r;
			l--; r--;
			if(type == 1) set_true(l, r);
			if(type == 2) set_false(l, r);
		} else if(type == 3){
			int x;
			cin >> x;
			x--;
			int z = *cmax.rbegin();
			auto [al, ar] = *next(cur_intervals.begin());
			if(al >= 0 && al < n){
				z = max(z, get_path(x, al));
			}
			if(z <= 0) z = -1;
			cout << z << '\n';
		}
	}
}
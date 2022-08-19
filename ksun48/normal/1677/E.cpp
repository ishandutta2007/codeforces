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

using ll = int64_t;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, Q;
	cin >> n >> Q;
	vector<int> p(n);
	for(int i = 0; i < n; i++) cin >> p[i];
	vector<int> loc(n+1);
	for(int i = 0; i < n; i++) loc[p[i]] = i;
	vector<pair<int,int> > queries(Q);
	for(auto& [l, r] : queries){
		cin >> l >> r;
		l--; r--;
	}
	vector<int> l(n), r(n);
	vector<pair<int,int> > interval(n);

	auto rmq = RangeMaxQuery<int>(p);
	int root = y_combinator(
		[&](auto self, int lx, int rx) -> int {	
			if(lx > rx) return -1;
			int val = rmq.query(lx, rx);
			int mx = loc[val];
			interval[mx] = {lx, rx};
			l[mx] = self(lx, mx-1);
			r[mx] = self(mx+1, rx);
			return mx;
		}
	)(0, n-1);
	vector<ll> ans(Q, 0);
	vector<vector<int> > factors(n+1);
	for(int d = 1; d <= n; d++){
		for(int e = d; e <= n; e += d){
			factors[e].push_back(d);
		}
	}
	vector<tuple<int, int, int> > rects;
	y_combinator(
		[&](auto self, int nx) -> void {
			if(nx == -1) return;
			self(l[nx]);
			self(r[nx]);
			int val = p[nx];
			auto [lx, rx] = interval[nx];
			vector<pair<int,int> > good;
			for(int f : factors[val]){
				if(f == val / f) continue;
				int ax = loc[f];
				int bx = loc[val / f];
				if(ax < lx || ax > rx || bx < lx || bx > rx) continue;
				int sx = min({ax, bx, nx});
				int ex = max({ax, bx, nx});
				good.push_back({sx, ex});
			}
			sort(good.begin(), good.end(), [&](pair<int,int> a, pair<int,int> b){
				return tie(a.first, b.second) > tie(b.first, a.second);
			});
			{
				vector<pair<int,int> > ngood;
				for(auto x : good){
					if(ngood.empty() || x.second < ngood.back().second){
						ngood.push_back(x);
					}
				}
				good = ngood;
			}
			if(!good.empty()){
				for(int i = 0; i < good.size(); i++){
					if(i) rects.push_back({good[i].first, good[i-1].second, -1});
					rects.push_back({good[i].first, good[i].second, 1});
				}
				rects.push_back({lx-1, good.back().second, -1});
				rects.push_back({good.front().first, rx+1, -1});
				rects.push_back({lx-1, rx+1, 1});
			}
		}
	)(root);
	vector<vector<int> > q_by_lx(n);
	vector<vector<int> > upd_by_lx(n);
	for(int i = 0; i < Q; i++){
		auto [lx, rx] = queries[i];
		q_by_lx[lx].push_back(i);
	}
	for(int i = 0; i < rects.size(); i++){
		auto [lx, rx, t] = rects[i];
		if(lx >= 0){
			upd_by_lx[min(lx, n-1)].push_back(i);
		}
	}
	FT ft_mult(n);
	FT ft_mult_lx(n);
	FT ft_mult_rx(n);
	FT ft_mult_lx_rx(n);
	for(int i = n-1; i >= 0; i--){
		for(int idx : upd_by_lx[i]){
			auto [lx, rx, mult] = rects[idx];
			ft_mult.update(rx, mult);
			ft_mult_lx.update(rx, mult * ll(lx));
			ft_mult_rx.update(rx, mult * ll(rx));
			ft_mult_lx_rx.update(rx, mult * ll(lx) * ll(rx));
		}
		for(int idx : q_by_lx[i]){
			auto [qlx, qrx] = queries[idx];
			ans[idx] =
			- ll(qlx - 1) * ll(qrx + 1) * ft_mult.query(qrx + 1)
			+ ll(qrx + 1) * ft_mult_lx.query(qrx + 1)
			+ ll(qlx - 1) * ft_mult_rx.query(qrx + 1)
			- ll(1) * ft_mult_lx_rx.query(qrx + 1);
		}
	}
	for(ll v : ans){
		cout << v << '\n';
	}
}
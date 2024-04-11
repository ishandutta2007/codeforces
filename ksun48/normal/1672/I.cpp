#include <bits/stdc++.h>
using namespace std;

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder



#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

namespace seg1 {
	using S = pair<int, int>;
	using F = int;
	S e(){ return {1e8, -1}; }
	S op(S l, S r) { return min(l, r); }
	S mapping(F l, S r) { return {r.first + l, r.second}; }
	F composition(F l, F r) { return l + r; }
	F id() { return 0; }
	using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	vector<vector<int> > P(2);
	P[0] = p;
	P[1] = p;
	reverse(P[1].begin(), P[1].end());
	for(int& x : P[1]) x = n-1-x;

	vector<vector<int> > Pinv(2, vector<int>(n));
	for(int side = 0; side < 2; side++){
		for(int i = 0; i < n; i++){
			Pinv[side][P[side][i]] = i;
		}
	}
	vector<int> which(n);
	for(int i = 0; i < n; i++) which[i] = p[i] < i;
	vector<FT> ftx(2, FT(n));
	vector<FT> fty(2, FT(n));
	for(int i = 0; i < n; i++){
		ftx[0].update(i, 1);
		ftx[1].update(i, 1);
		fty[0].update(i, 1);
		fty[1].update(i, 1);
	}
	vector<seg1::segtree> scores(2);
	scores[0] = seg1::segtree(n);
	scores[1] = seg1::segtree(n);
	vector<set<int> > active(2);
	for(int side = 0; side < 2; side++){
		active[side].insert(-1);
		active[side].insert(n);
	}
	vector<seg1::segtree> inactive(2);
	inactive[0] = seg1::segtree(n);
	inactive[1] = seg1::segtree(n);
	for(int i = 0; i < n; i++){
		if(which[i] == 0){
			inactive[0].set(i, {p[i], i});
		} else {
			inactive[1].set(n-1-i, {n-1-p[i], n-1-i});
		}
	}
	auto get_active_interval_l = [&](int side, int r, int P_lb) -> int {
		int s = -1;
		int e = r;
		while(s + 1 < e){
			int m = (s + e) / 2;
			auto f = *active[side].lower_bound(m);
			if(f < n && P[side][f] < P_lb){
				s = m;
			} else {
				e = m;
			}
		}
		return e;
	};
	const int M = 1e8;
	auto ins = [&](int side, int x){
		int r = *active[side].upper_bound(x);
		int Pup = (r == n) ? n : P[side][r];
		while(true){
			int idx = inactive[side].prod(x+1, r).second;
			if(idx < 0) break;
			int val = P[side][idx];
			if(val > Pup) break;
			active[side].insert(idx);
			inactive[side].set(idx, {M, -1});
			int score = fty[side].query(val) - ftx[side].query(idx);
			// cerr << "active " << side << ' ' << idx << ' ' << val << ' ' << score << '\n';
			scores[side].set(idx, {score, idx});
			x = idx;
		}
	};
	ins(0, -1);
	ins(1, -1);
	int ans = 0;
	for(int it = 0; it < n; it++){
		int a = scores[0].all_prod().first;
		int b = scores[1].all_prod().first;
		int side = (a <= b) ? 0 : 1;
		// remove side
		int loc = scores[side].all_prod().second;
		int val = P[side][loc];
		// cerr << "remove " << side << ' ' << loc << ' ' << val << ' ' << min(a,b) << '\n';
		ans = max(ans, min(a, b));
		ftx[side].update(loc, -1);
		fty[side].update(val, -1);
		ftx[1 ^ side].update(n-1-loc, -1);
		fty[1 ^ side].update(n-1-val, -1);

		active[side].erase(loc);
		scores[side].set(loc, {M, loc});

		int r = n-1-loc;
		int l = get_active_interval_l(1 ^ side, r, n-1-val);
		scores[1 ^ side].apply(l, r, -1);
		ins(side, *prev(active[side].lower_bound(loc)));
	}
	cout << ans << '\n';
}
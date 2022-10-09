// some part of the code may be built automatically using atcoder's ac-library
// source: https://github.com/atcoder/ac-library


#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

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

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;
typedef pair <int, int> pii;
typedef pair <int, int> item;

item op(item a, item b) {
	if (a.first > b.first) return a;
	return b;
}

item e() { return item{-1, -1}; }

item op_rev(item a, item b) {
	if (a.first < b.first) return a;
	return b;
}

item e_rev() { return item{1e6, -1}; }

bool is_edge(vector <pii> &cards, int i, int j) {
	if (i == j) return false;
	if (cards[i].first < cards[j].first && cards[j].first < cards[i].second && cards[i].second < cards[j].second) return true;
	swap(i, j);
	if (cards[i].first < cards[j].first && cards[j].first < cards[i].second && cards[i].second < cards[j].second) return true;
	return false;
}

void detect_impossible(vector <pii> &cards) {
	int lmax = INT_MIN, rmin = INT_MAX;
	for (auto &interval : cards) {
		rmin = min(rmin, interval.second);
		lmax = max(lmax, interval.first);
	}
	
	if (rmin < lmax) {
		cout << "-1\n";
		exit(0);
	}
}
int CNT;

void dfs(int node, vector <bool> &vis, int &f, int &uf, segtree<item, op, e> &tree, segtree<item, op_rev, e_rev> &tree_rev, vector <bool> &flipped, vector <pii> &cards, vector <bool> &color) {
	vis[node] = true;
	tree.set(cards[node].first, e());
	tree_rev.set(cards[node].second, e_rev());
	if (flipped[node] == color[node]) ++f;
	else ++uf;
	
	item query = e();
	while (true) {
		query = tree.prod(cards[node].first + 1, cards[node].second);
		if (query.first == -1) break;
		else {	
			if (!vis[query.second] && is_edge(cards, node, query.second)) {
				color[query.second] = (1 ^ color[node]);
				dfs(query.second, vis, f, uf, tree, tree_rev, flipped, cards, color);
			}
			else break;
		}
	}
	
	query = e_rev();
	while (true) {
		query = tree_rev.prod(cards[node].first + 1, cards[node].second);
		if (query.first == 1e6) break;
		else {
			if (!vis[query.second] && is_edge(cards, node, query.second)) {
				color[query.second] = (1 ^ color[node]);
				dfs(query.second, vis, f, uf, tree, tree_rev, flipped, cards, color);
			}
			else break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
	vector <pii> cards(n);
	vector <bool> flipped(n);
	
    for (int i=0; i<n; ++i) {
		cin >> cards[i].first >> cards[i].second;
		if (cards[i].first > cards[i].second) {
			flipped[i] = true;
			swap(cards[i].first, cards[i].second);
		}
	}
	
	detect_impossible(cards);
	
    segtree<item, op, e> tree(2 * n + 1);
    segtree<item, op_rev, e_rev> tree_rev(2 * n + 1);
    
    for (int i=0; i<n; ++i) {
		tree.set(cards[i].first, item{cards[i].second, i});
		tree_rev.set(cards[i].second, item{cards[i].first, i});
	}
	
	int result = 0;
	int f = 0, uf = 0;
	vector <bool> vis(n, false);
	vector <bool> color(n, false);
	
	for (int i=0; i<n; ++i) {
		if (!vis[i]) {
			dfs(i, vis, f, uf, tree, tree_rev, flipped, cards, color);
			result += min(f, uf);
			f = uf = 0;
		}
	}
	
	// we now have a spanning tree and candidate for result
	// we do need to check if the graph is bipartite
	
	bool bipartite = true;
	for (int clr = 0; clr < 2; ++clr) {
		segtree<item, op, e> ntree(2 * n + 1);
		//setting edges of this color
		for (int i=0; i<n; ++i) {
			if (color[i] == clr) ntree.set(cards[i].first, item{cards[i].second, i});
		}
		
		for (int i=0; i<n; ++i) {
			if (color[i] == clr) {
				item query = ntree.prod(cards[i].first+1, cards[i].second);
				int j = query.second;
				if (j == -1) continue;
				if (is_edge(cards, i, j)) bipartite = false;
			}
		}
	}
	
	if (!bipartite) cout << "-1\n";
	else cout << result << "\n";
}
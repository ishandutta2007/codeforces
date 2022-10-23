#include <bits/stdc++.h>


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

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
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

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
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

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
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

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
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

using namespace std;

const int MAXN = 1050000;

struct node {
    int next[26];
    int len;
    int sufflink;
    int num;
};

int len;
string s;
node tree[MAXN]; 
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome

bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])     
            break;  
        cur = tree[cur].sufflink;
    }       
    if (tree[cur].next[let]) {  
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }       
    }           

    tree[num].num = 1 + tree[tree[num].sufflink].num;

    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}

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

int op(int a, int b){
	return max(a, b);
}
int e(){
	return -1e8;
}

vector<int> solve(string str, vector<pair<int,int>> queries){
	for(int i = 0; i < MAXN; i++){
		for(int c = 0; c < 26; c++){
			tree[i].next[c] = 0;
		}
		tree[i].len = tree[i].sufflink = tree[i].num = 0;
	}
	int N = (int)str.size();
	s = str;
	len = s.size();
	vector<int> suff_pal(N+1);
	suff_pal[0] = suff;

	initTree();
	for(int i = 1; i <= N; i++){
		addLetter(i-1);
		suff_pal[i] = suff;
	}

	int V = num + 1;
	vector<int> par(V);
	vector<vector<int> > ch(V);
	vector<int> len(V);
	for(int i = 1; i < V; i++){
		if(i > 1) ch[tree[i].sufflink].push_back(i);
		par[i] = tree[i].sufflink;
		len[i] = tree[i].len;
		if(i > 1) assert(len[i] > len[par[i]]);
	}
	int J = 21;
	vector<vector<int> > jump(J, vector<int>(V));
	jump[0] = par;
	for(int j = 1; j < J; j++){
		for(int v = 1; v < V; v++){
			jump[j][v] = jump[j-1][jump[j-1][v]];
		}
	}
	vector<int> qans(queries.size(), 1);
	vector<vector<tuple<int, int, int> > > qloc(N+1);
	for(int q = 0; q < queries.size(); q++){
		auto [en, st] = queries[q];
		assert(en > st);
		int v = suff_pal[en];
		assert(v < V);
		for(int j = J-1; j >= 0; j--){
			while(len[jump[j][v]] > en-st) v = jump[j][v];
		}
		if(len[v] > en-st) v = par[v];
		int l = len[v];
		assert(l <= en-st);
		qloc[en-1].push_back({q, v, st + l});
	}
	vector<pair<int,int> > intervals(V);
	int T = 0;
	y_combinator([&](auto self, int v) -> void {
		intervals[v].first = T;
		T++;
		for(int w : ch[v]) self(w);
		intervals[v].second = T;
	})(1);
	atcoder::segtree<int, op, e> seg(T+1);
	// cerr << s << '\n';
	for(int i = 0; i <= N; i++){
		int v = suff_pal[i];
		// update v to i
		seg.set(intervals[v].first, i);
		for(auto [q, v, st] : qloc[i]){
			auto [l, r] = intervals[v];
			int loc = seg.prod(l, r);
			if(loc >= 0 && loc >= st){
				qans[q] = 0;
			}
		}
	}
	for(int q = 0; q < queries.size(); q++){
		auto [en, st] = queries[q];
		// cerr << en << ' ' << st << qans[q] << '\n';
	}
	return qans;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int Q;
	cin >> Q;
	string tot;
	vector<pair<int,int> > qp;
	int st = 0;
	int en = 0;
	vector<pair<int,int> > fwd, bk;
	for(int qidx = 0; qidx < Q; qidx++){
		string type;
		cin >> type;
		if(type == "pop"){
			bk.push_back({st, en});
			st++;
		} else if(type == "push"){
			char c;
			cin >> c;
			tot += c;
			en++;
			fwd.push_back({en, st});
		} else assert(false);
		qp.push_back({st, en});
	}
	map<pair<int,int>, int64_t> ret;
	{
		vector<int> r = solve(tot, fwd);
		for(int i = 0; i < fwd.size(); i++){
			ret[fwd[i]] = r[i];
		}
	}
	{
		string rtot(tot.rbegin(), tot.rend());
		vector<pair<int,int> > queries = bk;
		for(auto& [x, y] : queries){
			x = rtot.size() - x;
			y = rtot.size() - y;
		}
		reverse(queries.begin(), queries.end());
		vector<int> r = solve(rtot, queries);
		reverse(r.begin(), r.end());
		for(int i = 0; i < bk.size(); i++){
			ret[bk[i]] = r[i];
		}
	}
	st = 0;
	en = 0;
	int64_t cnt = 0;
	for(int i = 0; i < Q; i++){
		if(st < qp[i].first){
			cnt -= ret[{st, en}];
			st++;
		} else {
			en++;
			cnt += ret[{en, st}];
		}
		cout << cnt << '\n';
	}
}
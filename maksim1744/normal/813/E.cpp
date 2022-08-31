/**
  the_hyp0cr1t3
  29.06.2021 23:15:01
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

template<class T, bool ONE = true>
class Segtree {
    struct Node { int lc{-1}, rc{-1}; T info; };

    int N, size{1}, version_cnt{0};
    deque<Node> st; vector<int> version;

    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    int create(int id = 0) {
        st.emplace_back(st[id]);
        return size++;
    }

    template<typename It>
    void build(int node, int L, int R, It beg, It end, bool opt) {
        if(L == R)
            return st[node].info = static_cast<T>(*beg), void();
        int M = L + R >> 1;

        int lc = st[node].lc = create();
        build(lc, L, M, beg, beg + (opt? M - L : 0), opt);

        int rc = st[node].rc = create();
        build(rc, M + 1, R, beg + (opt? M - L + 1 : 0), end, opt);

        st[node].info = T(st[lc].info, st[rc].info);
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(ql == L and R == qr) return st[node].info;
        int M = L + R >> 1;
        return qr <= M? Query(st[node].lc, L, M, ql, qr)
                        : M < ql? Query(st[node].rc, M + 1, R, ql, qr)
                            : T(Query(st[node].lc, L, M, ql, M),
                                    Query(st[node].rc, M + 1, R, M + 1, qr));
    }

    void Update(int node, int L, int R, int pos, int64_t val) {
        if(L == R) return st[node].info.upd(val);
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;
        if(pos <= M) {
            lc = st[node].lc = create(lc);
            Update(lc, L, M, pos, val);
        } else {
            rc = st[node].rc = create(rc);
            Update(rc, M + 1, R, pos, val);
        }

        st[node].info = T(st[lc].info, st[rc].info);
    }

public:

    template<class... Args>
    Segtree(int N, Args&&... args): N(N), st(1) {
        // st.reserve(ceil2n(N));
        T val(forward<Args>(args)...);
        version.push_back(create()); version_cnt++;
        build(1, ONE, N - !ONE, &val, &val, false);
    }

    template<typename It,
        typename = enable_if_t<is_same<typename iterator_traits<It>::iterator_category,
                                            random_access_iterator_tag>::value,
                                typename iterator_traits<It>::difference_type>>
    Segtree(It beg, It end): N(end - beg), st(1) {
        // st.reserve(ceil2n(N));
        version.push_back(create()); version_cnt++;
        build(1, ONE, N - !ONE, beg, end, true);
    }

    T query(int ver, int qpos) {
        if(ver == -1) ver = version_cnt - 1;
        return Query(version[ver], ONE, N - !ONE, qpos, qpos);
    }

    T query(int ver, int ql, int qr) {
        if(ver == -1) ver = version_cnt - 1;
        return Query(version[ver], ONE, N - !ONE, ql, qr);
    }

    int copy(int ver) {
        version.push_back(create(version[ver]));
        return version_cnt++;
    }

    int update(int ver, int pos, int64_t val) {
        if(ver == -1) ver = version_cnt - 1;
        version.push_back(create(version[ver]));
        Update(version[version_cnt], ONE, N - !ONE, pos, val);
        return version_cnt++;
    }

};

struct Node {
    int64_t val;
    Node(int64_t val = 0): val(val) {}
    Node(const Node& l, const Node& r)
        : val(l.val + r.val) {}
    void upd(int64_t delta) { val += delta; }
    operator int64_t() const { return val; }
};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    Segtree<Node, false> seg(n+1);
    array<queue<int>, N> occ;
    for(i = 1; i <= n; i++) {
        if(sz(occ[a[i-1]]) == k) {
            seg.update(-1, occ[a[i-1]].front(), +1);
            occ[a[i-1]].pop();
        } else {
            seg.update(-1, 0, +1);
        }
        occ[a[i-1]].push(i);
    }

    int Q, ans = 0; cin >> Q;
    while(Q--) {
        int X, Y; cin >> X >> Y;
        int l = (X + ans) % n + 1, r = (Y + ans) % n + 1;
        if(l > r) swap(l, r);
        ans = seg.query(r, 0, l-1) - seg.query(l-1, 0, l-1);
        cout << ans << '\n';
    }

} // ~W.
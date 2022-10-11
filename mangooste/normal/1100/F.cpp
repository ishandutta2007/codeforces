#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

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


const int N = 1e6 + 4;
const int LG = __lg(N) + 1;

struct gauss {
    int bit[LG];

    gauss() { fill(all(bit), -1); }

    inline int get_max() {
        int x = 0;
        for (int i = LG - 1; i >= 0; i--) {
            if (bit[i] != -1) x = max(x, x ^ bit[i]);
        }
        return x;
    }

    inline void insert(int x) {
        while (x != 0) {
            int b = __lg(x);
            if (bit[b] == -1) {
                bit[b] = x;
                break;
            }
            x ^= bit[b];
        }
    }

    inline gauss operator+(const gauss nd) {
        gauss res = *this;
        for (int i = 0; i < LG; i++) {
            if (nd.bit[i] != -1) res.insert(nd.bit[i]);
        }
        return res;
    }
};

struct query {
    int l, r, id;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    int tree_sz = 4 * n;
    vec<int> par(tree_sz), tin(tree_sz), tout(tree_sz), leaf(n);
    vec<vec<query>> queries(tree_sz);
    int timer = 0;
    y_combinator([&](auto init, int v, int vl, int vr) -> void {
        tin[v] = timer++;
        if (vr - vl > 1) {
            int vm = (vl + vr) / 2;
            par[v << 1] = par[v << 1 | 1] = v;
            init(v << 1, vl, vm);
            init(v << 1 | 1, vm, vr);
        } else {
            leaf[vl] = v;
        }
        tout[v] = timer;
    })(1, 0, n);
    auto is_par = [&](int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    };
    auto lca = [&](int v, int u) {
        if (is_par(v, u)) return v;
        while (!is_par(v, u)) {
            v = par[v];
        }
        return v;
    };
    int q;
    cin >> q;
    vec<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r, l--, r--;
        queries[lca(leaf[l], leaf[r])].push_back({l, r, i});
    }
    y_combinator([&](auto solve, int v, int vl, int vr) -> void {
        int vm = (vl + vr) / 2;
        if (vr - vl > 1) {
            solve(v << 1, vl, vm);
            solve(v << 1 | 1, vm, vr);
        }
        int mn_left = vm;
        int mx_right = vm;
        for (auto [l, r, id] : queries[v]) {
            assert(l <= vm && r < vr);
            mn_left = min(mn_left, l);
            mx_right = max(mx_right, r);
        }
        vec<gauss> left(vm - mn_left + 1);
        for (int i = 1; i < len(left); i++) {
            left[i] = left[i - 1];
            left[i].insert(c[vm - i]);
        }
        vec<gauss> right(mx_right - vm + 2);
        for (int i = 1; i < len(right); i++) {
            right[i] = right[i - 1];
            right[i].insert(c[vm + i - 1]);
        }
        for (auto [l, r, id] : queries[v]) {
            ans[id] = (left[vm - l] + right[r - vm + 1]).get_max();
        }
    })(1, 0, n);
    for (auto x : ans) {
        cout << x << '\n';
    }
}
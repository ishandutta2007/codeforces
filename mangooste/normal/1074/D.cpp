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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int q;
    cin >> q;
    int n = 0;
    vec<int> par, dist;
    vec<vec<int>> comp;
    map<int, int> id;
    int last = 0;
    auto get_id = [&](int x) {
        if (id.find(x) != id.end()) return id[x];
        par.push_back(n);
        dist.push_back(0);
        comp.push_back({n});
        id[x] = n;
        return n++;
    };
    auto get_par = y_combinator([&](auto get_par, int v) -> int {
        return par[v] == v ? v : par[v] = get_par(par[v]);
    });
    auto get_res = [&](int v, int u) {
        if (get_par(v) != get_par(u)) return -1;
        return dist[v] ^ dist[u];
    };
    auto unite = [&](int v, int u, int x) {
        int pv = get_par(v), pu = get_par(u);
        if (pv == pu) return;
        if (len(comp[pv]) < len(comp[pu])) swap(v, u), swap(pv, pu);
        x ^= dist[v] ^ dist[u];
        for (auto w : comp[pu]) {
            par[w] = pv;
            dist[w] ^= x;
            comp[pv].push_back(w);
        }
    };
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last, r ^= last, x ^= last;
            if (l > r) swap(l, r);
            l = get_id(l), r = get_id(r + 1);
            int real = get_res(l, r);
            if (real != -1 && real != x) continue;
            unite(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last, r ^= last;
            if (l > r) swap(l, r);
            int ans = get_res(get_id(l), get_id(r + 1));
            cout << ans << '\n';
            last = abs(ans);
        }
    }
}
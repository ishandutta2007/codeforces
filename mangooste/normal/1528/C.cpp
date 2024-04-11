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

const int N = 3e5 + 4;

struct segtree {
    int tree[2 * N];

    segtree() {}

    void add(int pos, int value) {
        pos += N;
        tree[pos] += value;

        for (pos >>= 1; pos > 0; pos >>= 1)
            tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
    }

    int get(int l, int r) {
        int sum = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                sum += tree[l++];

            if (r & 1)
                sum += tree[--r];
        }

        return sum;
    }
};

struct Tree {
    vec<int> g[N];
    int tin[N], tout[N], timer = 0;

    Tree() {}

    void add(int par, int v) {
        g[par].push_back(v);
    }

    void dfs(int v) {
        tin[v] = timer++;
        for (auto u : g[v])
            dfs(u);

        tout[v] = timer;
    }

    void init() {
        dfs(0);
    }
};

vec<int> g[N];
Tree tree;

segtree seg;
int ans;
set<pair<int, int>> st;

pair<int, int> insert(int v) {
    seg.add(tree.tin[v], 1);

    if (seg.get(tree.tin[v] + 1, tree.tout[v]) > 0)
        return {-2, -2};

    pair<int, int> erased{-1, -1};

    auto it = st.lower_bound({tree.tin[v], tree.tout[v]});
    if (it != st.begin()) {
        it--;
        assert(it->first <= tree.tin[v]);
        if (it->second >= tree.tout[v]) {
            erased = *it;
            st.erase(*it);
        }
    }

    st.insert({ tree.tin[v], tree.tout[v] });
    return erased;
}

void solve(int v) {
    auto erased = insert(v);
    ans = max(ans, len(st));

    for (auto u : g[v])
        solve(u);

    seg.add(tree.tin[v], -1);

    if (erased.first == -2)
        return;

    st.erase({ tree.tin[v], tree.tout[v] });
    if (erased.first != -1)
        st.insert(erased);
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int par;
        cin >> par, par--;
        g[par].push_back(i);
    }

    for (int i = 1; i < n; i++) {
        int par;
        cin >> par, par--;
        tree.add(par, i);
    }

    tree.init();

    solve(0);
    cout << ans << '\n';

    ans = 1;
    tree.timer = 0;
    for (int i = 0; i < n; i++) {
        tree.g[i].clear();
        g[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
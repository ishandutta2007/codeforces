#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

struct segtree {
    struct node {
        pair<int, int> mn;
        pair<int, int> second_mn;
        pair<int, int> mx;
        pair<int, int> mod;

        node() {}
        node(const pair<int, int> &x) : mn(x), second_mn({1e8, -1}), mx(x), mod({INT_MIN, -1}) {}
    };

    int n;
    vector<node> tree;

    segtree(int n) : n(n), tree(4 * n, node({{0, -1}})) {
        build(1, 0, n);
    }

    node merge(node left, node right) {
        if (left.mn > right.mn)
            swap(left, right);

        node res;
        res.mn = left.mn;
        res.second_mn = right.mn == left.mn ? min(left.second_mn, right.second_mn) : right.mn;
        res.mx = max(left.mx, right.mx);
        res.mod = {INT_MIN, -1};
        return res;
    }

    void build(int v, int vl, int vr) {
        if (vr - vl == 1)
            return;

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    void push(int v, int vl, int vr) {
        if (tree[v].mod.first == INT_MIN)
            return;

        assert(tree[v].mod < tree[v].second_mn);
        if (vr - vl > 1) {
            tree[v << 1].mod = max(tree[v << 1].mod, tree[v].mod);
            tree[v << 1 | 1].mod = max(tree[v << 1 | 1].mod, tree[v].mod);
        }

        tree[v].mn = max(tree[v].mn, tree[v].mod);
        tree[v].mx = max(tree[v].mx, tree[v].mod);
        tree[v].mod = {INT_MIN, -1};
    }

    void setmax(int l, int r, const pair<int, int> &value) {
        setmax(1, 0, n, l, r, value);
    }

    void setmax(int v, int vl, int vr, int l, int r, const pair<int, int> &value) {
        push(v, vl ,vr);
        if (r <= vl || vr <= l || tree[v].mn >= value)
            return;

        if (l <= vl && vr <= r && tree[v].second_mn > value) {
            tree[v].mod = value;
            push(v, vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        setmax(v << 1, vl, vm, l, r, value);
        setmax(v << 1 | 1, vm, vr, l, r, value);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 0, n, l, r);
    }

    pair<int, int> query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return {INT_MIN, -1};

        if (l <= vl && vr <= r)
            return tree[v].mx;

        int vm = (vl + vr) >> 1;
        return max(query(v << 1, vl, vm, l, r), query(v << 1 | 1, vm, vr, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> segs(n);
    vector<int> values;
    values.reserve(2 * m);

    while (m--) {
        int i, l, r;
        cin >> i >> l >> r;
        segs[i - 1].emplace_back(l, r);
        values.push_back(l);
        values.push_back(r);
    }

    sort(all(values));
    values.resize(unique(all(values)) - values.begin());

    auto query_real_x = [&](int x) {
        return lower_bound(all(values), x) - values.begin();
    };

    for (int i = 0; i < n; i++)
        for (auto &[l, r] : segs[i])
            l = query_real_x(l), r = query_real_x(r) + 1;

    const int SZ = len(values);
    segtree tree(SZ);

    vector<int> dp(n);
    iota(all(dp), 0);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        for (const auto &[l, r] : segs[i]) {
            const auto [best, from] = tree.query(l, r);
            if (dp[i] > -best + i) {
                dp[i] = -best + i;
                parent[i] = from;
            }
        }

        for (const auto &[l, r] : segs[i])
            tree.setmax(l, r, {-(dp[i] - i - 1), i});
    }

    auto get_value = [&](int pos) {
        return n - 1 - pos + dp[pos];
    };

    int best = n - 1;
    for (int i = n - 2; i >= 0; i--)
        if (get_value(i) < get_value(best))
            best = i;

    vector<int> answer;
    for (int i = n - 1; i > best; i--)
        answer.push_back(i);

    for (int i = best; i != -1; i = parent[i])
        for (int j = parent[i] + 1; j < i; j++)
            answer.push_back(j);

    assert(len(answer) == get_value(best));
    cout << len(answer) << '\n';
    for (auto x : answer)
        cout << x + 1 << ' ';

    cout << '\n';
}
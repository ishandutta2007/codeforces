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

template<bool minimum_mode>
struct segtree {
    int n;
    vector<pair<int, int>> tree;

    segtree(int n, const pair<int, int> &value) : n(n), tree(4 * n, value) {}

    void set(int pos, const pair<int, int> &value) {
        set(1, 0, n, pos, value);
    }

    void set(int v, int vl, int vr, int pos, const pair<int, int> &value) {
        if (vr - vl == 1) {
            tree[v] = value;
            return;
        }

        int vm = (vl + vr) >> 1;
        pos < vm ? set(v << 1, vl, vm, pos, value) : set(v << 1 | 1, vm, vr, pos, value);
        tree[v] = minimum_mode ? min(tree[v << 1], tree[v << 1 | 1]) : max(tree[v << 1], tree[v << 1 | 1]);
    }

    pair<int, int> get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    pair<int, int> get(int v, int vl, int vr, int l, int r) {
        assert(min(l, vl) < max(r, vr));
        if (l <= vl && vr <= r)
            return tree[v];

        int vm = (vl + vr) >> 1;
        if (l < vm && vm < r)
            return minimum_mode ? min(get(v << 1, vl, vm, l, r), get(v << 1 | 1, vm, vr, l, r)) :
                max(get(v << 1, vl, vm, l, r), get(v << 1 | 1, vm, vr, l, r));

        return l < vm ? get(v << 1, vl, vm, l, r) : get(v << 1 | 1, vm, vr, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i], l[i]--;

    vector<vector<pair<int, int>>> events(n + 1);
    for (int i = 0; i < n; i++) {
        events[l[i]].emplace_back(i, 0);
        events[r[i]].emplace_back(i, 1);
    }

    auto cmp = [&](int i, int j) {
        return r[i] < r[j] || (r[i] == r[j] && i < j);
    };
    set<int, decltype(cmp)> open(cmp);
    vector<int> solution(n);

    for (int i = 0; i < n; i++) {
        for (const auto &[id, type] : events[i])
            if (type == 0)
                open.insert(id);
            else
                open.erase(id);

        assert(!open.empty());
        solution[*open.begin()] = i;
        open.erase(open.begin());
    }

    auto answer = [&](int i, int who) {
        cout << "NO\n";
        for (auto x : solution)
            cout << x + 1 << ' ';

        cout << '\n';
        swap(solution[i], solution[who]);
        for (auto x : solution)
            cout << x + 1 << ' ';

        cout << '\n';
    };

    {
        segtree<false> tree(n, {INT_MIN, -1});
        for (int i = 0; i < n; i++)
            tree.set(solution[i], {r[i], i});

        for (int i = 0; i < n; i++) {
            if (l[i] == solution[i])
                continue;

            const auto [r, who] = tree.get(l[i], solution[i]);
            if (r > solution[i]) {
                answer(i, who);
                return 0;
            }
        }
    }

    {
        segtree<true> tree(n, {INT_MAX, -1});
        for (int i = 0; i < n; i++)
            tree.set(solution[i], {l[i], i});

        for (int i = 0; i < n; i++) {
            if (solution[i] + 1 == r[i])
                continue;

            const auto [l, who] = tree.get(solution[i] + 1, r[i]);
            if (l <= solution[i]) {
                answer(i, who);
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (auto x : solution)
        cout << x + 1 << ' ';

    cout << '\n';
}
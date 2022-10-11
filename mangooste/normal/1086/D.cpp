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

int get_id(char c) {
    if (c == 'R')
        return 0;

    if (c == 'S')
        return 1;

    return 2;
}

struct segtree {
    struct node {
        int cnt[3];

        node() {
            fill(all(cnt), 0);
        }

        node(int x) {
            fill(all(cnt), 0);
            cnt[x] = 1;
        }

        node operator+(const node &nd) const {
            node res;
            for (int i = 0; i < 3; i++)
                res.cnt[i] = cnt[i] + nd.cnt[i];

            return res;
        }
    };

    int n;
    vec<node> tree;

    segtree() {}

    segtree(int n) : n(n), tree(2 * n) {}

    void set(int pos, int x) {
        pos += n;
        tree[pos] = node(x);
        for (pos >>= 1; pos > 0; pos >>= 1)
            tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
    }

    node get(int l, int r) {
        node res;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = res + tree[l++];

            if (r & 1)
                res = res + tree[--r];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vec<int> a(n);
    for (auto &x : a) {
        char c;
        cin >> c;
        x = get_id(c);
    }

    segtree tree(n);
    for (int i = 0; i < n; i++)
        tree.set(i, a[i]);

    ar<set<int>, 3> positions;
    for (int i = 0; i < n; i++)
        positions[a[i]].insert(i);

    auto solve = [&]() {
        auto count = tree.tree[1].cnt;
        int positive = 0;
        for (int i = 0; i < 3; i++)
            positive += count[i] > 0;

        if (positive == 1)
            return n;

        if (positive == 2)
            for (int i = 0; i < 3; i++)
                if (count[i] > 0 && count[(i + 1) % 3] > 0)
                    return count[i];

        int ans = n;
        for (int i = 0; i < 3; i++) {
            pair<int, int> seg1{ *positions[(i + 2) % 3].begin(), *positions[(i + 1) % 3].begin() };
            pair<int, int> seg2{ *positions[(i + 1) % 3].rbegin(), *positions[(i + 2) % 3].rbegin() };

            ans -= tree.get(seg1.first, seg1.second).cnt[i];
            ans -= tree.get(seg2.first, seg2.second).cnt[i];

            if (seg1.first < seg1.second && seg2.first < seg2.second)
                ans += tree.get(max(seg1.first, seg2.first), min(seg1.second, seg2.second)).cnt[i];
        }

        return ans;
    };

    cout << solve() << '\n';

    while (q--) {
        int pos;
        char c;
        cin >> pos >> c, pos--;

        positions[a[pos]].erase(pos);
        a[pos] = get_id(c);
        positions[a[pos]].insert(pos);

        tree.set(pos, get_id(c));
        cout << solve() << '\n';
    }
}
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
    int n;
    vector<ll> tree;

    segtree(int n) : n(n), tree(2 * n) {}

    void setmax(int pos, ll value) {
        pos += n;
        tree[pos] = max(tree[pos], value);
        for (pos >>= 1; pos; pos >>= 1)
            tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
    }

    ll get(int l, int r) {
        ll answer = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                answer = max(answer, tree[l++]);

            if (r & 1)
                answer = max(answer, tree[--r]);
        }
        return answer;
    }
};

struct tower {
    int a, b, h;

    bool operator<(const tower &t) const {
        return b > t.b || (b == t.b && a > t.a);
    }

    friend istream& operator>>(istream &in, tower &t) {
        return in >> t.a >> t.b >> t.h;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<tower> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> values;
    values.reserve(2 * n);
    for (const auto &x : a) {
        values.push_back(x.a);
        values.push_back(x.b);
    }

    sort(all(values));
    values.resize(unique(all(values)) - values.begin());
    for (auto &x : a) {
        x.a = lower_bound(all(values), x.a) - values.begin();
        x.b = lower_bound(all(values), x.b) - values.begin();
    }

    sort(all(a));
    int m = len(values);
    segtree tree(m);

    for (auto &x : a) {
        ll mx = tree.get(0, x.b) + x.h;
        tree.setmax(x.a, mx);
    }

    cout << tree.get(0, m) << '\n';
}
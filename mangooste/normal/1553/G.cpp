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

struct disjoin_set_union {
    std::vector<int> parent;
    std::vector<int> rank;

    disjoin_set_union(int n = 0) : parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) ? parent[v] = root(parent[v]) : v;
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    const int A = 1e6 + 444;
    vector<int> a(n);
    vector<char> used(A);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        used[a[i]] = 1;
    }

    disjoin_set_union dsu(A);
    for (int x = 2; x < A; x++)
        for (int y = x; y < A; y += x)
            if (used[y])
                dsu.unite(x, y);

    set<int> valid_roots;
    for (auto x : a)
        valid_roots.insert(dsu.root(x));

    vector<pair<int, int>> edges;
    for (auto x : a) {
        vector<int> good_roots{dsu.root(x)};
        for (int j = 1; j * j <= x + 1; j++)
            if ((x + 1) % j == 0) {
                if (j != 1 && valid_roots.count(dsu.root(j)))
                    good_roots.push_back(dsu.root(j));

                if (j * j != x + 1 && valid_roots.count(dsu.root((x + 1) / j)))
                    good_roots.push_back(dsu.root((x + 1) / j));
            }

        sort(all(good_roots));
        good_roots.resize(unique(all(good_roots)) - good_roots.begin());
        for (int i = 0; i < len(good_roots); i++)
            for (int j = i + 1; j < len(good_roots); j++)
                edges.emplace_back(minmax(good_roots[i], good_roots[j]));
    }
    sort(all(edges));

    while (q--) {
        int i, j;
        cin >> i >> j;
        i = dsu.root(a[i - 1]);
        j = dsu.root(a[j - 1]);

        if (i == j) {
            cout << "0\n";
        } else if (binary_search(all(edges), pair<int, int>(minmax(i, j)))) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}
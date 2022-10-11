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

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    disjoin_set_union dsu1(n);
    while (m1--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        dsu1.unite(v, u);
    }

    disjoin_set_union dsu2(n);
    while (m2--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        dsu2.unite(v, u);
    }

    vector<pair<int, int>> answer;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dsu1.root(i) != dsu1.root(j) && dsu2.root(i) != dsu2.root(j)) {
                answer.emplace_back(i, j);
                dsu1.unite(i, j);
                dsu2.unite(i, j);
            }

    cout << len(answer) << '\n';
    for (const auto &[v, u] : answer)
        cout << v + 1 << ' ' << u + 1 << '\n';
}
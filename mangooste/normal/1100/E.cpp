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

const int N = 1e5 + 4;
vec<pair<int, int>> g[N];
vec<ar<int, 3>> edges;
int n, m;

inline vec<int> solve(int x) {
    vec<int> in_deg(n);
    for (auto [i, j, w] : edges) {
        if (w > x) in_deg[j]++;
    }
    vec<int> que;
    que.reserve(n);
    for (int i = 0; i < n; i++) {
        if (!in_deg[i]) que.push_back(i);
    }
    for (int st = 0; st < len(que); st++) {
        int v = que[st];
        for (auto [u, w] : g[v]) {
            if (w <= x) continue;
            in_deg[u]--;
            if (!in_deg[u]) que.push_back(u);
        }
    }
    return que;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    vec<int> costs{0};
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w, v--, u--;
        g[v].emplace_back(u, w);
        costs.push_back(w);
        edges.push_back({v, u, w});
    }
    sort(all(costs));
    costs.resize(unique(all(costs)) - costs.begin());
    int l = -1, r = len(costs) - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (len(solve(costs[mid])) == n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    auto ord = solve(costs[r]);
    assert(len(ord) == n);
    vec<int> where(n);
    for (int i = 0; i < n; i++) {
        where[ord[i]] = i;
    }
    vec<int> bad;
    for (int id = 0; id < m; id++) {
        auto [i, j, w] = edges[id];
        if (w > costs[r]) continue;
        if (where[i] > where[j]) bad.push_back(id);
    }
    cout << costs[r] << ' ' << len(bad) << '\n';
    for (auto x : bad) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}
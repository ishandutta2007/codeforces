#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<ll> bal(n, 0);
    for (int i = 0; i < m; i++) {
        int v, u, d; cin >> v >> u >> d;
        v--, u--;
        bal[v] += d;
        bal[u] -= d;
    }

    array<vector<int>, 2> all;
    for (int i = 0; i < n; i++) {
        if (bal[i] == 0) continue;
        all[bal[i] > 0].push_back(i);
        bal[i] = abs(bal[i]);
    }
    vector<pair<pair<int, int>, ll>> edges;
    int j = 0;
    for (auto v : all[1]) {
        while (bal[v]) {
            int u = all[0][j];
            ll z = min(bal[v], bal[u]);
            edges.push_back({ {v, u}, z });
            bal[v] -= z;
            bal[u] -= z;
            if (!bal[u]) j++;
        }
    }
    cout << sz(edges) << '\n';
    for (auto [p, d] : edges) {
        cout << p.first + 1 << ' ' << p.second + 1 << ' ' << d << '\n';
    }
}
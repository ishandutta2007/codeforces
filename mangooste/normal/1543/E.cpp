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

void solve() {
    int m;
    cin >> m;
    int n = 1 << m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m * n / 2; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
        sort(all(g[i]));

    vector<char> used(n);
    used[0] = 1;
    for (auto v : g[0])
        used[v] = 1;

    vector<int> p(n, -1);
    p[0] = 0;
    for (int i = 0; i < m; i++)
        p[1 << i] = g[0][i];

    for (int i = 1; i < n; i++)
        if (i & (i - 1)) {
            int x = i ^ (1 << __lg(i));
            int y = i ^ (1 << __lg(x));
            assert(x != y);

            for (auto v : g[p[x]])
                if (!used[v] && binary_search(all(g[p[y]]), v)) {
                    assert(p[i] == -1);
                    p[i] = v;
                    used[v] = 1;
                }

            assert(p[i] != -1);
        }

    for (auto x : p)
        cout << x << ' ';

    cout << '\n';

    if (n % m) {
        cout << "-1\n";
        return;
    }

    vector<int> col(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1)
                col[p[i]] ^= j;

    for (auto x : col)
        cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while  (tests--)
        solve();
}
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

void solve_test() {
    int n;
    cin >> n;
    vector<int> parent(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> parent[i], parent[i]--;
        g[parent[i]].push_back(i);
    }

    vector<int> a(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];

    vector<ll> dp(n);
    vector<int> current{0};

    while (true) {
        vector<int> row;
        for (auto v : current)
            for (auto u : g[v])
                row.push_back(u);

        if (row.empty())
            break;

        int mn = a[row[0]], mx = a[row[0]];
        for (auto v : row) {
            mn = min(mn, a[v]);
            mx = max(mx, a[v]);
        }
        for (auto v : row)
            dp[v] = dp[parent[v]] + max(a[v] - mn, mx - a[v]);

        sort(all(row), [&](int i, int j) {
            return a[i] < a[j];
        });

        vector<ll> suf_max(len(row));
        for (int i = len(row) - 1; i >= 0; i--) {
            suf_max[i] = dp[parent[row[i]]] + a[row[i]];
            if (i != len(row) - 1)
                suf_max[i] = max(suf_max[i], suf_max[i + 1]);
        }

        ll pref_max = LLONG_MIN;
        for (int i = 0; i < len(row); i++) {
            pref_max = max(pref_max, dp[parent[row[i]]] - a[row[i]]);
            dp[row[i]] = max({dp[row[i]], pref_max + a[row[i]], suf_max[i] - a[row[i]]});
        }

        current = row;
    }

    cout << *max_element(all(dp)) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve_test();
}
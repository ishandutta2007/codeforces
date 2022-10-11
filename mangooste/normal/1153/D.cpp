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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> op(n);
    for (auto &x : op)
        cin >> x;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        g[parent - 1].push_back(i);
    }

    vector<int> dp(n);
    vector<int> size(n);
    for (int i = n - 1; i >= 0; i--) {
        if (g[i].empty()) {
            size[i] = 1;
            continue;
        }

        for (auto u : g[i])
            size[i] += size[u];

        if (op[i] == 0) {
            for (auto u : g[i])
                dp[i] += dp[u];
        } else {
            for (auto u : g[i])
                dp[i] = max(dp[i], size[i] - size[u] + dp[u]);
        }
    }

    cout << dp[0] + 1 << '\n';
}
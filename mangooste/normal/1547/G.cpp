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

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    inline decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rev_g(n);
    vector<char> bad(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        if (v == u)
            bad[v] = 1;
        else {
            g[v].push_back(u);
            rev_g[u].push_back(v);
        }
    }

    vector<char> used(n);
    vector<int> order;
    for (int i = 0; i < n; i++)
        if (!used[i])
            y_combinator([&](auto dfs, int v) -> void {
                used[v] = 1;
                for (auto u : g[v])
                    if (!used[u])
                        dfs(u);

                order.push_back(v);
            })(i);

    int current = 0;
    vector<int> who(n, -1);
    vector<vector<int>> comps;
    reverse(all(order));
    for (auto v : order)
        if (who[v] == -1) {
            comps.push_back({});
            y_combinator([&](auto dfs, int v) -> void {
                comps.back().push_back(v);
                who[v] = current;
                for (auto u : rev_g[v])
                    if (who[u] == -1)
                        dfs(u);
            })(v);
            current++;
        }

    vector<char> inf(current);
    for (int i = 0; i < current; i++) {
        inf[i] |= len(comps[i]) > 1;
        for (auto v : comps[i])
            inf[i] |= bad[v];
    }

    vector<set<int>> dug(current);
    for (int i = 0; i < n; i++)
        for (auto j : g[i])
            if (who[i] != who[j])
                dug[who[i]].insert(who[j]);

    used.assign(current, 0);
    y_combinator([&](auto dfs, int v) -> void {
        used[v] = 1;
        for (auto u : dug[v])
            if (!used[u])
                dfs(u);
    })(who[0]);

    vector<int> in(current);
    for (int i = 0; i < current; i++)
        if (used[i])
            for (auto j : dug[i])
                in[j]++;

    assert(in[who[0]] == 0);
    vector<int> que{who[0]};
    que.reserve(current);

    vector<int> answer(current);
    answer[who[0]] = 1;
    for (int st = 0; st < len(que); st++) {
        int v = que[st];
        if (inf[v])
            answer[v] = -1;

        for (auto u : dug[v]) {
            if (answer[u] == 0)
                answer[u] = answer[v];
            else if (answer[u] == 1)
                answer[u] = (answer[v] == -1 ? -1 : 2);
            else if (answer[u] == 2 && answer[v] == -1)
                answer[u] = -1;

            in[u]--;
            if (!in[u])
                que.push_back(u);
        }
    }

    for (int i = 0; i < n; i++)
        cout << answer[who[i]] << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
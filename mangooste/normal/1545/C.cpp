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

constexpr int MOD = 998'244'353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> perms(2 * n, vector<int>(n));
    for (auto &perm : perms)
        for (auto &x : perm)
            cin >> x, x--;

    vector<char> used(2 * n);
    vector<vector<int>> freq(n, vector<int>(n));
    for (const auto &perm : perms)
        for (int i = 0; i < n; i++)
            freq[i][perm[i]]++;

    auto find = [&](int col, int x) {
        for (int i = 0; i < 2 * n; i++)
            if (!used[i] && perms[i][col] == x)
                return i;

        return -1;
    };

    vector<int> answer;
    while (true) {
        bool found = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (freq[i][j] == 1) {
                    int who = find(i, j);
                    if (who == -1)
                        continue;

                    found = true;
                    answer.push_back(who);

                    for (int i = 0; i < 2 * n; i++)
                        if (!used[i]) {
                            bool bad = false;
                            for (int j = 0; j < n; j++) 
                                if (perms[i][j] == perms[who][j]) {
                                    bad = true;
                                    break;
                                }

                            if (bad) {
                                used[i] = 1;
                                for (int j = 0; j < n; j++)
                                    freq[j][perms[i][j]]--;
                            }
                        }
                }

        if (!found)
            break;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            assert(freq[i][j] == 0 || freq[i][j] == 2);

    vector<vector<int>> g(2 * n);
    auto add = [&](int v, int u) {
        g[v].push_back(u);
        g[u].push_back(v);
    };

    for (int j = 0; j < n; j++) {
        vector<int> who(n, -1);
        for (int i = 0; i < 2 * n; i++)
            if (!used[i]) {
                if (who[perms[i][j]] == -1)
                    who[perms[i][j]] = i;
                else
                    add(who[perms[i][j]], i);
            }
    }

    int total = 1;
    vector<int> color(2 * n);
    for (int i = 0; i < 2 * n; i++)
        if (!used[i]) {
            y_combinator([&](auto dfs, int v) -> void {
                used[v] = 1;
                if (color[v] == 0)
                    answer.push_back(v);

                for (auto u : g[v])
                    if (!used[u]) {
                        color[u] = color[v] ^ 1;
                        dfs(u);
                    } else {
                        assert(color[u] == (color[v] ^ 1));
                    }
            })(i);

            total <<= 1;
            if (total >= MOD)
                total -= MOD;
        }

    cout << total << '\n';
    assert(len(answer) == n);
    for (auto x : answer)
        cout << x + 1 << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
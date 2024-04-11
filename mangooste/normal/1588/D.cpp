#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n;
    cin >> n;

    constexpr int A = 52;
    vector<array<array<int, 2>, A>> a(n);

    auto to_int = [&](char c) {
        if ('a' <= c && c <= 'z')
            return c - 'a';

        return 26 + c - 'A';
    };

    auto to_char = [&](int id) {
        if (id < 26)
            return 'a' + id;

        return 'A' + id - 26;
    };

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < A; j++)
            a[i][j] = {-1, -1};

        for (int j = 0; j < len(s); j++) {
            int id = to_int(s[j]);
            a[i][id][a[i][id][0] != -1] = j;
        }
    }

    const int MASK = 1 << n;
    array<vector<int>, A> dp;
    dp.fill(vector<int>(MASK, -1));
    array<vector<pair<int, int>>, A> go;
    go.fill(vector<pair<int, int>>(MASK));

    auto solve = y_combinator([&](auto dfs, int c, int mask) -> int {
        if (dp[c][mask] != -1)
            return dp[c][mask];

        dp[c][mask] = 1;
        for (int nxt = 0; nxt < A; nxt++) {
            bool ok = true;
            int new_mask = 0;

            for (int i = 0; i < n; i++) {
                int pos = a[i][c][mask >> i & 1], id = a[i][nxt][0] <= pos;
                if (a[i][nxt][id] <= pos) {
                    ok = false;
                    break;
                }
                new_mask ^= id << i;
            }

            if (ok && dp[c][mask] < dfs(nxt, new_mask) + 1) {
                dp[c][mask] = dfs(nxt, new_mask) + 1;
                go[c][mask] = {nxt, new_mask};
            }
        }

        return dp[c][mask];
    });

    int answer = 0, best_c = -1, best_mask = 0;
    for (int first = 0; first < A; first++) {
        bool ok = true;
        for (int i = 0; i < n; i++)
            ok &= a[i][first][0] != -1;

        if (!ok)
            continue;

        int cur_answer = solve(first, 0);
        if (answer < cur_answer) {
            answer = cur_answer;
            best_c = first;
        }
    }

    cout << answer << '\n';
    string res;
    while (answer--) {
        res.push_back(to_char(best_c));
        tie(best_c, best_mask) = go[best_c][best_mask];
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
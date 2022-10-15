#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        autoint v;
        tree[i].push_back(--v);
        tree[v].push_back(i);
    }
    vector<vector<int>> level(n + 2);
    function<void(int, int, int)> dfs = [&](int cur, int prev, int lvl) {
        level[lvl].push_back(cur);
        auto parent = find(tree[cur].begin(), tree[cur].end(), prev);
        if (parent != tree[cur].end()) tree[cur].erase(parent);
        for (int next : tree[cur]) {
            dfs(next, cur, lvl + 1);
        }
    };
    dfs(0, 0, 0);

    vector<int> numbers(n);
    for (int i = 1; i < n; ++i) cin >> numbers[i];

    vector<int> dp(n);

    for (int lvl = 0; !level[lvl + 1].empty(); ++lvl) {
        int dp_minus_min = -1e18;
        int dp_plus_max = -1e18;
        int mn_lvl = 1e9;
        int mx_lvl = -1e9;

        for (int x : level[lvl]) {
            int mn = *min_element(tree[x].begin(), tree[x].end(), [&](int a, int b) { return numbers[a] < numbers[b]; });
            int mx = *max_element(tree[x].begin(), tree[x].end(), [&](int a, int b) { return numbers[a] < numbers[b]; });
            mn = numbers[mn];
            mx = numbers[mx];

            mn_lvl = min(mn_lvl, mn);
            mx_lvl = max(mx_lvl, mx);
            dp_minus_min = max(dp_minus_min, dp[x] - mn);
            dp_plus_max = max(dp_plus_max, dp[x] + mx);
        }

        for (int x : level[lvl]) {
            for (int y : tree[x]) {
                dp[y] = max({dp[y], dp[x] + numbers[y] - mn_lvl, dp[x] + mx_lvl - numbers[y]});
                dp[y] = max({dp[y], numbers[y] + dp_minus_min, dp_plus_max - numbers[y]});
            }
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
}
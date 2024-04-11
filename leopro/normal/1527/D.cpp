#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#else
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;
    using ull = unsigned long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<S> && !is_same_v<S, char> ? " " : "") << p.second;
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
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
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
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
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

        explicit autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() const { return x; }

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
        autoint u, v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> size(n, 1);
    vector<int> in(n), out(n);
    int t = 0;
    auto dfs = [&](auto dfs, int cur, int prev) -> int {
        in[cur] = ++t;
        for (int next : tree[cur]) {
            if (next == prev) continue;
            size[cur] += dfs(dfs, next, cur);
        }
        out[cur] = ++t;
        return size[cur];
    };
    dfs(dfs, 0, 0);
    auto is_ancestor = [&](int parent, int son) {
        return in[parent] <= in[son] && out[son] <= out[parent];
    };

    vector<ll> ans(n + 1);
    for (int c : tree[0]) {
        ans[0] += size[c] * 1LL * (size[c] - 1) / 2;
    }
    int one = -1;
    for (int i : tree[0]) if (is_ancestor(i, 1)) one = i;
    ans[1] = (n - size[1]) * 1LL * (n - size[1] - 1) / 2;
    for (int c : tree[0]) {
        int fictiveSize = size[c] - (c == one) * size[1];
        ans[1] -= fictiveSize * 1LL * (fictiveSize - 1) / 2;
    }

    int u = 0, v = 1;
    for (int i = 1; i < n; ++i) {
        if (is_ancestor(i, u) || is_ancestor(i, v)) continue;

        int sizeU;
        if (u == 0) {
            sizeU = size[u] - size[one] - (is_ancestor(u, i) && !is_ancestor(one, i)) * size[i];
        } else {
            sizeU = size[u] - is_ancestor(u, i) * size[i];
        }
        int sizeV = size[v] - is_ancestor(v, i) * size[i];
        ans[i] = sizeU * 1LL * sizeV;

        if (u == 0 && is_ancestor(u, i) && !is_ancestor(one, i)) {
            u = i;
        } else if (u != 0 && is_ancestor(u, i)) {
            u = i;
        } else if (is_ancestor(v, i)) {
            v = i;
        } else break;
    }
    ans[n] = n * 1LL * (n - 1) / 2;
    for (int i = 0; i < n; ++i) ans[n] -= ans[i];
    cout << ans << '\n';
}
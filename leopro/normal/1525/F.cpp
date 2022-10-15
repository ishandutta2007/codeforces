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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

vector<vector<int>> remove(vector<vector<int>> castle, int x) {
    if (x == 0) return castle;
    if (x > 0) {
        castle[--x].clear();
        return castle;
    } else {
        x = -(x + 1);
        for (int i = 0; i < castle.size(); ++i) {
            for (int j = 0; j < castle[i].size(); ++j) {
                while (j < castle[i].size() && castle[i][j] == x) castle[i].erase(castle[i].begin() + j);
            }
        }
        return castle;
    }
}

int force(const vector<vector<int>> &castle) {
    vector<int> pair(castle.size(), -1), used(castle.size(), -1);

    for (int i = 0; i < castle.size(); ++i) {
        auto go = [&](auto go, int cur) -> bool {
            if (used[cur] == i) return false;
            used[cur] = i;
            for (int next : castle[cur]) {
                if (pair[next] == -1) {
                    pair[next] = cur;
                    return true;
                }
            }
            for (int next : castle[cur]) {
                if (go(go, pair[next])) {
                    pair[next] = cur;
                    return true;
                }
            }
            return false;
        };
        go(go, i);
    }
    return count(pair.begin(), pair.end(), -1);
}

int sgn(int i) { return i > 0 ? 1 : -1; }

void solve() {
    autoint n, m, k;
    vector<vector<int>> castle(n);
    for (int i = 0; i < m; ++i) {
        autoint u, v;
        --u, --v;
        castle[u].push_back(v);
    }
    vector<pair<int, int>> out(n, {-1, 0});
    int t = 0;
    auto dfs = [&](auto dfs, int cur) -> void {
        if (out[cur].first != -1) return;
        out[cur].first = -2;
        for (int next : castle[cur]) {
            dfs(dfs, next);
        }
        out[cur].first = t++;
    };
    for (int i = 0; i < n; ++i) {
        out[i].second = i;
        if (out[i].first == -1) dfs(dfs, i);
    }
    sort(out.rbegin(), out.rend());
    vector<int> sorted(n), real(n);
    for (int i = 0; i < n; ++i) {
        real[i] = out[i].second;
        sorted[real[i]++] = i;
    }


    vector<vector<int>> c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < castle[i].size(); ++j) {
            c[sorted[i]].push_back(sorted[castle[i][j]]);
        }
        sort(c[sorted[i]].begin(), c[sorted[i]].end());
    }

    int f = force(c);
    int initial = f;
    vector<int> actions;
    while (f <= k) {
        for (int i = -n; i <= n; ++i) {
            if (i == 0) continue;
            auto blocked = remove(c, i);
            if (force(blocked) > force(c)) {
                f = force(blocked);
                c = blocked;
                actions.push_back(i);
                break;
            }
        }
    }

    vector<ll> x(k), y(k);

    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
    }
    // TOO MUCH CODE...




    vector<vector<ll>> maxCost(k + 1, vector<ll>(n, -1e13));
    maxCost[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = max(i + 1 - initial, 0); j <= actions.size(); ++j) {
            for (int prevJ = 0; prevJ <= j; ++prevJ) {
                maxCost[i][j] = max(maxCost[i - 1][prevJ] + max(0ll, x[i - 1] - (j - prevJ) * y[i - 1]), maxCost[i][j]);
            }
        }
    }
    cout << actions.size() + k << '\n';

    auto print = [&]() {
        static auto it = actions.begin();
        cout << sgn(*it) * (real[abs(*it) - 1]) << ' ';
        ++it;
    };

    function<void(int, int)> restore = [&](int i, int j) {
        if (i == 0) return;
        for (int prevJ = 0; prevJ <= j; ++prevJ) {
            if (maxCost[i][j] == maxCost[i - 1][prevJ] + max(0ll, x[i - 1] - (j - prevJ) * y[i - 1])) {
                restore(i - 1, prevJ);
                for (int k = prevJ; k < j; ++k) print();
                cout << "0 ";
                break;
            }
        }
    };
    restore(k, actions.size());
}
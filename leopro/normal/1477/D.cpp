#ifndef ONLINE_JUDGE
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
    do {
        solve();
    } while (--t);
    return 0;
}

struct segment {
    int l, r;

    segment() {}

    segment(int l, int r) : l(l), r(r) {}

    friend istream &operator>>(istream &is, segment &s) {
        is >> s.l >> s.r;
        --s.l, --s.r;
        return is;
    }
};

void solve() {
    autoint n, m;
    vector<segment> sg(m);
    cin >> sg;
    vector<int> deg(n);
    for (auto &s : sg) deg[s.l]++;
    for (auto &s : sg) deg[s.r]++;
    vector<int> mn;
    for (int i = 0; i < n; ++i) if (deg[i] == n - 1) mn.push_back(i);
    if (mn.size() == n) {
        for (int i = 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
        for (int i = 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
        return;
    }
    vector<vector<int>> graph(n);
    for (auto &s : sg) graph[s.l].push_back(s.r);
    for (auto &s : sg) graph[s.r].push_back(s.l);
    for (auto &v : graph) sort(v.begin(), v.end());
    vector<int> absent(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (!binary_search(graph[i].begin(), graph[i].end(), j)) {
                absent[i] = j;
                absent[j] = i;
                break;
            }
        }
    }

    vector<int> g(n, -1);
    vector<set<int>> gr;

    vector<int> parent(n, -1);
    vector<int> d(n, 0);
    for (int i = 0; i < n; ++i) {
        if (deg[i] == n - 1) continue;

        if (parent[i] >= 0) continue;
        int next = absent[i];
        if (parent[next] == -1 || parent[next] == next) {
            if (parent[next] == next) d[next]--;
            parent[i] = parent[next] = next;
            d[next] += 2;
        } else {
            if (parent[parent[next]] == parent[next] && d[parent[next]] == 2) {
                d[parent[parent[next]]]--;
                parent[parent[next]] = next;
                d[next]++;
                d[parent[next]]--;
                parent[next] = next;
                d[next]++;
                parent[i] = next;
                d[next]++;
            } else {
                {
                    d[parent[next]]--;
                    parent[i] = parent[next] = next;
                    d[next] += 2;
                }
            }
        }
    }

    set<int> parents;
    for (int x : parent) if (x != -1) parents.insert(x);
    vector<vector<int>> children(n);
    for (int i = 0; i < n; ++i) if (parent[i] != -1 && parent[i] != i) children[parent[i]].push_back(i);

    auto inverse = [&](vector<int> p) {
        vector<int> q(p.size());
        for (int i = 0; i < p.size(); ++i) q[p[i]] = i + 1;
        return q;
    };
    vector<int> p;
    for (int i : mn) p.push_back(i);
    for (int x : parents) {
        p.push_back(x);
        for (int c : children[x]) p.push_back(c);
    }
    cout << inverse(p);
    vector<int> q;
    for (int i : mn) q.push_back(i);
    for (int x : parents) {
        for (int c : children[x]) q.push_back(c);
        q.push_back(x);
    }
    cout << inverse(q);
}
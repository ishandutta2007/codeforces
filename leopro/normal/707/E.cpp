// #ifndef ONLINE_JUDGE
// #define _GLIBCXX_DEBUG
// #endif

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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct wire {
    int i = -1, g = -1;

    wire(int i, int g) : i(i), g(g) {}

    wire() = default;
};

struct cell {
    int i, j;

    friend istream &operator>>(istream &is, cell &c) {
        is >> c.i >> c.j;
        --c.i, --c.j;
        return is;
    }
};

void solve() {
    autoint n, m, k;
    vector<vector<wire>> rows(n, vector<wire>(m + 1));
    vector<vector<wire>> cols(n + 1, vector<wire>(m));
    vector<vector<int>> prefix(k);
    vector<cell> start(k);
    for (int g = 0; g < k; ++g) {
        autoint len;
        prefix[g].assign(len + 1, 0);
        cin >> start[g] >> prefix[g][1];
        cell prev = start[g];
        for (int i = 1; i < len; ++i) {
            cell cur;
            cin >> cur >> prefix[g][i + 1];
            prefix[g][i + 1] += prefix[g][i];
            if (prev.i == cur.i) rows[cur.i][max(prev.j, cur.j)] = {i, g};
            if (prev.j == cur.j) cols[max(cur.i, prev.i)][cur.j] = {i, g};
            prev = cur;
        }
    }
    vector<bool> on(k, true);
    autoint q;
    for (int t = 0; t < q; ++t) {
        string s;
        cin >> s;
        if (s.size() == 6) {
            autoint i;
            --i;
            on[i] = !on[i];
        } else {
            cell a, b;
            cin >> a >> b;
            vector<vector<int>> cut(k);
            for (int i = a.i; i <= b.i; ++i) {
                if (rows[i][a.j].g >= 0) cut[rows[i][a.j].g].push_back(rows[i][a.j].i);
                if (rows[i][b.j + 1].g >= 0) cut[rows[i][b.j + 1].g].push_back(rows[i][b.j + 1].i);
            }
            for (int j = a.j; j <= b.j; ++j) {
                if (cols[a.i][j].g >= 0) cut[cols[a.i][j].g].push_back(cols[a.i][j].i);
                if (cols[b.i + 1][j].g >= 0) cut[cols[b.i + 1][j].g].push_back(cols[b.i + 1][j].i);
            }
            int ans = 0;
            for (int g = 0; g < k; ++g) {
                if (!on[g]) continue;
                auto begin = start[g];
                if (a.i <= begin.i && begin.i <= b.i && a.j <= begin.j && begin.j <= b.j) cut[g].push_back(0);
                if (cut[g].size() & 1) cut[g].push_back(prefix[g].size() - 1);
                sort(cut[g].begin(), cut[g].end());
                for (int i = 1; i < cut[g].size(); i += 2) ans += prefix[g][cut[g][i]] - prefix[g][cut[g][i - 1]];
            }
            cout << ans << '\n';
        }
    }
}
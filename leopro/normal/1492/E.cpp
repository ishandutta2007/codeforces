#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<F> || is_integral_v<S> ? " " : "") << p.second << "\n";
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
        for (const T &t : v) os << t << (is_integral_v<T> ? " " : "");
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
        for (const T &t : v) os << t << (is_integral_v<T> ? " " : "");
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

vector<int> majority;
vector<vector<int>> other;

void check_time_limit() {
    static int times = 0;
    times++;
    if ((times & 1023) == 0) {
        if (clock() * 1.0 / CLOCKS_PER_SEC > 1.9) answer("No");
    }
}

void return_if_ok(const vector<vector<int>> &s, const vector<int> &choice, const vector<int> &cur) {
    vector<int> diff(s.size());
    for (int p = 0; p < choice.size(); ++p) {
        if (majority[choice[p]] == cur[p]) {
            for (int i : other[choice[p]]) {
                diff[i]++;
                if (diff[i] > 2) return;
            }
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i][choice[p]] != cur[p]) diff[i]++;
                if (diff[i] > 2) return;
            }
        }
    }
    vector<int> ans = s[0];
    for (int p = 0; p < choice.size(); ++p) {
        ans[choice[p]] = cur[p];
    }
    cout << "Yes\n";
    answer(ans);
}

void go(const vector<vector<int>> &s, const vector<int> &choice, const vector<vector<pair<int, int>>> &cnt,
        vector<int> &suf_min, vector<int> cur, int score) {
    check_time_limit();
    int i = cur.size();
    if (i == choice.size()) {
        return_if_ok(s, choice, cur);
        return;
    }
    if (score + suf_min[i] > 2 * s.size()) return;
    for (auto x : cnt[choice[i]]) {
        cur.push_back(x.second);
        score += x.first;
        go(s, choice, cnt, suf_min, cur, score);
        cur.pop_back();
        score -= x.first;
    }
}

void solve() {
    autoint n, m;
    majority.resize(m);
    other.assign(m, vector<int>());
    vector<vector<int>> s(n, vector<int>(m));
    cin >> s;
    vector<map<int, int>> count(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            count[j][s[i][j]]++;
        }
    }

    vector<vector<pair<int, int>>> cnt(m);
    vector<int> choice;
    for (int j = 0; j < m; ++j) {
        for (auto entry : count[j]) {
            cnt[j].emplace_back(n - entry.second, entry.first);
        }
        sort(cnt[j].begin(), cnt[j].end());
        if (cnt[j][0].first) choice.emplace_back(j);
        majority[j] = cnt[j][0].second;
        for (int i = 0; i < n; ++i) if (s[i][j] != majority[j]) other[j].push_back(i);
    }
    vector<pair<int, int>> choice_for_sort(choice.size());
    for (int i = 0; i < choice.size(); ++i) choice_for_sort[i] = {cnt[choice[i]][0].first, choice[i]};
    sort(choice_for_sort.begin(), choice_for_sort.end());
    for (int i = 0; i < choice.size(); ++i) choice[i] = choice_for_sort[i].second;
    vector<int> suf_min(choice.size());
    for (int i = (int) choice.size() - 1; i >= 0; --i) {
        suf_min[i] = cnt[choice[i]][0].first + ((i + 1 == choice.size()) ? 0 : suf_min[i + 1]);
    }
    go(s, choice, cnt, suf_min, {}, 0);
    cout << "No\n";
}
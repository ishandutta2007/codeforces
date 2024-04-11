#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#include <utility>

namespace {
    using namespace std;
//#define int long long
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

void solve() {
    int l, r;
    cin >> l >> r;
    cout << "YES\n";
    if (l == r) {
        cout << "2 1\n";
        cout << "1 2 " << l << '\n';
        return;
    }
    int cnt = __lg(r - l) + 1;
    vector<vector<pair<int, int>>> map(cnt + 2);
    for (int i = cnt + 1; i >= 1; --i) {
        for (int j = i + 1; j < map.size(); ++j) map[i].emplace_back(j + 1, 1 << (cnt - i));
    }
    map.insert(map.begin(), vector<pair<int, int>>());
    int sz = map.size();
    map[0].emplace_back(sz - 1, l);
    int cur = l;
    int sm = 0;
    for (int bit = 0; bit < 30; ++bit){
        if (cur + (1 << bit) <= r){
            map[0].emplace_back(sz - bit - 2, cur - (1 << bit) + 1);
            cur += (1 << bit);
        }
    }
    auto answer = [&](){
        int m = 0;
        for (int i = 0; i < map.size(); ++i){
            m += map[i].size();
        }
        cout << map.size() << ' ' << m << '\n';

        for (int i = 0; i < map.size(); ++i){
            for (int j = 0; j < map[i].size(); ++j){
                cout << i + 1 << ' ' << map[i][j].first + 1 << ' ' << map[i][j].second << '\n';
            }
        }
    };
    map[0].emplace_back(1, 1);
    if (cur == r) return answer();

    int rem = r - cur;
    for (int bit = 20; bit >= 0; --bit){
        if (rem & (1 << bit)){
            map[1].emplace_back(sz - bit - 2, cur - (1 << bit));
            cur += (1 << bit);
        }
    }
    return answer();
}
#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
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

using card = pair<int, int>;
vector<int> p;

card remove(set<card> &s, const set<card>::iterator& it){
    card x = *it;
    s.erase(it);
    s.erase({p[x.first], x.second});
    return x;
}
card remove(set<card> &s, const set<card>::reverse_iterator& it){
    card x = *it;
    s.erase(--s.end());
    s.erase({p[x.first], x.second});
    return x;
}
void solve() {
    autoint n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < n; ++i) --a[i];
    for (int i = 0; i < n; ++i) --b[i];
    set<card> cards;
    for (int i = 0; i < n; ++i) {
        cards.emplace(a[i], i);
        cards.emplace(b[i], i);
    }
    p.assign(2 * n, 0);
    for (int i = 0; i < n; ++i) {
        p[a[i]] = b[i];
        p[b[i]] = a[i];
    }
    int ans = 0;
    int right_min = -1;
    int right_max = 2 * n;
    vector<bool> isa(2 * n);
    for (int x : a) isa[x] = true;
    while (!cards.empty()) {
        int left_min = remove(cards, cards.begin()).first;
        int left_max = p[left_min];
        int reversed = !isa[left_min], total = 1;
        while (!cards.empty() && (cards.begin()->first < max(left_min, right_min) || cards.rbegin()->first > min(left_max, right_max))) {
            total++;
            if (cards.begin()->first < left_min) {
                auto[c, idx] = remove(cards, cards.begin());
                if (c < right_min || p[c] > right_max) answer(-1);
                reversed += c == a[idx];
                right_max = p[c];
                right_min = c;
            } else if (cards.begin()->first < right_min) {
                auto[c, idx] = remove(cards, cards.begin());
                if (c < left_min || p[c] > left_max) answer(-1);
                reversed += c == b[idx];
                left_max = p[c];
                left_min = c;
            } else if (cards.rbegin()->first > left_max) {
                auto[c, idx] = remove(cards, cards.rbegin());
                if (c > right_max || p[c] < right_min) answer(-1);
                reversed += c == b[idx];
                right_min = p[c];
                right_max = c;
            } else if (cards.rbegin()->first > right_max) {
                auto[c, idx] = remove(cards, cards.rbegin());
                if (c > left_max || p[c] < left_min) answer(-1);
                reversed += c == a[idx];
                left_max = c;
                left_min = p[c];
            }
        }
        ans += min(reversed, total - reversed);
        if (left_max < right_min || right_max < left_min) answer(-1);
    }

    cout << ans << '\n';
}
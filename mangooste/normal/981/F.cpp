#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename T, typename merge_t>
struct functional_stack {
    std::vector<std::pair<T, T>> st;
    const merge_t merge;

    functional_stack(const merge_t &merge) : merge(merge) {}

    void reserve(size_t n) {
        st.reserve(n);
    }

    int size() const {
        return st.size();
    }

    bool empty() const {
        return st.empty();
    }

    void push(T x) {
        st.emplace_back(x, st.empty() ? x : merge(st.back().second, x));
    }

    void pop() {
        assert(!st.empty());
        st.pop_back();
    }

    T query() const {
        return st.back().second;
    }

    void reverse() {
        std::reverse(st.begin(), st.end());
        for (int i = 0; i < int(st.size()); i++)
            st[i].second = i == 0 ? st[i].first : merge(st[i - 1].second, st[i].first);
    }
};

template<typename T, typename merge_t>
struct functional_queue {
    functional_stack<T, merge_t> front_stack, back_stack;
    const merge_t merge;

    functional_queue(const merge_t &merge) : front_stack(merge), back_stack(merge), merge(merge) {}

    int size() const {
        return front_stack.size() + back_stack.size();
    }

    bool empty() const {
        return front_stack.empty() && back_stack.empty();
    }

    void push(T x) {
        back_stack.push(x);
    }

    void pop() {
        assert(!empty());
        if (front_stack.empty()) {
            std::swap(front_stack.st, back_stack.st);
            front_stack.reverse();
        }
        assert(!front_stack.empty());
        front_stack.pop();
    }

    T query() const {
        assert(!empty());
        if (back_stack.empty())
            return front_stack.query();

        if (front_stack.empty())
            return back_stack.query();

        return merge(front_stack.query(), back_stack.query());
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, length;
    cin >> n >> length;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a));
    sort(all(b));

    auto check = [&](int dist) {
        auto compress = [&](const vector<pair<int, int>> &segs) {
            struct event {
                int type, x;

                bool operator<(const event &e) const {
                    return x == e.x ? type < e.type : x < e.x;
                }
            };

            static vector<event> events;
            events.clear();
            for (auto &[l, r] : segs) {
                events.push_back({0, l});
                events.push_back({1, r});
            }
            sort(all(events));

            vector<pair<int, int>> new_segs;
            int balance = 0, from = -1;
            for (int i = 0; i < len(events); i++) {
                balance += events[i].type == 0 ? 1 : -1;
                assert(balance >= 0);
                if (balance == 1 && from == -1) {
                    from = events[i].x;
                } else if (balance == 0) {
                    assert(from != -1);
                    if (from != events[i].x) {
                        new_segs.emplace_back(from, events[i].x);
                    }
                    from = -1;
                }
            }
            return new_segs;
        };

        vector<vector<pair<int, int>>> segs(2 * n);
        vector<pair<int, int>> cur_segs;
        for (int i = 0; i < n; i++) {
            if (b[i] - dist <= 0) {
                int first = upper_bound(all(a), b[i]) - a.begin();
                int last = lower_bound(all(a), length - (dist - b[i])) - a.begin();
                cur_segs.emplace_back(0, first);
                cur_segs.emplace_back(last, n);
            } else {
                int first = lower_bound(all(a), b[i] - dist) - a.begin();
                int last = upper_bound(all(a), b[i]) - a.begin();
                cur_segs.emplace_back(first, last);
            }

            if (b[i] + dist >= length) {
                int first = lower_bound(all(a), b[i]) - a.begin();
                int last = upper_bound(all(a), b[i] + dist - length) - a.begin();
                cur_segs.emplace_back(first, n);
                cur_segs.emplace_back(0, last);
            } else {
                int first = lower_bound(all(a), b[i]) - a.begin();
                int last = upper_bound(all(a), b[i] + dist) - a.begin();
                cur_segs.emplace_back(first, last);
            }

            segs[i] = segs[i + n] = compress(cur_segs);
            cur_segs.clear();
        }

        vector<int> delta(2 * n), pref(2 * n);
        for (int i = 1; i < 2 * n; i++) {
            for (auto &[l1, r1] : segs[i]) {
                delta[i] += r1 - l1;
                for (auto &[l2, r2] : segs[i - 1]) {
                    delta[i] -= max(0, min(r1, r2) - max(l1, l2));
                }
            }
            pref[i] = pref[i - 1] + delta[i];
        }

        auto merge = [&](int a, int b) {
            return a < b ? a : b;
        };
        functional_queue<int, decltype(merge)> que(merge);
        for (int i = 0; i < n - 1; i++) {
            que.push(pref[i] - i);
        }

        for (int i = 0; i < 2 * n; i++) {
            int have = 0;
            for (auto &[l, r] : segs[i]) have += r - l;
            if (have == 0) return false;

            // for (int j = i + 1; j < min(2 * n, i + n); j++) {
            //     if (pref[j] - pref[i] + have < j - i + 1) {
            //         return false;
            //     }
            // }
            if (i == 2 * n - 1 || n == 1) continue;
            que.pop();
            if (i + n - 1 < 2 * n) que.push(pref[i + n - 1] - (i + n - 1));
            if (que.query() < pref[i] - i - have + 1) {
                return false;
            }
        }
        return true;
    };

    int l = -1, r = length;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (check(mid) ? r : l) = mid;
    }
    cout << r << '\n';
}
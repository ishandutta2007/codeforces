#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T, typename merge_t = std::function<T(const T&, const T&)>>
struct functional_stack {
    std::vector<std::pair<T, T>> st;
    const merge_t merge;

    functional_stack(const merge_t &merge) : merge(merge) {}

    void reserve(size_t n) {
        st.reserve(n);
    }

    size_t size() const {
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

template<typename T, typename merge_t = std::function<T(const T&, const T&)>>
struct functional_queue {
    functional_stack<T, merge_t> front_stack;
    functional_stack<T, merge_t> back_stack;
    const merge_t merge;

    functional_queue(const merge_t &merge) : front_stack(merge), back_stack(merge), merge(merge) {}

    size_t size() const {
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
            static_assert(is_same<decltype(front_stack), decltype(back_stack)>::value);
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> dp(m, LLONG_MIN);

    for (int it = 0; it < n; it++) {
        vector<int> pref(m + 1);
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            pref[i] = pref[i - 1] + x;
        }

        if (it == 0) {
            for (int i = 0; i + k <= m; i++)
                dp[i] = pref[i + k] - pref[i];

            dbg(dp);
            continue;
        }

        vector<ll> suf_max(m + 1, LLONG_MIN);
        for (int i = m - k; i >= 0; i--)
            suf_max[i] = max(suf_max[i + 1], dp[i] + pref[i + k] - pref[i]);

        functional_queue<ll> que1([](const ll &x, const ll &y) { return max(x, y); });
        que1.push(dp[0] - pref[0]);

        functional_queue<ll> que2([](const ll &x, const ll &y) { return max(x, y); });
        for (int i = 1; i < k && i + k <= m; i++)
            que2.push(dp[i] + pref[i + k]);


        vector<ll> ndp(m, LLONG_MIN);
        ll pref_max = LLONG_MIN;
        for (int i = 0; i + k <= m; i++) {
            if (i - k >= 0)
                pref_max = max(pref_max, dp[i - k] + pref[i] - pref[i - k]);

            ndp[i] = max({que1.size() ? que1.query() + pref[i] : LLONG_MIN, que2.size() ? que2.query() - pref[i + k] : LLONG_MIN,
                pref_max, suf_max[i + k]}) + pref[i + k] - pref[i];

            if (i + k != m)
                que1.push(dp[i + 1] - pref[i + 1]);

            if (i - k + 1 >= 0)
                que1.pop();

            if (i + (k << 1) <= m)
                que2.push(dp[i + k] + pref[i + (k << 1)]);

            if (i + k != m)
                que2.pop();
        }
        dp = ndp;
        dbg(dp);
    }
    cout << *max_element(all(dp)) << '\n';
}
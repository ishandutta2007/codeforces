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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct segment_tree {
    int sz;
    vector<ull> sum, rise, fall;
    vector<ull> numbers;
    vector<int> on;

    explicit segment_tree(const vector<ull> &num) : sz(2 << __lg(num.size())), sum(2 * sz), rise(2 * sz), fall(2 * sz), on(2 * sz), numbers(num) {}

    void insert(ull x) {
        int i = lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();
        on[i + sz] = 1;
        sum[i + sz] = numbers[i];
        i = (i + sz) / 2;
        while (i > 0) {
            update(i);
            i /= 2;
        }
    }

    void erase(ull x) {
        int i = lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();
        on[i + sz] = 0;
        sum[i + sz] = 0;
        i = (i + sz) / 2;
        while (i > 0) {
            update(i);
            i /= 2;
        }
    }

    void normalize(int &i) {
        if (i == get_on()) {
            i = sz;
            return;
        }
        int j = 1;
        while (j < sz) {
            if (on[2 * j] <= i) {
                i -= on[2 * j];
                j = 2 * j + 1;
            } else {
                j = 2 * j;
            }
        }
        i = j - sz;
    }

    void update(int i) {
        sum[i] = sum[2 * i + 1] + sum[2 * i];
        on[i] = on[2 * i] + on[2 * i + 1];
        rise[i] = rise[2 * i] + rise[2 * i + 1] + on[2 * i] * sum[2 * i + 1];
        fall[i] = fall[2 * i] + fall[2 * i + 1] + on[2 * i + 1] * sum[2 * i];
    }

    ull get_sum(int l, int r) {
        normalize(l), normalize(r);
        ull ans = 0;
        for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
            if (l & 1) ans += sum[l++];
            if (r & 1) ans += sum[--r];
        }
        return ans;
    }

    int get_on() {
        int ans = 0;
        for (int l = sz, r = 2 * sz; l < r; l /= 2, r /= 2) {
            if (l & 1) ans += on[l++];
            if (r & 1) ans += on[--r];
        }
        return ans;
    }

    ull get_rise(int l, int r) {
        normalize(l), normalize(r);
        ull ansL = 0, ansR = 0, sumR = 0, sumL = 0;
        int onL = 0, onR = 0;
        for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ansL += rise[l] + onL * sum[l];
                onL += on[l];
                sumL += sum[l];
                l++;
            }
            if (r & 1) {
                --r;
                ansR += rise[r] + on[r] * sumR;
                onR += on[r];
                sumR += sum[r];
            }
        }
        return ansL + ansR + onL * sumR;
    }

    ull get_fall(int l, int r) {
        normalize(l), normalize(r);
        ull ansL = 0, ansR = 0, sumR = 0, sumL = 0;
        int onL = 0, onR = 0;
        for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ansL += fall[l] + on[l] * sumL;
                onL += on[l];
                sumL += sum[l];
                l++;
            }
            if (r & 1) {
                --r;
                ansR += fall[r] + onR * sum[r];
                onR += on[r];
                sumR += sum[r];
            }
        }
        return ansL + ansR + onR * sumL;
    }

    ull get_ans() {
        // ans = get-sum(root) - U [sum[n - i + 1; n); sum[0; i) )
        int n = get_on();
        if (n <= 1) return 0;
        if (get_sum(n - (n + 1) / 2 + 1, n) <= get_sum(0, (n + 1) / 2)) return get_rise(0, n) - get_fall(0, n);
        //get_sum(n - n / 2 + 1, n) > get_sum(0, n / 2)
        int l1 = 0, r1 = (n + 1) / 2;
        while (r1 - l1 > 1) {
            int m = (l1 + r1) / 2;
            if (get_sum(n - m + 1, n) > get_sum(0, m)) r1 = m; else l1 = m;
        }
        ull tans = get_fall(0, l1) + get_sum(0, l1) - get_rise(n - l1 + 1, n) - get_sum(n - l1 + 1, n);
        return get_sum(0, sz) - 2 * tans;
    }
};

void solve() {
    autoint n, q;
    vector<ull> s(n);
    cin >> s;
    vector<pair<int, ull>> queries(q);
    cin >> queries;
    vector<ull> numbers = s;
    for (auto[t, x] : queries) numbers.push_back(x);
    sort(numbers.begin(), numbers.end());
    numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());
    segment_tree t(numbers);
    for (ull x : s) t.insert(x);
    cout << t.get_ans() << '\n';
    for (int w = 0; w < queries.size(); ++w) {
        auto[x, a]=queries[w];
        if (x == 1) t.insert(a); else t.erase(a);
        cout << t.get_ans() << '\n';
    }
}
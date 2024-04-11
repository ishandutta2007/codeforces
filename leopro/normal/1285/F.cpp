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

vector<int> getDivisors(int x) {
    vector<int> res{1};
    for (int d = 1; d * d <= x; ++d) {
        if (x % d == 0 && d < x / d) {
            if (d != 1) res.push_back(d);
            if (d * d == x) break;
            res.push_back(x / d);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int calculateMask(int x) {
    int res = 1;
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) res *= d;
        while (x % d == 0) x /= d;
    }
    return x * res;
}

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    int mx = *max_element(a.begin(), a.end());
    vector<int> mask(mx + 1);
    for (int i = 0; i <= mx; ++i) mask[i] = calculateMask(i);
    vector<vector<int>> divisors(mx + 1);
    for (int i = 0; i <= mx; ++i) divisors[i] = getDivisors(i);
    vector<bool> primesCountParity(divisors.size());
    for (int i = 2; i < divisors.size(); ++i) {
        primesCountParity[i] = !primesCountParity[i / divisors[i][1]];
    }
    int maxMask = *max_element(mask.begin(), mask.end());
    vector<int> maxValue(maxMask + 1);
    for (int x : a) {
        for (int d : divisors[x]) {
            maxValue[mask[d]] = max(maxValue[mask[d]], d);
        }
    }
    vector<pair<int, int>> maskByValue(maxValue.size());
    for (int i = 0; i < maxValue.size(); ++i) maskByValue[i] = {i, maxValue[i]};
    sort(maskByValue.begin(), maskByValue.end(), [](auto p, auto q) { return p.second < q.second; });
    vector<int> total(maxValue.size());
    for (auto[mask, value] : maskByValue) {
        if (value == 0) continue;
        for (int subMask : divisors[mask]) total[subMask]++;
    }
    vector<vector<pair<int, int>>> count(maxValue.size());
    for (int i = 0; i < count.size(); ++i) count[i].emplace_back(0, total[i]);
    for (auto[mask, value] : maskByValue) {
        if (value == 0) continue;
        for (auto subMask : divisors[mask]) {
            count[subMask].emplace_back(value, count[subMask].back().second - 1);
        }
    }

    auto countInclusionExclusion = [&](int mask, int bound) {
        int cnt = 0;
        for (auto subMask : divisors[mask]) {
            auto it = --upper_bound(count[subMask].begin(), count[subMask].end(), pair{bound, 1000'000});
            cnt += primesCountParity[subMask] ? -it->second : it->second;
        }
        return cnt;
    };

    ll ans = 0;
    for (auto[mask, value] : maskByValue) {
        if (value == 0) continue;
        int l = 0;
        int r = divisors.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (countInclusionExclusion(mask, m) > 0) l = m; else r = m;
        }
        ans = max(ans, value * 1LL * r);
    }
    cout << ans;
}
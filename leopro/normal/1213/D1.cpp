#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

namespace {
    using namespace std;
    typedef long long ll;

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    bool space(vector<T>) { return false; }

    template<typename T>
    bool space(T) { return true; }

    bool space(char) { return false; }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) { os << t << (space(t) ? " " : ""); }
        os << "\n";
        return os;
    }

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }

    template<typename T>
    void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }

    template<typename value_type, typename sum_type>
    sum_type sum(const vector<value_type> &v) {
        ll s = 0;
        for (value_type value : v) s += value;
        return s;
    }
}

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    /*int t;
    cin >> t;
    for (int i = 0; i < t; ++i) */solve();
}

void solve() {
    int k, n;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(1));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
        int prev = a[i][0];
        while ((prev >> 1) != prev) a[i].push_back(prev >>= 1);
    }
    vector<multiset<int>> count(200001);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            count[a[i][j]].insert(j);
        }
    }
    vector<int> cnt(200001, 1000000000);
    for (int i = 0; i < 200001; ++i) {
        if (count[i].size() < k) continue;
        int sum = 0;
        auto x = count[i].begin();
        for (int j = 0; j < k; ++j, ++x) {
            sum += *x;
        }
        cnt[i] = sum;
    }
    int ans = 1000000000;
    for (int v : cnt) {
        ans = min(ans, v);
    }
    cout << ans;
}
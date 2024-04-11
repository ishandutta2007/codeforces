#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

template<class T, bool max_mode = false>
class sparse_table {
public:
    int n, log;
    vector<T> values;
    vector<vector<T>> sparse;
    vector<int> bit_precalc;

private:
    int better_index(int i, int j) {
        // if (max_mode)                                //
        //     return (values[i] >= values[j]) ? i : j; // if you want to get minimum index in function "best_index"
        // return (values[i] <= values[j]) ? i : j;     //
        if (max_mode)
            return (values[i] > values[j]) ? i : j;
        return (values[i] < values[j]) ? i : j;
    }

public:
    sparse_table() : n(0), log(0) {}

    void clear() {
        n = log = 0;
        values.clear();
        sparse.clear();
        bit_precalc.clear();
    }

    void build(vector<T> values_) {
        values = values_;
        n = values.size();
        bit_precalc.resize(n);
        bit_precalc[0] = 0;
        for (int i = 1; i < n; i++)
            bit_precalc[i] = bit_precalc[i - 1] + ((1 << bit_precalc[i - 1] + 1) <= i + 1);
        log = bit_precalc[n - 1] + 1;
        sparse.resize(n, vector<T>(log));
        for (int i = 0; i < n; i++)
            sparse[i][0] = i;
        for (int bit = 1; bit < log; bit++)
            for (int i = 0; i + (1 << bit) <= n; i++) 
                sparse[i][bit] = better_index(sparse[i][bit - 1], sparse[i + (1 << bit - 1)][bit - 1]);
    }

    // the maximum index of min/max element in [L, R]
    int best_index(int L, int R) {
        int cur_bit = bit_precalc[R - L];
        return better_index(sparse[L][cur_bit], sparse[R - (1 << cur_bit) + 1 ][cur_bit]);
    }

    // the min/max element in [L, R]
    T best_value(int L, int R) {
        return values[best_index(L, R)];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &el : a)
        cin >> el;
    if (n / k > x)
        return cout << "-1\n", 0;
    vector<ll> for_bld(n, -1e17);
    for (int i = 0; i < k; i++)
        for_bld[i] = a[i];
    sparse_table<ll, true> sp;
    sp.build(for_bld);
    for (int j = 1; j < x; j++) {
        for_bld = vector<ll>(n, -1e17);
        for (int i = j; i < n; i++)
            for_bld[i] = a[i] + sp.best_value(max(0, i - k), i - 1);
        sp.clear();
        sp.build(for_bld);
    }
    cout << sp.best_value(n - k, n - 1) << '\n';
}
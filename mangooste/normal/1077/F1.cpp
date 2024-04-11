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

struct seg_tree {
    vector<ll> tree;

    seg_tree() {
        tree.resize(0);
    }

    void upd(int v, int vl, int vr, int pos, ll val) {
        if (pos < vl || vr <= pos)
            return;
        if (vr - vl == 1) {
            tree[v] = val;
            return;
        }
        int vm = (vl + vr) / 2;
        upd(2 * v, vl, vm, pos, val);
        upd(2 * v + 1, vm, vr, pos, val);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    ll get(int v, int vl, int vr, int L, int R) {
        if (R <= vl || vr <= L)
            return -1e17;
        if (L <= vl && vr <= R)
            return tree[v];
        int vm = (vl + vr) / 2;
        return max(get(2 * v, vl, vm, L, R), get(2 * v + 1, vm, vr, L, R));
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
    vector<vector<ll>> dp(n, vector<ll>(x, -1e17));
    vector<seg_tree> trees(x);
    for (int i = 0; i < x; i++)
        trees[i].tree.resize(4 * n, -1e17);
    for (int i = 0; i < n; i++) {
        if (i < k) {
            dp[i][0] = a[i];
            trees[0].upd(1, 0, n, i, a[i]);
        }
        for (int j = 1; j < x; j++) {
            dp[i][j] = a[i] + trees[j - 1].get(1, 0, n, max(0, i - k), i);
            trees[j].upd(1, 0, n, i, dp[i][j]);
        }
    }
    ll ans = dp[n - 1][x - 1];
    for (int i = n - 2; i >= n - k; i--)
        ans = max(ans, dp[i][x - 1]);
    cout << ans << '\n';
}
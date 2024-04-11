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
    // #define DEBUG

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

    void debug_out() { cerr << '\n'; }
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

vector<int> tree;

void build(int v, int vl, int vr, vector<int> &a) {
    if (vr - vl == 1) {
        tree[v] = a[vl];
        debug(vl, vr, tree[v]);
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v, vl, vm, a);
    build(2 * v + 1, vm, vr, a);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    debug(vl, vr, tree[v]);
}

int tree_get(int v, int vl, int vr, int L, int R, int val) {
    if (R <= vl || vr <= L)
        return -1;
    if (tree[v] > val)
        return -1;
    if (vr - vl == 1)
        return vl;
    int vm = (vl + vr) / 2;
    int right = tree_get(2 * v + 1, vm, vr, L, R, val);
    if (right != -1)
        return right;
    return tree_get(2 * v, vl, vm, L, R, val);
}
 
vector<ll> get(vector<int> a) {
    int n = a.size();
    tree.clear();
    tree.resize(4 * n);
    build(1, 0, n, a);
    vector<ll> ans(n, 0);
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            ans[i] = ans[i - 1] + a[i];
            continue;
        }
        int pos = tree_get(1, 0, n, 0, i, a[i]);
        debug("get", i, a[i], pos);
        ans[i] = (pos == -1 ? 0LL : ans[pos]) + 1LL * (i - pos) * a[i];
    }
    return ans;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<ll> left = get(a);
    reverse(all(a));
    vector<ll> right = get(a);
    reverse(all(right));
    reverse(all(a));
    debug(left);
    debug(right);
    debug(a);
    int pick = 0;
    for (int i = 1; i < n; i++)
        if (left[i] + right[i] - a[i] > left[pick] + right[pick] - a[pick])
            pick = i;
    debug(pick);
    vector<int> ans(n);
    ans[pick] = a[pick];
    for (int i = pick - 1; i >= 0; i--)
        ans[i] = min(a[i], ans[i + 1]);
    for (int i = pick + 1; i < n; i++)
        ans[i] = min(a[i], ans[i - 1]);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
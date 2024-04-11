#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
vector<int> tree;
 
void upd(int v, int vl, int vr, int pos, int del) {
    if (pos < vl || vr <= pos)
        return;
    if (vr - vl == 1) {
        tree[v] += del;
        return;
    }
    int vm = (vl + vr) / 2;
    upd(2 * v, vl, vm, pos, del);
    upd(2 * v + 1, vm, vr, pos, del);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}
 
void upd(int v, int vl, int vr, int k) {
    if (vr - vl == 1) {
        tree[v]--;
        return;
    }
    int vm = (vl + vr) / 2;
    if (tree[2 * v] >= k)
        upd(2 * v, vl, vm, k);
    else
        upd(2 * v + 1, vm, vr, k - tree[2 * v]);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}
 
int get(int v, int vl, int vr) {
    if (vr - vl == 1)
        return vl;
    int vm = (vl + vr) / 2;
    if (tree[2 * v] != 0)
        return get(2 * v, vl, vm);
    else
        return get(2 * v + 1, vm, vr);
}
 
void solve() {
    // cout << fixed << setprecision(10);
    // const ld PI = atan2(0, -1);
    // ll n;
    // cin >> n;
    // ld ans = 0.0;
    // ld alp = 180 - 360.0 / (2.0 * n);
    // alp /= 2.0;
    // // cout << "alp = " << alp << '\n';
    // ld ln = 1.0;
    // ld R = ln / (2.0 * cos(alp * PI / 180.0));
    // ans = 2.0 * R;
    // cout << fixed << setprecision(10) << ans << '\n';
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &el : a)
        cin >> el, el--;
    vector<int> k(q);
    int sz = n;
    for (int &el : k) {
        cin >> el;
        if (el > 0)
            sz++, el--;
        else
            sz--;
    }
    if (sz == 0) {
        cout << "0\n";
        return;
    }
    tree.resize(4 * n, 0);
    for (auto el : a)
        upd(1, 0, n, el, 1);
    for (int i = 0; i < q; i++) {
        if (k[i] >= 0)
            upd(1, 0, n, k[i], 1);
        else
            upd(1, 0, n, abs(k[i]));
    }
    cout << get(1, 0, n) + 1 << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
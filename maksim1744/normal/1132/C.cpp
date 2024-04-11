/*
    26.03.2019 20:34:20
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

#define int long long

// struct item {
//     int value = 0;
//     int l = 0;
//     int r = 0;
//     int mod_sm = 0;  // modify sum, not sum on [l; r] !!!

//     item() {}
//     item(int value, int l = 0, int r = 0): value(value), l(l), r(r) {}

//     int ask() {
//         return value + mod_sm * (r - l + 1);
//     }
// };

// item operator + (item a, item b) {
//     return item(a.ask() + b.ask(), a.l, b.r);
// }

// struct segtree {
//     vector< item > tree;
//     int n;

//     segtree(int size) : n(size), tree(size * 4, item()) {}
//     template< typename InType >
//     segtree(vector< InType >& v) : n(v.size()), tree(v.size() * 4) {
//         build(v, 0, 0, n - 1);
//     }

//     template< typename InType >
//     void build(vector< InType >& v, int i, int l, int r) {
//         if (l == r) {
//             tree[i] = item(v[l], l, l);
//             return;
//         }
//         int m = (l + r) / 2;
//         build(v, i * 2 + 1, l, m);
//         build(v, i * 2 + 2, m + 1, r);
//         tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
//     }

//     template< typename InType >
//     void set(int ind, InType k, int i, int vl, int vr) {
//         if (vl == vr) {
//             tree[i].value = k - tree[i].mod_sm;
//             return;
//         }
//         int m = (vl + vr) / 2;
//         if (ind <= m) set(ind, k - tree[i].mod_sm, 2 * i + 1, vl, m);
//         else set(ind, k - tree[i].mod_sm, 2 * i + 2, m + 1, vr);
//         tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
//     }

//     template< typename InType >
//     void set(int ind, InType k) {
//         set(ind, k, 0, 0, n - 1);
//     }

//     template< typename InType >
//     void add(int l, int r, InType k, int i, int vl, int vr) {
//         if (l == vl && r == vr) {
//             tree[i].mod_sm += k;
//             return;
//         }
//         int m = (vl + vr) / 2;
//         if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
//         else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
//         else {
//             add(    l, m, k, 2 * i + 1,    vl,  m);
//             add(m + 1, r, k, 2 * i + 2, m + 1, vr);
//         }
//         tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
//     }

//     template< typename InType >
//     void add(int l, int r, InType k) {
//         add(l, r, k, 0, 0, n - 1);
//     }

//     auto ask(int l, int r, int i, int vl, int vr) {
//         if (l == vl && r == vr) {
//             return tree[i].ask();
//         }
//         int m = (vl + vr) / 2;
//         if (r <= m)
//             return ask(l, r, 2 * i + 1, vl, m) + tree[i].mod_sm * (r - l + 1);
//         if (l > m)
//             return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
//         return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
//     }

//     auto ask(int l, int r) {
//         return ask(l, r, 0, 0, n - 1);
//     }
// };

main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v(q);
    vector<int> cnt(n, 0);
    // segtree t(n);
    for (int i = 0; i < q; ++i) {
        cin >> v[i].first >> v[i].second;
        --v[i].first; --v[i].second;
        // t.add(v[i].first, v[i].second, 1);
        for (int j = v[i].first; j <= v[i].second; ++j)
            ++cnt[j];
    }
    sort(v.begin(), v.end());
    // for (int i = 0; i < n; ++i) {
    //     cnt[i] = t.ask(i, i);
    // }
    int bad = 0;
    show(cnt);
    vector<int> s1(n + 1, 0), s2(n + 1, 0), so(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        s1[i + 1] = s1[i];
        s2[i + 1] = s2[i];
        so[i + 1] = so[i];
        if (cnt[i] == 0) ++bad;
        else if (cnt[i] == 1) s1[i + 1] = s1[i] + 1;
        else if (cnt[i] == 2) s2[i + 1] = s2[i] + 1;
        else so[i + 1] = so[i] + 1;
    }
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        for (int j = i + 1; j < q; ++j) {
            int sm = n - bad - (s1[v[i].second + 1] - s1[v[i].first]) - (s1[v[j].second + 1] - s1[v[j].first]);
            if (v[i].second >= v[j].first)
                sm -= s2[min(v[j].second, v[i].second) + 1] - s2[v[j].first];
            ans = max(ans, sm);
        }
    }
    cout << ans << '\n';
    return 0;
}
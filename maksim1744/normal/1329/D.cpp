/*
    author:  Maksim1744
    created: 03.04.2020 18:36:31
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

struct item {
    int value = 0;
    int l = 0;
    int r = 0;
    int mod_sm = 0;  // modify sum, not sum on [l; r] !!!

    item() {}
    item(int value, int l = 0, int r = 0): value(value), l(l), r(r) {}

    int ask() {
        return value + mod_sm * (r - l + 1);
    }
};

item operator + (item a, item b) {
    return item(a.ask() + b.ask(), a.l, b.r);
}

struct segtree {
    vector<item> tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, item()) {}
    template<typename InType>
    segtree(vector<InType>& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template<typename InType>
    void build(vector<InType>& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item(v[l], l, l);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template<typename InType>
    void set(int ind, InType k, int i, int vl, int vr) {
        if (vl == vr) {
            tree[i].value = k - tree[i].mod_sm;
            return;
        }
        int m = (vl + vr) / 2;
        if (ind <= m) set(ind, k - tree[i].mod_sm, 2 * i + 1, vl, m);
        else set(ind, k - tree[i].mod_sm, 2 * i + 2, m + 1, vr);
        tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
    }

    template<typename InType>
    void set(int ind, InType k) {
        set(ind, k, 0, 0, n - 1);
    }

    template<typename InType>
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].mod_sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            add(    l, m, k, 2 * i + 1,    vl,  m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
    }

    template<typename InType>
    void add(int l, int r, InType k) {
        if (r < l) return;
        add(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].mod_sm * (r - l + 1);
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
        return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string mid;
        int n = s.size();
        segtree tree(n);
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                tree.set(mid.size(), i + 1);
                mid.pb(s[i]);
            }
        }
        if (mid.empty()) {
            cout << 1 << '\n';
            cout << 1 << ' ' << n << '\n';
            continue;
        }
        vector<int> cnt(26);
        for (auto c : mid) {
            cnt[c - 'a']++;
        }
        int mx = 0;
        for (auto k : cnt) {
            mx = max(mx, k);
        }
        int m = mid.size();
        int ans = max(mx, (m + 1) / 2) + 1;
        cout << ans << '\n';
        // vector<pair<int, int>> segs
        vector<bool> u(m, false);
        vector<int> next(m, -1), prev(m, -1);
        for (int i = 0; i < m - 1; ++i) {
            next[i] = i + 1;
            prev[i + 1] = i;
        }
        vector<set<int>> borders(26);
        for (int i = 0; i < m; ++i) {
            if (i != 0 && mid[i] != mid[i - 1])
                borders[mid[i] - 'a'].insert(i);
            if (i + 1 != m && mid[i] != mid[i + 1])
                borders[mid[i] - 'a'].insert(i);
        }
        set<pair<int, char>> scnt;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0)
                scnt.emplace(cnt[i], 'a' + i);
        }
        auto upd_bord = [&](int i) {
            if (i == -1) return;
            bool isb = false;
            if (prev[i] != -1 && mid[prev[i]] != mid[i] || next[i] != -1 && mid[next[i]] != mid[i])
                isb = true;
            if (!isb)
                borders[mid[i] - 'a'].erase(i);
            else
                borders[mid[i] - 'a'].insert(i);
        };
        auto dl = [&](int i) {
            char c = mid[i];
            // show(i, c, scnt);
            scnt.erase(mp(cnt[c - 'a'], c));
            cnt[c - 'a']--;
            if (cnt[c - 'a'] != 0)
                scnt.insert(mp(cnt[c - 'a'], c));
            // show(scnt);
            u[i] = true;
            if (prev[i] != -1) {
                next[prev[i]] = next[i];
            }
            if (next[i] != -1) {
                prev[next[i]] = prev[i];
            }
            borders[mid[i] - 'a'].erase(i);
            upd_bord(prev[i]);
            upd_bord(next[i]);
            prev[i] = -1;
            next[i] = -1;
        };
        // cout << "tree: ";
        // for (int i = 0; i < m; ++i) {
        //     cout << tree.ask(i, i) << ' ';
        // }
        // cout << endl;
        int ln = n;
        while (scnt.size() >= 2) {
            // show(scnt);
            char c1 = (--scnt.end())->second;
            int i1 = *borders[c1 - 'a'].begin();
            char c2;
            int i2;
            if (next[i1] != -1 && mid[next[i1]] != mid[i1]) {
                i2 = next[i1];
                c2 = mid[i2];
            } else {
                i2 = prev[i1];
                c2 = mid[i2];
            }
            // show(i1, i2, mid);
            int l = tree.ask(i1, i1);
            int r = tree.ask(i2, i2);
            if (r < l)
                swap(l, r);
            tree.add(max(i1, i2) + 1, m - 1, -(r - (l + 1) + 1));
            cout << l + 1 << ' ' << r << '\n';
            ln -= r - (l + 1) + 1;
            dl(i1);
            dl(i2);
        }
        for (int i = m - 1; i >= 0; --i) {
            if (!u[i]) {
                int l = tree.ask(i, i);
                cout << l << ' ' << l << '\n';
                --ln;
            }
        }
        cout << 1 << ' ' << ln << '\n';
        // show(mid);
        // show(borders);
    }

    return 0;
}
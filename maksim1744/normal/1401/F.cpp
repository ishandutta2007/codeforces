/*
    author:  Maksim1744
    created: 21.08.2020 18:00:08
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


vector<ll> sums;
vector<bool> swapped;
vector<bool> reversed;
vector<ll> a;
int n;

void build(int i = 0, int l = 0, int r = n - 1) {
    if (l == r) {
        sums[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(i * 2 + 1, l, m);
    build(i * 2 + 2, m + 1, r);
    sums[i] = sums[i * 2 + 1] + sums[i * 2 + 2];
};

ll get_sum(int l, int r, int i = 0, int vl = 0, int vr = n - 1, int lvl = 0) {
    l = max(l, vl); r = min(r, vr);
    if (r < l) return 0;

    show(l, r, i, vl, vr, lvl);

    if (l == vl && r == vr) {
        show(sums[i]);
        return sums[i];
    }
    int m = (vl + vr) / 2;
    int ln = (vr - vl + 1);
    if (!reversed[lvl] && !swapped[lvl]) {
        return get_sum(l, r, i * 2 + 1, vl, m, lvl + 1) + get_sum(l, r, i * 2 + 2, m + 1, vr, lvl + 1);
    } else if (!reversed[lvl] && swapped[lvl]) {
        return get_sum(l - ln / 2, r - ln / 2, i * 2 + 1, vl, m, lvl + 1) +
               get_sum(l + ln / 2, r + ln / 2, i * 2 + 2, m + 1, vr, lvl + 1);
    } else if (reversed[lvl] && !swapped[lvl]) {
        int l0 = (vr - r) + vl;
        int r0 = vr - (l - vl);
        return get_sum(l0, r0, i * 2 + 1, vl, m, lvl + 1) + get_sum(l0, r0, i * 2 + 2, m + 1, vr, lvl + 1);
    } else if (reversed[lvl] && swapped[lvl]) {
        int l0 = (vr - r) + vl;
        int r0 = vr - (l - vl);
        l = l0; r = r0;
        return get_sum(l - ln / 2, r - ln / 2, i * 2 + 1, vl, m, lvl + 1) +
               get_sum(l + ln / 2, r + ln / 2, i * 2 + 2, m + 1, vr, lvl + 1);
    }
};

void set_value(int ind, int k, int l = 0, int r = n - 1, int i = 0, int lvl = 0) {
    if (l == r) {
        sums[i] = k;
        return;
    }
    int m = (l + r) / 2;
    int ln = (r - l + 1);
    if (reversed[lvl]) {
        ind = r - (ind - l);
    }
    if (swapped[lvl]) {
        if (ind <= m) {
            ind += ln / 2;
        } else {
            ind -= ln / 2;
        }
    }
    if (ind <= m) {
        set_value(ind, k, l, m, i * 2 + 1, lvl + 1);
    } else {
        set_value(ind, k, m + 1, r, i * 2 + 2, lvl + 1);
    }
    sums[i] = sums[i * 2 + 1] + sums[i * 2 + 2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int k, q;
    cin >> k >> q;
    n = (1 << k);
    a.resize(n);
    cin >> a;

    sums.assign(n * 2, 0);
    swapped.assign(k, false);
    reversed.assign(k + 1, false);
    build();

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, k;
            cin >> x >> k;
            set_value(x - 1, k);
        } else if (tp == 2) {
            int t;
            cin >> t;
            reversed[k - t] = !reversed[k - t];
        } else if (tp == 3) {
            int t;
            cin >> t;
            swapped[k - 1 - t] = !swapped[k - 1 - t];
        } else if (tp == 4) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << get_sum(l, r) << '\n';
        }
    }

    return 0;
}
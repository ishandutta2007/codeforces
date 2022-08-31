/*
    author:  Maksim1744
    created: 23.04.2022 17:56:10
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;
    int K;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
        K = 0;
        while ((1 << K) <= n)
            ++K;
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }

    // find first i such that sum[0..i] >= x
    int lower_bound(T x) {
        int cur = 0;
        T cur_sum = 0;
        for (int k = K - 1; k >= 0; --k) {
            int ind = cur | ((1 << k) - 1);
            if (ind >= n) continue;
            if (cur_sum + tree[ind] >= x) continue;
            cur_sum += tree[ind];
            cur |= (1 << k);
        }
        return cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    fenwick<int> f0(n), f1(n);
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            if (s[i] == '0') f0.add(i, 1);
            else f1.add(i, 1);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (l == r) {
            cout << 1 << '\n';
            continue;
        }
        int c0 = f0.ask(l, r - 1);
        int c1 = f1.ask(l, r - 1);
        cout << max(c0, c1) + 1 << '\n';
    }

    return 0;
}
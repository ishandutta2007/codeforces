/*
    author:  Maksim1744
    created: 11.04.2021 17:58:13
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

vector<int> p2;

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<int> left;
    vector<int> right;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
        left = right = p;
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        left[v] = min(left[v], left[u]);
        right[v] = max(right[v], right[u]);
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

void test_case(int test) {
    int n;
    ll p;
    cin >> n >> p;
    vector<int> a(n);
    cin >> a;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        b.eb(a[i], i);
    }
    sort(b.begin(), b.end());

    vector<vector<int>> sparse(20, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        sparse[0][i] = a[i];
    }
    for (int i = 1; i < sparse.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + (1 << (i - 1)) >= n) break;
            sparse[i][j] = gcd(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }

    auto getg = [&](int l, int r) {
        int p = p2[r - l + 1];
        return gcd(sparse[p][l], sparse[p][r - (1 << p) + 1]);
    };

    DSU d(n);

    ll ans = 0;
    int comps = n;

    for (auto [x, ind] : b) {
        if (x >= p) break;
        int r = ind;
        while (r < n) {
            r = d.right[d.par(r)];
            ++r;
            if (r >= n) break;
            if (getg(ind, r) != x) break;
            d.un(r, r - 1);
            ans += x;
            --comps;
        }
        int l = ind;
        while (l >= 0) {
            l = d.left[d.par(l)];
            --l;
            if (l < 0) break;
            if (getg(l, ind) != x) break;
            d.un(l, l + 1);
            ans += x;
            --comps;
        }
    }
    ans += (ll)p * (comps - 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    const int N = 2e5 + 20;
    p2.resize(N);
    p2[0] = 0;
    for (int i = 1; i < p2.size(); ++i) {
        p2[i] = __lg(i);
    }

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}
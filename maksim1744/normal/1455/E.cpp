/*
    author:  Maksim1744
    created: 12.01.2022 01:28:29
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = double;

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

namespace simplex {
    //#define ld double

    const ld eps = 1e-9;

    bool eq(ld x, ld y) {
        return abs(x - y) < eps;
    }

    bool ls(ld x, ld y) {
        return x + eps < y;
    }

    vector<ld> simplex(vector<vector<ld> > a) {
        int n = a.size() - 1;
        int m = a[0].size() - 1;
        vector<int> left(n + 1), up(m + 1);
        iota(up.begin(), up.end(), 0);
        iota(left.begin(), left.end(), m);
        auto pivot = [&](int x, int y) {
            swap(left[x], up[y]);
            ld k = a[x][y];
            a[x][y] = 1;
            vector<int> vct;
            for (int j = 0; j <= m; j++) {
                a[x][j] /= k;
                if (!eq(a[x][j], 0)) vct.push_back(j);
            }
            for (int i = 0; i <= n; i++) {
                if (eq(a[i][y], 0) || i == x) continue;
                k = a[i][y];
                a[i][y] = 0;
                for (int j : vct) a[i][j] -= k * a[x][j];
            }
        };
        while (1) {
            int x = -1;
            for (int i = 1; i <= n; i++) if (ls(a[i][0], 0) && (x == -1 || a[i][0] < a[x][0])) x = i;
            if (x == -1) break;
            int y = -1;
            for (int j = 1; j <= m; j++) if (ls(a[x][j], 0) && (y == -1 || a[x][j] < a[x][y])) y = j;
            if (y == -1) assert(0); // infeasible
            pivot(x, y);
        }
        while (1) {
            int y = -1;
            for (int j = 1; j <= m; j++) if (ls(0, a[0][j]) && (y == -1 || a[0][j] > a[0][y])) y = j;
            if (y == -1) break;
            int x = -1;
            for (int i = 1; i <= n; i++) if (ls(0, a[i][y]) && (x == -1 || a[i][0] / a[i][y] < a[x][0] / a[x][y])) x = i;
            if (x == -1) assert(0); // unbounded
            pivot(x, y);
        }
        vector<ld> ans(m + 1);
        for (int i = 1; i <= n; i++) if (left[i] <= m) ans[left[i]] = a[i][0];
        ans[0] = -a[0][0];
        return ans;
    }
    // j=1..m: x[j]>=0
    // i=1..n: sum(j=1..m) A[i][j]*x[j] <= A[i][0]
    // max sum(j=1..m) A[0][j]*x[j]
    // res[0] is answer
    // res[1..m] is certificate
};

void test_case(int test) {
    vector<int> x(4), y(4);
    for (int i = 0; i < 4; ++i) {
        cin >> x[i] >> y[i];
    }
    ll ans = 1e18;
    for (int mx = 0; mx < 16; ++mx) {
        if (__builtin_popcount(mx) != 2) continue;
        for (int my = 0; my < 16; ++my) {
            if (__builtin_popcount(my) != 2) continue;
            if (__builtin_popcount(mx & my) != 1) continue;
            vector<vector<ld>> A;
            // x0, y0, a, u1..4, v1..4
            vector<ld> b;
            auto ad = [&](int msk, const vector<int>& x, int isy) {
                vector<ld> v(11);
                for (int i = 0; i < 4; ++i) {
                    if ((msk >> i) & 1) {
                        v.assign(v.size(), 0);
                        v[isy] = 1; v[isy * 4 + 3 + i] = -1; v[2] = 1; A.pb(v); b.pb(x[i]);
                        v.assign(v.size(), 0);
                        v[isy] = -1; v[isy * 4 + 3 + i] = -1; v[2] = -1; A.pb(v); b.pb(-x[i]);
                    } else {
                        v.assign(v.size(), 0);
                        v[isy] = 1; v[isy * 4 + 3 + i] = -1; A.pb(v); b.pb(x[i]);
                        v.assign(v.size(), 0);
                        v[isy] = -1; v[isy * 4 + 3 + i] = -1; A.pb(v); b.pb(-x[i]);
                    }
                }
            };
            ad(mx, x, 0);
            ad(my, y, 1);
            for (int i = 0; i < A.size(); ++i) {
                A[i].insert(A[i].begin(), b[i]);
            }
            vector<ld> c(11, -1);
            c[0] = c[1] = c[2] = 0;
            c.insert(c.begin(), 0);
            A.insert(A.begin(), c);
            auto res = simplex::simplex(A);
            ans = min(ans, -llround(res[0]));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}
/*
    author:  Maksim1744
    created: 04.06.2021 17:59:04
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> q;
    int n = q + 2;
    vector<ll> a(n);
    vector<ll> c(n);
    cin >> a[0] >> c[0];
    vector<vector<int>> up(20, vector<int>(n, -1));
    vector<int> par(n, -1);

    auto get_first_pos = [&](int v) {
        for (int k = up.size() - 1; k >= 0; --k) {
            if (up[k][v] == -1) continue;
            if (a[up[k][v]] == 0) continue;
            v = up[k][v];
        }
        return v;
    };

    int it = 0;
    while (q--) {
        show(a, c);
        show(par);
        ++it;
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, a0, c0;
            cin >> p >> a0 >> c0;
            par[it] = p;
            a[it] = a0;
            c[it] = c0;
            up[0][it] = p;
            for (int i = 1; i < up.size(); ++i) {
                if (up[i - 1][it] == -1) break;
                up[i][it] = up[i - 1][up[i - 1][it]];
            }
        } else {
            ll v, w;
            cin >> v >> w;
            ll w0 = w;
            ll ans = 0;
            while (w && a[v] != 0) {
                int u = get_first_pos(v);
                assert(a[u] > 0);
                if (a[u] >= w) {
                    a[u] -= w;
                    ans += w * c[u];
                    w = 0;
                } else {
                    ans += (ll)a[u] * c[u];
                    w -= a[u];
                    a[u] = 0;
                }
            }
            cout << w0 - w << ' ' << ans << endl;
        }
    }

    return 0;
}
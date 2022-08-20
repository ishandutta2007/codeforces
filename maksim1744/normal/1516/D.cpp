/*
    author:  Maksim1744
    created: 21.04.2021 16:50:33
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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;

    map<int, int> last;
    vector<int> to(n, n);
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1)
            to[i] = to[i + 1];
        vector<int> d;
        int u = a[i];
        for (int k = 2; k * k <= u; ++k) {
            while (u % k == 0) {
                u /= k;
                d.pb(k);
            }
        }
        if (u != 1) {
            d.pb(u);
        }
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());

        for (int e : d) {
            if (last.count(e)) {
                to[i] = min(to[i], last[e]);
            }
            last[e] = i;
        }
    }

    show(to);

    vector<vector<int>> up(20, vector<int>(n, n));
    up[0] = to;
    for (int i = 1; i < up.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[i - 1][j] != n)
                up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }

    show(up);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        ++r;
        int k = 0;
        for (int i = (int)up.size() - 1; i >= 0; --i) {
            if (up[i][l] < r) {
                l = up[i][l];
                k += (1 << i);
            }
        }
        cout << k + 1 << '\n';
    }

    return 0;
}
/*
    author:  Maksim1744
    created: 05.07.2021 22:54:57
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

    ll a, B, w, x, c;
    cin >> a >> B >> w >> x >> c;

    const int N = 1050;
    vector<vector<pair<ll, ll>>> up(62, vector<pair<ll, ll>>(N * 2));
    for (int b = 0; b < up[0].size(); ++b) {
        if (b >= x) {
            up[0][b] = {b - x, 0};
        } else {
            up[0][b] = {b + w - x, 1};
        }
    }

    for (int i = 1; i < up.size(); ++i) {
        for (int j = 0; j < up[i].size(); ++j) {
            int to = up[i - 1][j].first;
            up[i][j] = mp(up[i - 1][to].first, up[i - 1][to].second + up[i - 1][j].second);
        }
    }

    auto geta = [&](ll steps) {
        ll ans = a;
        ll b = B;
        for (int i = up.size() - 1; i >= 0; --i) {
            if ((steps >> i) & 1) {
                show(i, b, up[i][b]);
                assert(0 <= b && b < up[i].size());
                ans -= up[i][b].second;
                b = up[i][b].first;
                steps -= (1ll << i);
            }
        }
        assert(steps == 0);
        return ans;
    };

    ll L = -1, R = 1e18;
    while (R - L > 1) {
        ll C = (L + R) / 2;
        ll a0 = geta(C);
        ll c0 = c - C;
        if (c0 <= a0)
            R = C;
        else
            L = C;
    }
    cout << R << '\n';

    return 0;
}
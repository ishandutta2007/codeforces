/*
    author:  Maksim1744
    created: 24.10.2021 13:06:28
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        ll need = (a + b * 2 + c * 3) / 2;
        ll sm = a + b * 2 + c * 3;
        ll ans = 1e9;
        for (ll x = need; x >= need - 5 && x >= 0; --x) {
            for (int c2 = 0; c2 < 5 && c2 <= b; ++c2) {
                if (x >= c2 * 2 && (x - c2 * 2) % 3 == 0 && (x - c2 * 2) / 3 <= c) {
                    ans = min(ans, abs((sm - x) - x));
                }
            }
        }
        for (ll x = need; x >= need - 5 && x >= 0; --x) {
            for (int c2 = 0; c2 < 5 && c2 <= c; ++c2) {
                if (x >= c2 * 3 && (x - c2 * 3) % 2 == 0 && (x - c2 * 3) / 2 <= b) {
                    ans = min(ans, abs((sm - x) - x));
                }
            }
        }
        cout << ans << '\n';
    } else if (a == 1) {
        if (b == 0) {
            cout << (c % 2 == 0 ? 1 : 2) << '\n';
        } else if (c == 0) {
            cout << 1 << '\n';
        } else {
            cout << (a + b * 2 + c * 3) % 2 << '\n';
        }
    } else {
        cout << (a + b * 2 + c * 3) % 2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}
/*
    author:  Maksim1744
    created: 19.04.2022 18:08:23
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int k = (n * 2 - 1 + 2) / 3;
    vector<pair<int, int>> ans;
    if (n % 3 == 0) {
        for (int i = 0; i < n / 3; ++i) {
            ans.eb(n/3 + 1 + i, n/3 + n/3 - i);
        }
        for (int i = 0; i < n / 3 - 1; ++i) {
            ans.eb(1 + i, n/3 - i - 1);
        }
        ans.eb(n/3, n/3);
    } else if (n % 3 == 1) {
        for (int i = 0; i < n / 3 + 1; ++i) {
            ans.eb(i + 1, n / 3 + 1 - i);
        }
        for (int i = 0; i < n / 3; ++i) {
            ans.eb(n / 3 + 1 + 1 + i, n / 3 + 1 + n / 3 - i);
        }
    } else {
        for (int i = 0; i < n / 3 + 1; ++i) {
            ans.eb(i + 1, n / 3 + 1 - i);
        }
        for (int i = 0; i < n / 3; ++i) {
            ans.eb(n / 3 + 1 + 1 + i, n / 3 + 1 + n / 3 - i);
        }
    }
    debug {
        vector<string> v(n, string(n, '.'));;
        for (auto [u, x] : ans) {
            v[u - 1][x - 1] = 'X';
        }
        for (auto s : v)
            cerr << s << '\n';
    }
    assert(ans.size() == k);
    cout << k << '\n';
    for (auto p : ans)
        cout << p << '\n';

    return 0;
}
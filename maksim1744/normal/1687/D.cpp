/*
    author:  Maksim1744
    created: 03.06.2022 18:12:34
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
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    #ifdef HOUSE
    int N = maxe(a) * 3.3;
    #else
    const int N = 6.6e6;
    #endif
    vector<int> prev(N, -1);
    vector<int> next(N, N);
    for (int k : a)
        prev[k] = next[k] = k;
    for (int i = 1; i < N; ++i)
        if (prev[i] == -1)
            prev[i] = prev[i - 1];
    for (int i = N - 2; i >= 0; --i)
        if (next[i] == N)
            next[i] = next[i + 1];


    show(a);

    for (int s0 = 1;; ++s0) {
        ll i0 = a[0];
        ll s = s0;
        bool ok = true;
        ll lk = s * s - i0;
        ll rk = lk + (i0 + s) - prev[i0 + s];
        lk = max(lk, 0ll);
        if (lk > rk) continue;
        i0 = next[i0 + s + 1];
        show(lk, rk, i0);
        while (i0 != N) {
            ll LK = (s + 1) * (s + 1) - i0;
            ll RK = LK + (i0 + s + 1) - prev[i0 + s + 1];
            show(lk, rk, i0, LK, RK, s);
            if (RK < lk) {
                ++s;
                continue;
            } else if (LK > rk) {
                ok = false;
                break;
            } else {
                lk = max(lk, LK);
                rk = min(rk, RK);
                assert(lk <= rk);
                i0 = next[i0 + s + 2];
            }
        }
        if (!ok) continue;
        cout << lk << '\n';
        break;
    }

    return 0;
}
/*
    author:  Maksim1744
    created: 19.11.2019 18:33:05
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

#ifdef HOMEn
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int N = 10;
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
const int N = 1000020;
#endif

array<ll, N> a, aa;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += aa[i];
    }
    ll sm0 = sm;
    show(sm);
    vector<ll> check;
    ll p = 2;
    while (p * p <= sm) {
        if (sm % p == 0) {
            check.pb(p);
            while (sm % p == 0)
                sm /= p;
        }
        ++p;
    }
    if (sm != 1)
        check.pb(sm);
    sm = sm0;
    ll mn = -1;
    assert(check.size() < 15);
    for (auto k : check) {
        // show(k);
        for (int i = 0; i < n; ++i) {
            a[i] = aa[i] % k;
        }
        // show(k, a);

        int ind = 0;
        ll need = k;
        ll cur_ans = 0;
        while (ind < n) {
            ll ind0 = ind;
            ll mid = -1;
            ll cur = 0;
            while (ind < n) {
                cur += a[ind];
                if (mid == -1 && cur * 2 >= need) {
                    mid = ind;
                    break;
                }
                ++ind;
            }
            if (mid == -1)
                break;
            show(a, mid);
            show(need);
            cur = 0;
            ind = ind0;
            while (cur < need) {
                ll get = min(need - cur, a[ind]);
                a[ind] -= get;
                cur_ans += get * abs(mid - ind);
                cur += get;
                if (a[ind] == 0)
                    ++ind;
            }
            assert(ind > ind0);
        }
        shows;
        show(k, cur_ans);
        if (mn == -1 || mn > cur_ans)
            mn = cur_ans;
    }
    cout << mn << endl;
    return 0;
}
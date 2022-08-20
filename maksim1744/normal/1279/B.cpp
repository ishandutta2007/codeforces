/*
    author:  Maksim1744
    created: 27.12.2019 17:42:55
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

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
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
#endif

#define int ll

main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll s;
        cin >> s;
        vector<ll> v(n);
        cin >> v;
        vector<ll> sms(n);
        sms[0] = v[0];
        for (int i = 1; i < n; ++i)
            sms[i] = sms[i - 1] + v[i];
        int ind = 0;
        while (ind < n && sms[ind] <= s)
            ++ind;
        int imx = 0;
        if (ind == n) {
            cout << 0 << '\n';
            continue;
        }
        int can = ind;
        for (int i = 0; i <= min(n - 1, ind); ++i) {
            if (v[i] > v[imx])
                imx = i;
        }
        show(sms, ind);
        // s -= v[imx];
        while (ind < n && sms[ind] - v[imx] <= s)
            ++ind;
        if (ind - 1 > can)
            cout << imx + 1 << '\n';
        else
            cout << 0 << '\n';
        // for (int i = 0; i < n; ++i) {
        //     if (sk[i] > mx) {
        //         mx = sk[i];
        //         imx = i + 1;
        //     }
        // }
        // cout << imx << '\n';
    }
    return 0;
}
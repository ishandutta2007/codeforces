/*
    author:  Maksim1744
    created: 07.03.2020 13:10:00
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

const int K = 27;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;

    int ans = 0;
    for (int k = K; k >= 0; --k) {
        sort(v.begin(), v.end());
        ll cnt = 0;

        for (int i = 0; i < n; ++i) {
            int x = v[i];
            int i1 = lowb(v, (1 << k) - x);
            int i2 = lowb(v, (1 << (k + 1)) - x);
            i1 = max(i1, i + 1);
            i2 = max(i2, i + 1);
            cnt += i2 - i1;
            i1 = lowb(v, ((1<<k) + (1 << (k + 1))) - x);
            i2 = n;
            i1 = max(i1, i + 1);
            i2 = max(i2, i + 1);
            cnt += i2 - i1;
        }
        for (int i = 0; i < n; ++i) {
            v[i] &= (1 << k) - 1;
        }

        if (cnt % 2 == 1)
            ans ^= 1 << k;
    }
    cout << ans << endl;

    // int ans = 0;
    // vector<int> if1(K, 0);
    // int xr = 0;
    // for (int i = 0; i < n; ++i) {
    //     int cur = 0;
    //     for (int j = 0; j < K; ++j) {
    //         if ((v[i] >> j) & 1)
    //             cur ^= if1[j];
    //     }
    //     ans ^= cur ^ xr;
    //     xr ^= v[i];
    //     for (int j = 0; j < K; ++j) {
    //         if1[j] ^= ((1 << j) + v[i]) ^ v[i];
    //     }
    //     show(if1);
    //     show(ans);
    //     show(xr);
    //     shows;
    // }
    // cout << ans << endl;

    return 0;
}
/*
    author:  Maksim1744
    created: 05.01.2021 17:37:15
*/

#include "bits/stdc++.h"

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

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    cin >> k;
    --k;
    vector<ll> c(m);
    cin >> c;
    ll l = 0, r = min(n, m) + 1;
    sort(k.begin(), k.end());
    // cerr << k << endl;
    // cerr << c << endl;
    while (r - l > 1) {
        ll C = (l + r) / 2;
        int ind = n - C;
        bool ok = true;
        for (int i = 0; i < C; ++i) {
            if (k[ind + i] < i) {
                ok = false;
                break;
            }
        }
        if (ok)
            l = C;
        else
            r = C;
    }
    ll ans = 1e18;
    int res = l;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += c[k[i]];
    }
    ans = cur;
    for (int i = 0; i < res; ++i) {
        cur -= c[k[n - i - 1]];
        cur += c[i];
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    // show(l, r);
    // ll ans = 0;
    // ll res = l;
    // for (int i = 0; i < res; ++i) {
    //     ans += c[i];
    // }
    // for (int i = 0; i < n - res; ++i)
    //     ans += c[k[i]];
    // cout << ans << '\n';
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
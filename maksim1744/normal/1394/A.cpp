/*
    author:  Maksim1744
    created: 12.08.2020 17:36:28
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, d, m;
    cin >> n >> d >> m;
    vector<ll> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    if (a.back() <= m) {
        cout << sum(a) << '\n';
        return 0;
    }

    vector<ll> good, bad;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= m) good.pb(a[i]);
        else bad.pb(a[i]);
    }
    ll sgood = sum(good);
    for (int i = 1; i < good.size(); ++i)
        good[i] += good[i - 1];
    // reverse(good.begin(), good.end());
    reverse(bad.begin(), bad.end());
    for (int i = 1; i < bad.size(); ++i)
        bad[i] += bad[i - 1];
    // while (good.size() <= n) good.pb(0);
    // while (bad.size() <= n) bad.pb(0);
    // for (int i = 1; i < bad.size(); ++i) {
    //     good[i] += good[i - 1];
    //     bad[i] += bad[i - 1];
    // }
    ll ans = 0;
    int can = (n + d) / (d + 1);
    reverse(a.begin(), a.end());
    for (int i = 0; i < min(n, can); ++i) {
        ans += a[i];
    }
    for (int cnt = 1; cnt <= bad.size(); ++cnt) {
        // if ((ll)(cnt - 1) * d + cnt < bad.size()) continue;
        if ((ll)(cnt - 1) * d + cnt > n) break;
        for (int nd = 0; nd <= d; ++nd) {
            ll sz = (cnt - 1) * d + cnt + nd;
            if (sz > n || sz < bad.size()) continue;
            ll cur = bad[cnt - 1];
            ll left = sz - (int)bad.size();
            cur += sgood;
            if (left != 0)
                cur -= good[left - 1];
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;

    return 0;
}
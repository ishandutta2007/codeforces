/*
    author:  Maksim1744
    created: 17.08.2020 16:36:49
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

    ll n, v;
    cin >> n >> v;
    vector<pair<ll, int>> c1, c2;
    for (int i = 0; i < n; ++i) {
        ll t, p;
        cin >> t >> p;
        if (t == 1) c1.eb(p, i + 1);
        else c2.eb(p, i + 1);
    }
    sort(c1.rbegin(), c1.rend());
    sort(c2.rbegin(), c2.rend());

    for (int i = 1; i < c1.size(); ++i) {
        c1[i].first += c1[i - 1].first;
    }
    for (int i = 1; i < c2.size(); ++i) {
        c2[i].first += c2[i - 1].first;
    }

    ll ans = 0;
    int bestc1 = 0, bestc2 = 0;

    for (int cnt = 0; cnt <= c1.size(); ++cnt) {
        ll sm = 0;
        if (cnt > v) break;
        if (cnt != 0) {
            sm += c1[cnt - 1].first;
        }
        int curc1 = cnt;
        int curc2 = 0;
        if (!c2.empty()) {
            ll can = (v - cnt) / 2;
            can = min(can, (ll)c2.size());
            if (can != 0) {
                curc2 = can;
                sm += c2[can - 1].first;
            }
        }
        if (sm > ans) {
            ans = sm;
            bestc1 = curc1;
            bestc2 = curc2;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < bestc1; ++i) {
        cout << c1[i].second << ' ';
    }
    for (int i = 0; i < bestc2; ++i) {
        cout << c2[i].second << ' ';
    }
    cout << '\n';

    return 0;
}
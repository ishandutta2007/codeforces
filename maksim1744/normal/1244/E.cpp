/*
    author:  Maksim1744
    created: 13.10.2019 12:37:08
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    cin >> a;
    map<ll, int> cnt;
    for (auto k : a) {
        cnt[k]++;
    }
    deque<pair<ll, int>> q;
    for (auto p : cnt) {
        q.pb(p);
    }
    while (k > 0 && q.size() > 1) {
        // showt(k, q);
        if (q.front().second < q.back().second) {
            ll need = (q[1].first - q[0].first) * q[0].second;
            if (k >= need) {
                q[1].second += q[0].second;
                k -= need;
                q.pop_front();
            } else {
                ll can = k / q[0].second;
                q[0].first += can;
                break;
            }
        } else {
            int n = q.size();
            ll need = (q[n - 1].first - q[n - 2].first) * q[n - 1].second;
            show(need);
            if (k >= need) {
                q[n - 2].second += q[n - 1].second;
                k -= need;
                q.pop_back();
            } else {
                ll can = k / q[n - 1].second;
                q[n - 1].first -= can;
                break;
            }
        }
    }
    cout << q.back().first - q.front().first << '\n';
    return 0;
}
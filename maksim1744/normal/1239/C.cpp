/*
    author:  Maksim1744
    created: 20.10.2019 13:06:25
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
#endif

const ll inf = 1e18 * 2;

int main() {
    int n;
    cin >> n;
    ll p;
    cin >> p;
    vector<ll> t(n);
    cin >> t;
    queue<int> q;
    vector<ll> st(n, -1);
    set<int> want;
    vector<pair<ll, int>> when_want;
    for (int i = 0; i < n; ++i) {
        when_want.eb(t[i], i);
    }
    sort(when_want.begin(), when_want.end());
    int when_want_ind = 0;
    ll time = 0;
    multiset<ll> times;
    for (int i = 0; i < n; ++i) {
        times.insert(t[i]);
    }
    set<int> in_queue;
    in_queue.insert(n + 5);
    while (!times.empty()) {
        ll now = *times.begin();
        times.erase(times.begin());
        while (when_want_ind < when_want.size() && when_want[when_want_ind].first <= now) {
            want.insert(when_want[when_want_ind].second);
            ++when_want_ind;
        }
        if (!q.empty() && st[q.front()] + p <= now) {
            in_queue.erase(q.front());
            q.pop();
        }
        if (!want.empty()) {
            auto man = *want.begin();
            if (*in_queue.begin() > man) {
                q.push(man);
                in_queue.insert(man);
                want.erase(want.begin());
            }
        }
        if (!q.empty() && st[q.front()] == -1) {
            st[q.front()] = now;
            times.insert(now + p);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << st[i] + p << ' ';
    }
    cout << '\n';
    return 0;
}
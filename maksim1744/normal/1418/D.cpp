/*
    author:  Maksim1744
    created: 14.09.2020 18:09:15
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

    int n, q;
    cin >> n >> q;
    set<int> p;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        p.insert(k);
    }
    auto it = p.begin();
    auto it1 = next(it);
    multiset<int> dists;
    while (it1 != p.end()) {
        dists.insert(*it1 - *it);
        ++it;
        ++it1;
    }
    auto calc = [&]() {
        if (p.size() <= 2) return 0;
        return *prev(p.end()) - *p.begin() - *prev(dists.end());
    };
    cout << calc() << '\n';
    while (q--) {
        int tp;
        int x;
        cin >> tp >> x;
        show(p, dists);
        if (tp == 0) {
            p.erase(x);
            auto it = p.lower_bound(x);
            int r = -1;
            if (it != p.end()) {
                dists.erase(dists.find(*it - x));
                r = *it;
            }
            int l = -1;
            if (it != p.begin()) {
                --it;
                l = *it;
                dists.erase(dists.find(x - *it));
            }
            if (l != -1 && r != -1)
                dists.insert(r - l);
        } else {
            auto it = p.lower_bound(x);
            if (it != p.end() && it != p.begin()) {
                dists.erase(dists.find(*it - *prev(it)));
            }
            p.insert(x);
            it = p.find(x);
            if (it != p.begin())
                dists.insert(x - *prev(it));
            if (next(it) != p.end())
                dists.insert(*next(it) - x);
        }
        cout << calc() << '\n';
    }

    return 0;
}
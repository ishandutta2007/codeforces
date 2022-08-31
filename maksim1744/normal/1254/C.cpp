/*
    author:  Maksim1744
    created: 19.11.2019 17:58:58
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

ll ask(int a, int b, int c, int d) {
    ++b; ++c; ++d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    ll ans;
    cin >> ans;
    return ans;
}

ll aska(int a, int b, int c) {
    return ask(2, a, b, c);
}

ll asks(int a, int b, int c) {
    return ask(1, a, b, c);
}

int main() {
    int n;
    cin >> n;
    int v0 = 0;
    int v1 = 1;
    for (int i = 2; i < n; ++i) {
        if (aska(v0, v1, i) > 0) {
            v1 = i;
        }
    }
    vector<pair<ll, int>> byd;
    for (int i = 0; i < n; ++i) {
        if (i == v0 || i == v1)
            continue;
        byd.emplace_back(asks(v0, v1, i), i);
    }
    sort(byd.begin(), byd.end());
    vector<int> order = {v0, v1};
    for (int i = 0; i < n - 2; ++i) {
        order.pb(byd[i].second);
    }
    vector<bool> u(n, false);
    u[v0] = true;
    u[v1] = true;
    vector<int> ans = {v0, v1};
    vector<int> sth;
    for (int i = 0; i < n - 2; ++i) {
        sth.pb(aska(order[i], order[i + 1], order[i + 2]));
    }
    for (int i = 2; i < n; ++i) {
        if (i - 1 < sth.size() && sth[i - 1] < 0) {
            ans.pb(order[i]);
            u[order[i]] = true;
        }
    }
    show(order);
    show(sth);
    show(u);
    show(ans);
    reverse(order.begin(), order.end());
    for (auto k : order) {
        if (!u[k])
            ans.pb(k);
    }

    // for (auto k : order) {
    //     while (ans.size() >= 2 && aska(ans[ans.size() - 2], ans[ans.size() - 1], k) > 0) {
    //         ans.pop_back();
    //     }
    //     ans.pb(k);
    // }
    // for (auto k : ans) {
    //     u[k] = true;
    // }
    // reverse(order.begin(), order.end());
    // for (auto k : order) {
    //     if (!u[k])
    //         ans.pb(k);
    // }


    reverse(ans.begin() + 1, ans.end());
    ++ans;
    cout << 0;
    for (auto k : ans) {
        cout << ' ' << k;
    }
    cout << endl;
    return 0;
}
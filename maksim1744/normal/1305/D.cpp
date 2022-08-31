/*
    author:  Maksim1744
    created: 03.03.2020 17:46:53
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

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto ask = [&](int u, int v) {
        cout << "? " << u + 1 << ' ' << v + 1 << endl;
        cin >> u;
        return u - 1;
    };
    auto say = [&](int v) {
        cout << "! " << v + 1 << endl;
        exit(0);
    };
    set<int> leafes;
    vector<int> d(n);
    vector<bool> u(n, false);
    for (int i = 0; i < n; ++i) {
        d[i] = g[i].size();
        if (d[i] == 1) {
            leafes.insert(i);
            u[i] = true;
        }
    }
    for (int iii = 0; iii < n / 2; ++iii) {
        auto v1 = *leafes.begin();
        leafes.erase(leafes.begin());
        auto v2 = *leafes.begin();
        leafes.erase(leafes.begin());
        int lca = ask(v1, v2);
        if (v1 == lca)
            say(v1);
        else if (v2 == lca)
            say(v2);
        for (auto v : {v1, v2}) {
            for (auto k : g[v]) {
                if (!u[k]) {
                    d[k]--;
                    if (d[k] <= 1) {
                        leafes.insert(k);
                        u[k] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!u[i])
            leafes.insert(i);
    }
    say(*leafes.begin());
    // for (int i = 0; i < n; ++i) {
    //     if (!u[i]) {
    //         say(i);
    //     }
    // }

    return 0;
}
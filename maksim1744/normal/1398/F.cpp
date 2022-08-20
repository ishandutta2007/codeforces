/*
    author:  Maksim1744
    created: 14.08.2020 18:06:14
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
    string s;
    cin >> s;
    vector<int> simr(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == s[i + 1]) simr[i] = simr[i + 1] + 1;
    }
    vector<int> tor(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == s[i + 1] || s[i] == '?') {
            tor[i] = tor[i + 1] + 1;
        } else if (s[i + 1] == '?') {
            int ind = i + simr[i + 1] + 1;
            if (ind >= n || s[ind] != s[i]) tor[i] = simr[i + 1] + 1;
            else tor[i] = simr[i + 1] + tor[ind] + 1;
        }
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    vector<int> rk(n, 1);
    vector<int> corr = p;

    function<int(int)> par = [&](int v) {
        return (v == p[v] ? v : p[v] = par(p[v]));
    };
    auto un = [&](int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return;
        int corr_res = corr[v];
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        corr[v] = corr_res;
    };

    set<int> good;
    for (int i = 0; i < n; ++i) {
        good.insert(i);
    }
    vector<int> ans;
    for (int x = 1; x <= n; ++x) {
        int cur = 0;
        int k = corr[par(0)];
        while (true) {
            if (tor[k] < x) {
                if (k != n - 1) {
                    un(k, k + 1);
                    k = corr[par(k)];
                } else {
                    break;
                }
            } else {
                ++cur;
                if (k + x >= n) break;
                k = corr[par(k + x)];
            }
        }
        ans.pb(cur);
        if (cur == 0) break;
        // while (!good.empty() && tor[*good.begin()] < x) good.erase(good.begin());
        // if (good.empty()) {
        //     cout << 0 << ' ';
        //     continue;
        // }
        // int ans = 0;
        // int k = *good.begin();
        // ++ans;
        // while (true) {
        //     auto it = good.lower_bound(k + x);
        //     while (it != good.end() && tor[*it] < x) {
        //         auto iit = it;
        //         ++it;
        //         good.erase(iit);
        //     }
        //     if (it == good.end()) break;
        //     ++ans;
        //     k = *it;
        // }
        // cout << ans << ' ';
    }
    while (ans.size() < n) ans.pb(0);
    cout << ans << '\n';

    return 0;
}
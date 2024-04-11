/*
    author:  Maksim1744
    created: 05.05.2019 23:31:54
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

#ifdef HOMEn
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
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const ll mod = 998244353;
const int nax = 2005;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (s.back() == '1') {
        cout << 0 << '\n';
        return 0;
    } else {
        s.back() = '0';
    }
    vector<ll> p2(nax);
    p2[0] = 1;
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (int i = 1; i < nax; ++i)
        p2[i] = (p2[i - 1] << 1) % mod;
    for (int a = 1; a < n; ++a) {
        shows;
        // a.size() = a;
        int m = (n + 1) / 2 + (a + 1) / 2;
        vector<vector<pair<int, bool>>> g(m + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                int v1, v2;
                if (i < (n + 1) / 2)
                    v1 = i;
                else
                    v1 = n - 1 - i;
                if (i < (a + 1) / 2)
                    v2 = i + (n + 1) / 2;
                else if (i < a)
                    v2 = a - 1 - i + (n + 1) / 2;
                else
                    v2 = m;
                g[v1].eb(v2, s[i] == '1');
                g[v2].eb(v1, s[i] == '1');
            }
        }
        show(m, g);
        vector<int> comp(g.size(), -1);
        int color = 0;
        function<void(int)> dfs = [&](int v) {
            comp[v] = color;
            for (auto [k, b] : g[v])
                if (comp[k] == -1 && !b)
                    dfs(k);
        };
        for (int i = 0; i < g.size(); ++i) {
            if (comp[i] == -1) {
                dfs(i);
                ++color;
            }
        }
        show(comp);
        // bool ok = true;
        // for (int i = 0; i < g.size(); ++i) {
        //     for (auto [j, b] : g[i]) {
        //         if (b && comp[i] == comp[j]) {
        //             ok = false;
        //             break;
        //         }
        //     }
        //     if (!ok)
        //         break;
        // }
        // if (ok) {
        vector<set<int>> g1(color);
        for (int i = 0; i < g.size(); ++i)
            for (auto [j, b] : g[i])
                if (b)
                    g1[comp[i]].insert(comp[j]);
        show(g1);
        vector<int> col2(g1.size(), -1);
        function<bool(int, int)> dfs2 = [&](int v, int y) {
            col2[v] = y;
            for (auto k : g1[v]) {
                if (col2[k] == col2[v])
                    return false;
                else if (col2[k] == -1)
                    if (!dfs2(k, 1 - y))
                        return false;
            }
            return true;
        };
        int cnt = 0;
        bool ok = true;
        for (int i = 0; i < g1.size(); ++i) {
            if (col2[i] == -1) {
                ++cnt;
                if (!dfs2(i, 0)) {
                    ok = false;
                    break;
                }
            }
        }
        show(col2, cnt);
        if (ok) {
            ans += p2[cnt - 1];
        }
        show(ok, ans);
        // }
    }
    cout << ans % mod << '\n';
    return 0;
}
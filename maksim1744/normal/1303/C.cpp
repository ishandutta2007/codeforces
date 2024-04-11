/*
    author:  Maksim1744
    created: 12.02.2020 17:47:21
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

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<set<int>> g(26);
        for (int i = 0; i < n - 1; ++i) {
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';
            g[a].insert(b);
            g[b].insert(a);
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (g[i].size() > 2) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        string ans;
        vector<bool> u(26, false);
        function<void(int)> dfs = [&](int v) {
            ans.pb('a' + v);
            u[v] = true;
            for (auto k : g[v]) {
                if (!u[k]) {
                    dfs(k);
                }
            }
        };
        for (int i = 0; i < 26; ++i) {
            if (u[i]) continue;
            if (g[i].size() == 0) {
                ans.pb('a' + i);
                u[i] = true;
            } else if (g[i].size() == 1) {
                dfs(i);
            }
        }
        show(ans);
        if (ans.size() != 26)
            cout << "NO\n";
        else
            cout << "YES\n" << ans << '\n';
    }

    return 0;
}
/*
    author:  Maksim1744
    created: 26.06.2019 18:12:55
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

array<int, 700> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, pair<int, int>> m;
        for (int i = 0; i < n; ++i) {
            int t, f;
            cin >> t >> f;
            m[t].first++;
            m[t].second += f;
        }
        vector<pair<int, int>> c;
        for (auto p : m) {
            c.eb(p.second.first, p.second.second);
        }
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        show(c);
        int last = 1e9;
        int s = 0;
        vector<int> ans;
        for (auto [x, y] : c) {
            x = min(x, last);
            if (x <= 0)
                break;
            ans.pb(x);
            s += x;
            last = x - 1;
        }
        vector<pair<int, int>> d;
        for (auto p : c) {
            d.eb(p.second, p.first);
        }
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        int f = 0;
        vector<bool> u(d.size(), false);
        for (auto t : ans) {
            int f0 = -1;
            int fi = -1;
            for (int i = 0; i < d.size(); ++i) {
                if (u[i])
                    continue;
                if (t > d[i].second)
                    continue;
                if (d[i].first > f0) {
                    f0 = d[i].first;
                    fi = i;
                }
            }
            u[fi] = true;
            f += min(f0, t);
        }
        // show(ans);
        // for (int i = 0; i <= ans.size(); ++i)
        //     dp[i] = 0;
        // // vector<vector<int>> dp(c.size() + 1, vector<int>(ans.size() + 1, 0));
        // int f = 0;
        // for (int i = 1; i < c.size() + 1; ++i) {
        //     for (int j = ans.size(); j >= 1; --j) {
        //         // dp[j] = dp[j];
        //         if (c[i - 1].first >= ans[j - 1]) {
        //             umax(dp[j], dp[j - 1] + min(c[i - 1].second, ans[j - 1]));
        //         }
        //     }
        //     umax(f, dp[ans.size()]);
        // }
        // printMatrix(dp);
        cout << s << ' ' << f << '\n';
    }
    return 0;
}
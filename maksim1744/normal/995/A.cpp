/*
    author:  Maksim1744
    created: 18.08.2020 23:51:33
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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(4, vector<int>(n));
    cin >> v;

    vector<pair<int, pair<int, int>>> ans;

    auto spin = [&]() {
        int x = ans.size();
        for (int i = 0; i < n - 1; ++i) {
            if (v[1][i + 1] == 0 && v[1][i] != 0) {
                ans.eb(v[1][i], mp(1, i + 1));
            }
        }
        if (v[2][n - 1] == 0 && v[1][n - 1] != 0) {
            ans.eb(v[1][n - 1], mp(2, n - 1));
        }
        for (int i = 1; i < n; ++i) {
            if (v[2][i - 1] == 0 && v[2][i] != 0) {
                ans.eb(v[2][i], mp(2, i - 1));
            }
        }
        if (v[1][0] == 0 && v[2][0] != 0) {
            ans.eb(v[2][0], mp(1, 0));
        }
        for (; x < ans.size(); ++x) {
            for (int i = 1; i < 3; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (v[i][j] == ans[x].first) {
                        v[i][j] = 0;
                    }
                }
            }
            v[ans[x].second.first][ans[x].second.second] = ans[x].first;
        }
    };

    auto place = [&]() {
        int done = 0;
        for (int i = 0; i < n; ++i) {
            if (v[0][i] == v[1][i] && v[0][i] != 0) {
                ans.eb(v[0][i], mp(0, i));
                v[1][i] = 0;
                v[0][i] = -1;
                ++done;
            }
            if (v[2][i] == v[3][i] && v[2][i] != 0) {
                ans.eb(v[2][i], mp(3, i));
                v[2][i] = 0;
                v[3][i] = -1;
                ++done;
            }
        }
        return done;
    };

    int done = place();
    if (k == n * 2 && done == 0) {
        cout << -1 << '\n';
        return 0;
    }
    while (done < k) {
        spin();
        done += place();
    }

    assert(ans.size() <= 20000);
    cout << ans.size() << '\n';
    for (auto [x, p] : ans) {
        cout << x << ' ' << p.first + 1 << ' ' << p.second + 1 << '\n';
    }

    return 0;
}
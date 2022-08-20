/*
    author:  Maksim1744
    created: 06.09.2020 18:24:31
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
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < n * 2; ++i) {
            cout << (i % n) + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "Second" << endl;
        vector<vector<int>> pairs(n);
        vector<int> where(n * 2 + 1);
        for (int i = 0; i < n * 2; ++i) {
            int p;
            cin >> p;
            --p;
            pairs[p].pb(i + 1);
            where[i + 1] = p;
        }
        vector<int> sim(n * 2 + 1);
        for (int i = 0; i < n; ++i) {
            sim[i + 1] = i + 1 + n;
            sim[i + 1 + n] = i + 1;
        }
        vector<int> ans(n, -1);
        vector<bool> u(n, false);
        vector<vector<int>> near(n);
        for (int i = 0; i < n; ++i) {
            if (pairs[i][0] % n == pairs[i][1] % n) {
                u[i] = true;
                ans[i] = pairs[i][0];
            } else {
                near[i].pb(where[sim[pairs[i][0]]]);
                near[i].pb(where[sim[pairs[i][1]]]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!u[i]) {
                int x = near[i][0];
                int y = i;
                ans[i] = pairs[i][0];
                while (x != i) {
                    u[x] = true;
                    int was = ans[y];
                    if (pairs[x][0] % n == was % n) ans[x] = pairs[x][1];
                    else ans[x] = pairs[x][0];
                    int z = near[x][0] + near[x][1] - y;
                    y = x;
                    x = z;
                }
            }
        }
        ll s = 0;
        for (auto k : ans) {
            s += k;
        }
        show(ans);
        s %= n * 2;
        if (s == n) {
            for (int i = 0; i < n; ++i) {
                ans[i] = pairs[i][0] + pairs[i][1] - ans[i];
            }
        }
        cout << ans << endl;
    }
    // int n = 10;
    // vector<int> p(n);
    // for (int i = 0; i < n; ++i) {
    //     p[i] = i + 1;
    // }
    // set<vector<int>> res;
    // do {
    //     bool ok = true;
    //     for (int i = 0; i < (1 << (n / 2)); ++i) {
    //         int s = 0;
    //         for (int j = 0; j < n / 2; ++j) {
    //             s += p[j * 2 + ((i >> j) & 1)];
    //         }
    //         // show(p, i, s);
    //         if (s % n == 0) {
    //             ok = false;
    //             break;
    //         }
    //     }
    //     if (ok) {
    //         vector<int> u = p;
    //         for (int i = 0; i < n / 2; ++i) {
    //             if (u[i * 2] > u[i * 2 + 1])
    //                 swap(u[i * 2], u[i * 2 + 1]);
    //         }
    //         res.insert(u);
    //     }
    // } while (next_permutation(p.begin() + 1, p.end()));
    // cerr << res.size() << endl;
    // for (auto v : res) {
    //     cout << v << '\n';
    // }

    return 0;
}
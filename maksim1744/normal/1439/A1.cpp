/*
    author:  Maksim1744
    created: 17.11.2020 17:37:22
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

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i][j] = (s[j] == '1');
        }
    }
    vector<vector<int>> ans;
    auto apply = [&](vector<int> x) {
        ans.pb(x);
        for (int i = 0; i < 3; ++i) {
            v[x[i * 2]][x[i * 2 + 1]] ^= 1;
        }
    };
    for (int i = n - 1; i >= 2; --i) {
        for (int j = 0; j < m; ++j) {
            int j1 = j + 1;
            if (j1 == m) j1 = j - 1;
            if (v[i][j] == 0) continue;
            apply(vector<int>{i, j, i - 1, j1, i - 1, j});
        }
    }
    for (int j = m - 1; j >= 2; --j) {
        for (int i = 0; i < 2; ++i) {
            int i1 = i ^ 1;
            if (v[i][j] == 0) continue;
            apply(vector<int>{i, j, i1, j - 1, i, j - 1});
        }
    }

    vector<vector<int>> other;
    other.pb(vector<int>{0, 0, 0, 1, 1, 0});
    other.pb(vector<int>{0, 0, 0, 1, 1, 1});
    other.pb(vector<int>{1, 0, 0, 1, 1, 1});
    other.pb(vector<int>{0, 0, 1, 0, 1, 1});

    bool ook = false;

    for (int i = 0; i < 16; ++i) {
        vector<vector<int>> here;
        for (int j = 0; j < 4; ++j) {
            if ((i >> j) & 1) {
                here.pb(other[j]);
            }
        }
        // shows;
        // show(here);
        // for (int i = 0; i < 2; ++i) {
        //     for (int j = 0; j < 2; ++j) {
        //         cout << v[i][j];
        //     }
        // }
        // cout << endl;
        for (auto x : here) {
            for (int i = 0; i < 3; ++i) {
                v[x[i * 2]][x[i * 2 + 1]] ^= 1;
            }
        }
        // for (int i = 0; i < 2; ++i) {
        //     for (int j = 0; j < 2; ++j) {
        //         cout << v[i][j];
        //     }
        // }
        // cout << endl;
        bool ok = true;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (v[i][j] != 0) {
                    ok = false;
                    break;
                }
            }
        }
        for (auto x : here) {
            for (int i = 0; i < 3; ++i) {
                v[x[i * 2]][x[i * 2 + 1]] ^= 1;
            }
        }
        if (ok) {
            for (auto x : here) {
                apply(x);
            }
            ook = true;
            break;
        }
    }
    assert(ook);
    cout << ans.size() << '\n';
    for (auto x : ans) {
        ++x;
        cout << x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}
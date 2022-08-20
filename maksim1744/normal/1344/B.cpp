/*
    author:  Maksim1744
    created: 06.05.2020 17:46:49
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

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    int empty1 = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '#') {
                if (j + 1 == m || v[i][j + 1] == '.')
                    ++cnt;
            }
        }
        if (cnt >= 2) {
            cout << -1 << endl;
            return 0;
        }
        if (cnt == 0)
            ++empty1;
    }
    if (empty1 == n) {
        cout << 0 << '\n';
        return 0;
    }
    int empty2 = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (v[j][i] == '#') {
                if (j + 1 == n || v[j + 1][i] == '.')
                    ++cnt;
            }
        }
        if (cnt >= 2) {
            cout << -1 << endl;
            return 0;
        }
        if (cnt == 0)
            ++empty2;
    }
    if (empty1 != 0 || empty2 != 0) {
        if (empty1 == 0 || empty2 == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool conn = false;
        bool has_sth = false;
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '#') {
                has_sth = true;
                break;
            }
        }
        if (!has_sth) continue;
        if (i == 0) {
            conn = false;
        } else {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '#' && v[i - 1][j] == '#') {
                    conn = true;
                    break;
                }
            }
        }
        if (!conn)
            ++ans;
    }
    cout << ans << endl;

    return 0;
}
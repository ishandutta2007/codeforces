/*
    author:  Maksim1744
    created: 13.08.2020 20:32:29
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
    vector<int> p(n);
    cin >> p;
    --p;
    vector<vector<int>> cycles;
    vector<bool> u(n, false);
    for (int i = 0; i < n; ++i) {
        if (!u[i]) {
            int x = p[i];
            cycles.eb();
            cycles.back().pb(i);
            u[i] = true;
            while (x != i) {
                u[x] = true;
                cycles.back().pb(x);
                x = p[x];
            }
        }
    }
    map<int, vector<vector<int>>> byl;
    for (auto c : cycles) {
        byl[c.size()].pb(c);
    }
    vector<int> q(n);
    for (auto [ln, cycs] : byl) {
        if (ln % 2 == 1) {
            for (auto c : cycs) {
                vector<int> res(c.size());
                // int ind = 0;
                for (int i = 0; i < c.size(); ++i) {
                    res[i * 2 % c.size()] = c[i];
                }
                for (int i = 0; i < res.size(); ++i) {
                    q[res[i]] = res[(i + 1) % res.size()];
                }
            }
        } else {
            if (cycs.size() % 2 == 1) {
                cout << -1 << '\n';
                return 0;
            }
            for (int i = 0; i < cycs.size(); i += 2) {
                for (int j = 0; j < ln; ++j) {
                    q[cycs[i][j]] = cycs[i + 1][j];
                    q[cycs[i + 1][j]] = cycs[i][(j + 1) % ln];
                }
            }
        }
    }
    ++q;
    cout << q << '\n';

    return 0;
}
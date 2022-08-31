/*
    author:  Maksim1744
    created: 30.09.2020 19:37:46
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

vector<pair<int, int>> ans;

template<typename T>
void make_equal(T b, T e) {
    int d = e - b;
    if (d == 1) {
        return;
    }
    auto m = b + d / 2;
    auto bb = b, mm = m, mm2 = m;
    make_equal(bb, mm);
    make_equal(mm2, e);
    while (m != e) {
        ans.eb(*b, *m);
        ++b; ++m;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> p2;
    int x = 1;
    for (int i = 0; i < 20; ++i) {
        if ((1 << i) & n) {
            p2.eb();
            for (int j = 0; j < (1 << i); ++j) {
                p2.back().pb(x);
                x += 1;
            }
        }
    }
    for (int i = 0; i < p2.size(); ++i) {
        if (p2[i].size() != 1) {
            make_equal(p2[i].begin(), p2[i].end());
        }
    }
    show(p2);
    int ind = 0;
    if (p2.size() > 2) {
        for (int i = 0; i + 2 < p2.size(); ++i) {
            while (p2[i].size() != p2[i + 1].size()) {
                int sz = p2[i].size();
                for (int j = 0; j < sz; ++j) {
                    ans.eb(p2[i][j], p2.back()[ind]);
                    p2[i].pb(p2.back()[ind]);
                    ind += 1;
                }
                show(p2[i], ind);
            }
            int sz = p2[i].size();
            for (int j = 0; j < sz; ++j) {
                ans.eb(p2[i][j], p2[i + 1][j]);
                p2[i + 1].pb(p2[i][j]);
            }
        }
        show(p2);
    }
    assert(ans.size() <= 500000);
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }

    return 0;
}
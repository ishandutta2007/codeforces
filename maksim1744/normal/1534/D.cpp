/*
    author:  Maksim1744
    created: 13.06.2021 18:47:03
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> mem(n);
    auto ask = [&](int v) {
        if (!mem[v].empty()) return mem[v];
        cout << "? " << v + 1 << endl;
        mem[v].resize(n);
        cin >> mem[v];
        return mem[v];
    };

    auto d0 = ask(0);
    vector<int> cnt(2, 0);
    for (int i = 0; i < n; ++i) {
        cnt[d0[i] % 2]++;
    }
    int parity = -1;
    if (cnt[0] - 1 < cnt[1]) {
        parity = 0;
    } else {
        parity = 1;
    }

    set<pair<int, int>> edges;
    auto add_edge = [&](int u, int v) {
        if (u > v) swap(u, v);
        ++u; ++v;
        edges.emplace(u, v);
    };
    for (int i = 0; i < n; ++i) {
        if (d0[i] % 2 == parity) {
            auto d = ask(i);
            show(i, d);
            for (int j = 0; j < n; ++j) {
                if (d[j] == 1) {
                    add_edge(i, j);
                }
            }
        }
    }

    assert(edges.size() == n - 1);
    cout << "!" << endl;
    for (auto [a, b] : edges)
        cout << a << ' ' << b << endl;

    return 0;
}
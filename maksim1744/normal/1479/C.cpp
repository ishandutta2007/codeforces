/*
    author:  Maksim1744
    created: 07.02.2021 18:31:53
*/

#include "bits/stdc++.h"

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

const int B = 100;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int L, R;
    cin >> L >> R;

    cout << "YES\n";

    vector<vector<pair<int, int>>> g(B + 1);
    set<int> has;
    for (int i = 2; i < B; ++i)
        has.insert(i);
    vector<pair<pair<int, int>, int>> compr;
    function<void(int, int)> build = [&](int from, int r) {
        g[from].eb(B, 1);
        if (r == 1) {
            return;
        } else if (r == 2) {
            assert(!has.empty());
            int u = *has.begin();
            has.erase(has.begin());
            g[from].eb(u, 1);
            g[u].eb(B, 1);
            return;
        }

        assert(!has.empty());
        int u = *has.begin();
        has.erase(has.begin());
        assert(!has.empty());
        int v = *has.begin();
        has.erase(has.begin());

        if (r % 2 == 0) {
            g[u].eb(B, r - 1);
            --r;
        }

        g[from].eb(v, 1);
        g[from].eb(u, 1);
        int k = (r + 1) / 2;
        g[u].eb(v, k - 1);
        if (r >= 10)
            compr.eb(mp(from, u), v);
        build(v, r / 2);
    };

    build(1, R - L + 1);

    int side = *has.begin();
    has.erase(has.begin());
    g[side].eb(B, 1);

    int ind = 0;
    while (ind < compr.size()) {
        auto [wu, v] = compr[ind];
        auto [u2, u] = wu;
        ++ind;
        bool ok = true;
        vector<pair<int, int>> gu;
        for (auto [x, w] : g[u]) {
            if (x == B) {
                gu.eb(side, w - 1);
                if (w == 1) ok = false;
            } else {
                for (auto [x2, w2] : g[v])
                    gu.eb(x2, w + w2);
            }
        }
        if (!ok) {
            continue;
        }
        vector<pair<int, int>> gu2;
        for (auto [x, w] : g[u2]) {
            if (x == B) {
                gu2.eb(B, w);
            } else if (x == u) {
                gu2.eb(x, w);
            } else {
                for (auto [x2, w2] : g[v]) {
                    if (x2 == B)
                        gu2.eb(side, w + w2 - 1);
                    else
                        gu2.eb(x2, w + w2);
                }
            }
        }
        g[v].clear();
        swap(g[u], gu);
        swap(g[u2], gu2);
        ++ind;
    }

    vector<int> vert;
    for (int i = 0; i < B + 1; ++i) {
        if (!g[i].empty() || i == B)
            vert.pb(i);
    }

    for (int i = 0; i < g[1].size(); ++i) {
        g[1][i].second += L - 1;
    }

    vector<pair<pair<int, int>, int>> e;
    for (int i = 0; i <= B; ++i) {
        for (auto p : g[i]) {
            e.eb(mp(lowb(vert, i) + 1, lowb(vert, p.first) + 1), p.second);
        }
    }

    cout << vert.size() << ' ' << e.size() << '\n';
    for (auto p : e) {
        cout << p << '\n';
    }

    return 0;
}
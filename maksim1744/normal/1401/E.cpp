/*
    author:  Maksim1744
    created: 21.08.2020 18:26:40
*/

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

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

#ifdef HOMEn
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

const int N = 1e6;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // vector<int> cnt_up(N + 1, 0), cnt_down(N + 1, 0), cnt_right(N + 1, 0), cnt_left(N + 1, 0);
    vector<vector<int>> up(N + 1), down(N + 1), left(N + 1), right(N + 1);
    vector<pair<int, int>> hor(N + 1, {-1, -1});
    vector<pair<int, int>> ver(N + 1, {-1, -1});

    for (int i = 0; i < n; ++i) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        // assert(hor[y].first == -1);
        hor[y] = mp(lx, rx);

        // if (lx == 0) cnt_right[rx]++;
        // if (rx == N) cnt_left[lx]++;
        if (lx == 0) right[rx].pb(y);
        if (rx == N && lx != 0) left[lx].pb(y);
    }
    for (int i = 0; i < m; ++i) {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        // assert(ver[x].first == -1);
        ver[x] = mp(ly, ry);

        // if (ly == 0) cnt_up[ry]++;
        // if (ry == N) cnt_down[ly]++;
        if (ly == 0) up[ry].pb(x);
        if (ry == N && ly != 0) down[ly].pb(x);
    }

    right[N].pb(0);
    right[N].pb(N);
    // left[0].pb(0);
    // left[0].pb(N);
    up[N].pb(0);
    up[N].pb(N);
    // down[0].pb(0);
    // down[0].pb(N);

    hor[0] = hor[N] = ver[0] = ver[N] = mp(0, N);

    int id = 0;

    ll vertices = 0;
    ll edges = 0;

    ordered_set<pair<int, int>> begins, ends;
    for (int i = 0; i <= N; ++i) {
        if (hor[i].first != -1) {
            begins.insert({hor[i].first, ++id});
            ends.insert({hor[i].second, ++id});
        }
        for (int x : up[i]) {
            auto it1 = begins.lower_bound(mp(x + 1, -1));
            int cnt_right = (it1 == begins.end() ? 0 : begins.size() - begins.order_of_key(*it1));
            auto it2 = ends.lower_bound(mp(x, -1));
            int cnt_left = ends.order_of_key(*it2);

            int intersect = (int)begins.size() - cnt_left - cnt_right;

            edges += intersect - 1;
            vertices += intersect;
        }
    }
    show(edges, vertices);

    begins.clear(); ends.clear();
    for (int i = N; i >= 0; --i) {
        if (hor[i].first != -1) {
            begins.insert({hor[i].first, ++id});
            ends.insert({hor[i].second, ++id});
        }
        for (int x : down[i]) {
            auto it1 = begins.lower_bound(mp(x + 1, -1));
            int cnt_right = (it1 == begins.end() ? 0 : begins.size() - begins.order_of_key(*it1));
            auto it2 = ends.lower_bound(mp(x, -1));
            int cnt_left = ends.order_of_key(*it2);

            int intersect = (int)begins.size() - cnt_left - cnt_right;

            edges += intersect - 1;
            vertices += intersect;
        }
    }
    show(edges, vertices);

    begins.clear(); ends.clear();
    for (int i = 0; i <= N; ++i) {
        if (ver[i].first != -1) {
            begins.insert({ver[i].first, ++id});
            ends.insert({ver[i].second, ++id});
        }
        for (int x : right[i]) {
            auto it1 = begins.lower_bound(mp(x + 1, -1));
            int cnt_right = (it1 == begins.end() ? 0 : begins.size() - begins.order_of_key(*it1));
            auto it2 = ends.lower_bound(mp(x, -1));
            int cnt_left = ends.order_of_key(*it2);

            int intersect = (int)begins.size() - cnt_left - cnt_right;

            edges += intersect - 1;
            vertices += intersect;
        }
    }
    show(edges, vertices);

    begins.clear(); ends.clear();
    for (int i = N; i >= 0; --i) {
        if (ver[i].first != -1) {
            begins.insert({ver[i].first, ++id});
            ends.insert({ver[i].second, ++id});
        }
        for (int x : left[i]) {
            auto it1 = begins.lower_bound(mp(x + 1, -1));
            int cnt_right = (it1 == begins.end() ? 0 : begins.size() - begins.order_of_key(*it1));
            auto it2 = ends.lower_bound(mp(x, -1));
            int cnt_left = ends.order_of_key(*it2);

            int intersect = (int)begins.size() - cnt_left - cnt_right;

            edges += intersect - 1;
            vertices += intersect;
        }
    }
    show(edges, vertices);

    vertices /= 2;
    ll planes = edges + 2 - vertices;
    show(edges, vertices, planes);
    cout << planes - 1 << endl;

    return 0;
}
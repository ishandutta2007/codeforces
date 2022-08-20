/*
    author:  Maksim1744
    created: 19.06.2019 18:36:47
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

const int inf = 1e9 * 2 + 100;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> need(512, 0);
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f;
        int k = 0;
        for (int j = 0; j < f; ++j) {
            int b;
            cin >> b;
            k |= (1 << (b - 1));
        }
        need[k]++;
    }
    vector<vector<pair<int, int>>> v(512);
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        int r;
        cin >> r;
        int now = 0;
        for (int j = 0; j < r; ++j) {
            int b;
            cin >> b;
            now |= (1 << (b - 1));
        }
        v[now].eb(c, i + 1);
    }
    for (int i = 0; i < 512; ++i) {
        sort(v[i].begin(), v[i].end());
    }
    pair<int, int> best = {-1, -1};
    int bestcnt = -1;
    int bestc = inf;
    for (int i = 0; i < 512; ++i) {
        if (v[i].empty())
            continue;
        for (int j = i + 1; j < 512; ++j) {
            if (v[j].empty())
                continue;
            int cnt = 0;
            int mask = i | j;
            int submask = mask;
            while (submask != 0) {
                cnt += need[submask];
                submask = (submask - 1) & mask;
            }
            int c = v[i][0].first + v[j][0].first;
            pair<int, int> jj = {v[i][0].second, v[j][0].second};
            // show(i, j, v[i], v[j], cnt, c, jj);
            if (cnt > bestcnt || (cnt == bestcnt && c < bestc)) {
                bestcnt = cnt;
                bestc = c;
                best = jj;
            }
        }
    }
    for (int i = 0; i < 512; ++i) {
        if (v[i].size() < 2)
            continue;
        int cnt = 0;
        int mask = i;
        int submask = mask;
        while (submask != 0) {
            cnt += need[submask];
            submask = (submask - 1) & mask;
        }
        int c = v[i][0].first + v[i][1].first;
        pair<int, int> jj = {v[i][0].second, v[i][1].second};
        if (cnt > bestcnt || (cnt == bestcnt && c < bestc)) {
            bestcnt = cnt;
            bestc = c;
            best = jj;
        }
    }
    cout << best << '\n';
    return 0;
}
/*
    author:  Maksim1744
    created: 13.08.2020 03:00:30
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

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> pts(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (auto c : s) {
            if (c == 'B') ++pts[i].first;
            else ++pts[i].second;
        }
    }
    int minx = inf;
    int maxx = -inf;
    int miny = inf;
    int maxy = -inf;
    int mind = inf;
    int maxd = -inf;
    for (auto [x, y] : pts) {
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
        mind = min(mind, x - y);
        maxd = max(maxd, x - y);
    }

    auto dist = [&](pair<int, int> a, pair<int, int> b) {
        int x = b.first - a.first;
        int y = b.second - a.second;
        if (x <= 0 && y <= 0) return max(abs(x), abs(y));
        else if (x >= 0 && y >= 0) return max(x, y);
        else return abs(x) + abs(y);
    };

    auto doit = [&](int c) {
        pair<bool, pair<int, int>> res = {false, {-1, -1}};
        vector<pair<int, int>> check;

        vector<int> posx = {minx + c, maxx - c, mind + miny, mind + maxy, maxd + miny, maxd + maxy};
        vector<int> posy = {miny + c, maxy - c, minx - mind, maxx - mind, minx - maxd, maxx - maxd};

        for (auto x : posx) {
            if (x < 0) x = 0;
            for (auto y : posy) {
                if (y < 0) y = 0;
                check.eb(x, y);
            }
        }
        check.eb(0, 1);
        check.eb(1, 0);
        sort(check.begin(), check.end());
        check.erase(unique(check.begin(), check.end()), check.end());

        for (auto [xc, yc] : check) {
            if (xc == 0 && yc == 0) continue;
            bool ok = true;
            for (auto [x, y] : pts) {
                if (dist({xc, yc}, {x, y}) > c) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return mp(true, mp(xc, yc));
            }
        }
        return res;
    };

    int l = -1, r = inf;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (doit(c).first) {
            r = c;
        } else {
            l = c;
        }
    }

    auto res = doit(r).second;
    cout << r << '\n';
    cout << string(res.first, 'B') + string(res.second, 'N') << '\n';

    return 0;
}
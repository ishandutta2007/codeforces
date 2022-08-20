/*
    author:  Maksim1744
    created: 24.11.2019 12:42:30
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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<string> ans(n + 1, string(n, '0'));
    vector<vector<int>> groups(1);
    for (int i = 0; i < n + 1; ++i) {
        groups[0].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> szs;
        for (int j = 0; j < groups.size(); ++j) {
            szs.pb(groups[j].size());
        }
        int l = 0, r = n + 10;
        while (r - l > 1) {
            int c = (l + r) / 2;
            bool ok = true;
            int ul = 0, ur = 0;
            for (auto u : szs) {
                if (u <= c) {
                    ur += u;
                    continue;
                }
                if (u > c * 2) {
                    ok = false;
                    break;
                }
                ul += u - c;
                ur += c;
            }
            if (ul <= a[i] && a[i] <= ur) {
            } else {
                ok = false;
            }
            if (ok) {
                r = c;
            } else {
                l = c;
            }
        }
        show(groups, a[i], r);
        vector<int> where(groups.size(), 0);
        vector<int> can(groups.size(), 0);
        int left = a[i];
        for (int i = 0; i < groups.size(); ++i) {
            if (groups[i].size() > r) {
                where[i] += (int)groups[i].size() - r;
                left -= (int)groups[i].size() - r;
                can[i] = r;
            } else {
                can[i] = groups[i].size();
            }
        }
        assert(left >= 0);
        show(where);
        for (int i = 0; i < groups.size(); ++i) {
            if (left == 0)
                break;
            int to_add = can[i] - where[i];
            if (true) {
                to_add = groups[i].size() - where[i];
                to_add /= 2;
            }
            if (to_add > left)
                to_add = left;
            where[i] += to_add;
            left -= to_add;
        }
        reverse(groups.begin(), groups.end());
        reverse(where.begin(), where.end());
        reverse(can.begin(), can.end());
        show(where);
        for (int i = 0; i < groups.size(); ++i) {
            if (left == 0)
                break;
            int to_add = can[i] - where[i];
            if (to_add > left)
                to_add = left;
            where[i] += to_add;
            left -= to_add;
        }
        show(where);
        assert(left == 0);
        int y = groups.size();
        for (int j = 0; j < y; ++j) {
            if (where[j] == 0)
                continue;
            if (where[j] == groups[j].size()) {
                for (auto k : groups[j]) {
                    ans[k][i] = '1';
                }
                continue;
            }
            groups.eb();
            for (int u = 0; u < where[j]; ++u) {
                ans[groups[j].back()][i] = '1';
                groups.back().pb(groups[j].back());
                groups[j].pop_back();
            }
        }
        sort(groups.begin(), groups.end(), [&](vector<int>& a, vector<int>& b) {
            return a.size() > b.size();
        });
    }
    cout << n + 1 << '\n';
    for (auto s : ans) {
        cout << s << '\n';
    }
    return 0;
}
/*
    author:  Maksim1744
    created: 06.11.2019 19:04:16
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
const int K = 4;
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
const int K = 15;
#endif

array<array<bool, 1 << K>, K> dp;

int main() {
    int k;
    cin >> k;
    vector<vector<int>> v(k);
    map<int, int> where;
    vector<ll> sms(k, 0);
    ll need = 0;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        v[i].resize(n);
        cin >> v[i];
        for (auto u : v[i]) {
            where[u] = i;
            sms[i] += u;
            need += u;
        }
    }
    if (need % k != 0) {
        cout << "No\n";
        return 0;
    }
    need /= k;
    // show(need);
    vector<map<int, pair<int, int>>> from(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            int next = need - (sms[i] - v[i][j]);
            // show(v[i][j], next);
            if (where.count(next)) {
                from[i][v[i][j]] = mp(next, where[next]);
            } else {
                from[i][v[i][j]] = mp(0, -1);
            }
        }
    }
    // show(from);
    set<int> used;
    vector<pair<int, int>> sth;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            int start = v[i][j];
            if (used.count(start))
                continue;
            int start_i = i;
            int now = start;
            int visited = 1 << i;
            bool ok = true;
            vector<int> was = {start};
            while (true) {
                auto [next, next_i] = from[start_i][start];
                if (next_i == -1) {
                    ok = false;
                    break;
                }
                if (visited & (1 << next_i)) {
                    if (next != now) {
                        ok = false;
                    }
                    break;
                }
                visited |= (1 << next_i);
                start = next;
                start_i = next_i;
                if (used.count(start)) {
                    ok = false;
                    break;
                }
                was.pb(start);
            }
            if (ok) {
                for (auto y : was) {
                    used.insert(y);
                }
                sth.eb(visited, now);
            }
        }
    }
    dp[0].fill(false);
    for (auto [mask, s] : sth) {
        dp[0][mask] = true;
    }
    dp[0][0] = true;
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            int mask = j;
            int submask = mask;
            if (j == 0) {
                dp[i][mask] = true;
            } else {
                dp[i][mask] = false;
            }
            while (submask != 0) {
                if (dp[i - 1][submask] && dp[i - 1][mask ^ submask]) {
                    dp[i][mask] = true;
                    break;
                }
                submask = (submask - 1) & mask;
            }
        }
    }
    if (!dp[k - 1][(1 << k) - 1]) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    vector<int> masks = {(1 << k) - 1};
    for (int i = k - 1; i > 0; --i) {
        vector<int> new_masks;
        for (auto mask : masks) {
            int submask = mask;
            while (submask != 0) {
                if (dp[i - 1][submask] && dp[i - 1][mask ^ submask]) {
                    if (submask)
                        new_masks.pb(submask);
                    if (mask ^ submask)
                        new_masks.pb(mask ^ submask);
                    break;
                }
                submask = (submask - 1) & mask;
            }
        }
        swap(new_masks, masks);
    }
    sort(sth.begin(), sth.end());
    show(masks);
    vector<int> starts;
    vector<pair<pair<int, int>, int>> ans;
    for (auto mask : masks) {
        auto it = lower_bound(sth.begin(), sth.end(), mp(mask, (int)(-1e9-10)));
        assert(it->first == mask);
        int start = it->second;
        int now = start;
        int now_i = where[start];
        int visited = 1 << now_i;
        vector<pair<int, int>> path;
        path.eb(now_i, now);
        while (true) {
            auto [next, next_i] = from[now_i][now];
            if (visited & (1 << next_i)) {
                break;
            }
            now = next;
            now_i = next_i;
            path.eb(now_i, now);
            visited |= 1 << next_i;
        }
        for (int i = 0; i < path.size(); ++i) {
            ans.eb(path[i], path[(i - 1 + path.size()) % path.size()].first);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto [p, y] : ans) {
        cout << p.second << ' ' << y + 1 << endl;
    }
    return 0;
}
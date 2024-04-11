/*
    author:  Maksim1744
    created: 01.11.2020 17:50:30
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

auto start_time = clock();

int a[3005][3005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> sz(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < t; ++j) {
            int u;
            cin >> u;
            if (j <= k) a[i][j] = u;
        }
        sz[i] = min(k, t);
    }

    // cerr << (double)(clock() - start_time) / CLOCKS_PER_SEC << endl;
    vector<vector<ll>> pref(n);
    for (int i = 0; i < n; ++i) {
        pref[i].reserve(sz[i]);
        pref[i].pb(a[i][0]);
        for (int j = 1; j < sz[i]; ++j) {
            pref[i].pb(pref[i].back() + a[i][j]);
        }
    }

    // cerr << (double)(clock() - start_time) / CLOCKS_PER_SEC << endl;

    vector<vector<ll>> pos(n, vector<ll>(k + 1));

    vector<pair<ll, int>> v;
    v.reserve(n + k);
    for (int ln = 1; ln <= k; ++ln) {
        v.clear();
        for (int i = 0; i < n; ++i) {
            if (pref[i].size() >= ln)
                v.eb(pref[i][ln - 1], i);
        }
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < v.size(); ++i) {
            pos[v[i].second][ln] = i;
        }
    }

    // cerr << (double)(clock() - start_time) / CLOCKS_PER_SEC << endl;

    vector<vector<ll>> only_full(n + 1, vector<ll>(k + 1, 0)), partial(n + 1, vector<ll>(k + 1, 0));
    for (int i = 0; i < n; ++i) {
        ll sm = pref[i].back();
        only_full[i + 1] = only_full[i];
        partial[i + 1] = partial[i];
        for (int j = k - (int)sz[i]; j >= 0; --j) {
            only_full[i + 1][j + sz[i]] = max(only_full[i + 1][j + sz[i]], only_full[i][j] + sm);
            partial[i + 1][j + sz[i]] = max(partial[i + 1][j + sz[i]], partial[i][j] + sm);
        }
        for (int ln = 1; ln <= sz[i]; ++ln) {
            int cbefore = pos[i][ln - 1] * ln;
            if (cbefore > k) continue;
            for (int j = 0; j + ln <= k; ++j)
                partial[i + 1][j + ln] = max(partial[i + 1][j + ln], only_full[i][j] + pref[i][ln - 1]);
        }
    }
    // shows;
    // printMatrix(only_full);
    // shows;
    // printMatrix(partial);
    // shows;
    cout << max(only_full[n][k], partial[n][k]) << '\n';

    // cerr << (double)(clock() - start_time) / CLOCKS_PER_SEC << endl;

    return 0;
}
/*
    author:  Maksim1744
    created: 26.04.2020 17:55:48
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

    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    vector<int> ms(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        --m;
        ms[i] = m;
        cnt[m]++;
    }
    sort(ms.begin(), ms.end());
    reverse(ms.begin(), ms.end());
    vector<int> c(k);
    cin >> c;
    int l = 0, r = n + 1;
    vector<vector<int>> v;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        v.assign(mid, vector<int>{});
        for (int i = 0; i < n; ++i) {
            v[i % mid].pb(ms[i]);
        }
        bool ok = true;
        for (int i = 0; i < mid; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                if (j + 1 > c[v[i][j]]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
    int mid = r;
    v.assign(mid, vector<int>{});
    for (int i = 0; i < n; ++i) {
        v[i % mid].pb(ms[i]);
    }
    for (int i = 0; i < r; ++i) {
        ++v[i];
        cout << v[i].size() << ' ';
        cout << v[i] << '\n';
    }
    
    return 0;
}
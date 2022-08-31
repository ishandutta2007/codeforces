/*
    author:  Maksim1744
    created: 23.02.2020 20:07:36
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

const ll inf = 1e12;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    cin >> mat;
    vector<vector<vector<pair<ll, int>>>> v(n, vector<vector<pair<ll, int>>>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i][j].eb(inf, -1);
            for (int k = 0; k < n; ++k) {
                if (i == k || j == k || k == 0) continue;
                v[i][j].eb(mat[i][k] + mat[k][j], k);
            }
            sort(v[i][j].begin(), v[i][j].end());
        }
    }
    int cnt = 1;
    k /= 2;
    for (int i = 0; i < k - 1; ++i) {
        cnt *= n;
    }
    vector<int> u(n, 0);
    int t = 1;
    ll ans = inf;
    vector<int> p(k, 0);
    p.back() = -1;
    for (int i = 0; i < cnt; ++i) {
        int ind = k - 1;
        ++p.back();
        while (p[ind] == n) {
            p[ind] = 0;
            --ind;
            ++p[ind];
        }
        ++t;
        for (auto y : p) {
            u[y] = t;
        }
        ll res = 0;
        for (int j = 0; j < k; ++j) {
            int x = p[j];
            int y = p[(j + 1) % k];
            int ind = 0;
            while (u[v[x][y][ind].second] == t)
                ++ind;
            res += v[x][y][ind].first;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;

    return 0;
}
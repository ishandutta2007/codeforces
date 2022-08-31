/*
    author:  Maksim1744
    created: 24.05.2021 18:12:12
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

    int n, m;
    cin >> n >> m;
    const int inf = 1e9 + 100000;
    vector<vector<int>> to0(n, vector<int>(n, inf));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        to0[a][b] = c;
    }
    vector<int> to(n, inf);
    for (int v0 = 0; v0 < n; ++v0) {
        vector<int> ans(n, inf);
        ans[v0] = 0;
        vector<bool> u(n, false);
        for (int i = 0; i < n; ++i) {
            int ind = -1;
            for (int j = 0; j < n; ++j) {
                if (!u[j] && (ind == -1 || ans[j] < ans[ind]))
                    ind = j;
            }
            u[ind] = true;
            int v = ind;
            int cur = inf;
            for (int j = 0; j < n; ++j) {
                to[(j + ans[v]) % n] = to0[v][j];
            }
            for (int u = 0; u < n; ++u) {
                cur = min(cur + 1, to[u]);
                umin(ans[u], ans[v] + cur);
            }
            cur = inf + n;
            for (int u = n - 1; u >= 0; --u) {
                umin(ans[u], ans[v] + cur);
                cur = min(cur - 1, to[u] + n - 1);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
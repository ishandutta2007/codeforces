/*
    author:  Maksim1744
    created: 10.07.2021 17:40:43
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

void test_case(int test) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    cin >> a >> b;
    vector<vector<bool>> can(n + 1, vector<bool>(m + 1, false));
    vector<vector<pair<int, int>>> from(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    can[0][0] = true;
    vector<vector<int>> bal(n + 1, vector<int>(m + 1, 0));
    bal[0][0] = k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                bal[i][j] = bal[i][j - 1] + (b[j - 1] == 0 ? +1 : 0);
            } else {
                bal[i][j] = bal[i - 1][j] + (a[i - 1] == 0 ? +1 : 0);
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (!can[i][j]) continue;
            if (i != n)
            if (a[i] == 0 || a[i] <= bal[i][j]) {
                can[i + 1][j] = true;
                from[i + 1][j] = {i, j};
            }
            if (j != m)
            if (b[j] == 0 || b[j] <= bal[i][j]) {
                can[i][j + 1] = true;
                from[i][j + 1] = {i, j};
            }
        }
    }

    show(can);
    show(bal);
    show(from);

    if (!can[n][m]) {
        cout << -1 << '\n';
        return;
    }

    pair<int, int> cur = {n, m};
    vector<int> ans;
    while (ans.size() != n + m) {
        if (from[cur.first][cur.second].first == cur.first) {
            ans.pb(b[--cur.second]);
        } else {
            ans.pb(a[--cur.first]);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}
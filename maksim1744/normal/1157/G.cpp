/*
    author:  Maksim1744
    created: 08.07.2021 21:10:44
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
    vector<vector<int>> v(n, vector<int>(m));
    cin >> v;

    vector<int> hr(n, 0);
    vector<int> vr(m, 0);

    auto pr = [&]() {
        for (int k : hr)
            cout << k;
        cout << '\n';
        for (int k : vr)
            cout << k;
        cout << '\n';
    };

    if (n == 1) {
        cout << "YES\n";
        for (int i = 0; i < m; ++i) {
            if (v[0][i] == 1)
                vr[i] ^= 1;
        }
        pr();
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        if (v[0][i] == 1) {
            vr[i] ^= 1;
            for (int j = 0; j < n; ++j)
                v[j][i] ^= 1;
        }
    }

    {
        for (int i = 0; i < n; ++i) {
            int k = count(v[i].begin(), v[i].end(), 0);
            if (k == m) continue;
            if (k == 0) {
                hr[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    v[i][j] ^= 1;
                }
                continue;
            }
            if (v[i][0] == 1) {
                hr[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    v[i][j] ^= 1;
                }
            }
            break;
        }
        for (int i = n - 1; i >= 0; --i) {
            int k = count(v[i].begin(), v[i].end(), 1);
            if (k == m) continue;
            if (k == 0) {
                hr[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    v[i][j] ^= 1;
                }
                continue;
            }
            break;
        }

        vector<int> a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a.pb(v[i][j]);
            }
        }
        if (is_sorted(a.begin(), a.end())) {
            cout << "YES\n";
            pr();
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (v.back()[i] == 0) {
            vr[i] ^= 1;
            for (int j = 0; j < n; ++j)
                v[j][i] ^= 1;
        }
    }

    {
        for (int i = 0; i < n; ++i) {
            int k = count(v[i].begin(), v[i].end(), 0);
            if (k == m) continue;
            if (k == 0) {
                hr[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    v[i][j] ^= 1;
                }
                continue;
            }
            if (v[i][0] == 1) {
                hr[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    v[i][j] ^= 1;
                }
            }
            break;
        }
        for (int i = n - 1; i >= 0; --i) {
            int k = count(v[i].begin(), v[i].end(), 1);
            if (k == m) continue;
            if (k == 0) {
                hr[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    v[i][j] ^= 1;
                }
                continue;
            }
            break;
        }

        vector<int> a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a.pb(v[i][j]);
            }
        }
        if (is_sorted(a.begin(), a.end())) {
            cout << "YES\n";
            pr();
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
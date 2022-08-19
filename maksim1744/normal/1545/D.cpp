/*
    author:  Maksim1744
    created: 11.07.2021 18:23:25
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

    int m, k;
    cin >> m >> k;
    vector<vector<int>> xs(k, vector<int>(m));
    cin >> xs;

    int bad = -1;
    int sv = 0;
    {
        map<int, vector<int>> mm;
        vector<int> sms;
        for (int i = 0; i + 1 < k; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                s += xs[i + 1][j] - xs[i][j];
            }
            sms.pb(s);
            mm[s].pb(i);
        }
        vector<int> bd;
        for (auto [a, v] : mm) {
            if (v.size() <= 2) {
                for (int k : v)
                    bd.pb(k);
            } else {
                sv = a;
            }
        }
        if (bd.size() == 1) {
            assert(bd[0] == 0 || bd[0] == k - 2);
            if (bd[0] == 0)
                bad = 0;
            else
                bad = k - 1;
        } else {
            assert(bd.size() == 2);
            sort(bd.begin(), bd.end());
            bad = bd[1];
        }
    }

    {
        ll sx = sum(xs[0]);
        if (bad == 0)
            sx = sum(xs[1]) - sv;
        int a = 0;
        while (a == bad) ++a;
        int b = a + 1;
        while (b == bad) ++b;
        int c = b + 1;
        while (c == bad) ++c;
        vector<vector<ll>> mat(3, vector<ll>(4, 0));
        vector<int> vv = {a, b, c};
        for (int i = 0; i < 3; ++i) {
            mat[i][0] = 1;
            mat[i][1] = vv[i];
            mat[i][2] = vv[i] * vv[i];
            for (int j = 0; j < m; ++j) {
                mat[i][3] += (ll)xs[vv[i]][j] * xs[vv[i]][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (mat[i][i] == 0)
                swap(mat[i][i], mat[i + 1][i]);
            assert(mat[i][i] != 0);
            for (int j = i + 1; j < 3; ++j) {
                ll lc = lcm(mat[j][i], mat[i][i]);
                ll k1 = lc / mat[j][i];
                ll k2 = lc / mat[i][i];
                for (int k = 0; k < 4; ++k)
                    mat[j][k] = mat[j][k] * k1 - k2 * mat[i][k];
                assert(mat[j][i] == 0);
            }
        }
        for (int i = 2; i >= 0; --i) {
            assert(mat[i].back() % mat[i][i] == 0);
            mat[i].back() /= mat[i][i];
            mat[i][i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                mat[j].back() -= mat[j][i] * mat[i].back();
                mat[j][i] = 0;
            }
        }
        ll dx = sum(xs[bad]) - (sx + sv * bad);
        ll need = (ll)bad * bad * mat[2].back() + (ll)bad * mat[1].back() + (ll)mat[0].back();
        for (int i = 0; i < m; ++i) {
            xs[bad][i] -= dx;
            ll have = 0;
            for (ll u : xs[bad])
                have += u * u;
            if (have == need) {
                cout << bad << ' ' << xs[bad][i] << '\n';
                exit(0);
            }

            xs[bad][i] += dx;
        }
    }
    return 0;
}
/*
    author:  Maksim1744
    created: 09.06.2021 13:46:10
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

const int N = 3005;
// const int N = 100;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> cur(n);
    for (int i = 0; i < n; ++i) {
        cur[i][0] = i * 3;
        cur[i][1] = i * 3 + 1;
        cur[i][2] = i * 3 + 2;
    }
    // RYB

    vector<bitset<N>> mt;

    for (int i = 0; i < n; ++i) {
        bitset<N> b;
        b[i * 3 + 0] = 1;
        b[i * 3 + 1] = 1;
        b[i * 3 + 2] = 1;
        mt.pb(b);
    }

    while (k--) {
        string s;
        cin >> s;
        int sz;
        cin >> sz;
        vector<int> v(sz);
        cin >> v;
        --v;
        if (s == "mix") {
            char c;
            cin >> c;
            array<bitset<N>, 3> a;
            a[0][n * 3] = 1;
            a[1][n * 3] = 1;
            a[2][n * 3] = 1;
            if (c == 'R')
                a[0][n * 3] = 0;
            else if (c == 'Y')
                a[1][n * 3] = 0;
            else if (c == 'B')
                a[2][n * 3] = 0;
            else if (c == 'W')
                a[0][n * 3] = a[1][n * 3] = a[2][n * 3] = 0;
            else
                assert(false);
            for (int i : v)
                for (int j = 0; j < 3; ++j)
                    a[j][cur[i][j]] = 1;
            for (auto b : a)
                mt.pb(b);
        } else if (s == "RY") {
            for (int i : v)
                swap(cur[i][0], cur[i][1]);
        } else if (s == "RB") {
            for (int i : v)
                swap(cur[i][0], cur[i][2]);
        } else if (s == "YB") {
            for (int i : v)
                swap(cur[i][1], cur[i][2]);
        } else {
            assert(false);
        }
    }
    show(mt);
    int last = 0;
    for (int i = 0; i < n * 3; ++i) {
        if (last == mt.size()) break;
        if (mt[last][i] == 0) {
            for (int j = last + 1; j < mt.size(); ++j) {
                if (mt[j][i] == 1) {
                    mt[last] ^= mt[j];
                    break;
                }
            }
        }
        if (mt[last][i] == 0) continue;
        for (int j = last + 1; j < mt.size(); ++j) {
            if (mt[j][i])
                mt[j] ^= mt[last];
        }
        ++last;
    }

    show(mt);

    for (int j = last; j < mt.size(); ++j) {
        if (mt[j][n * 3]) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<int> val(n * 3);
    for (int i = last - 1; i >= 0; --i) {
        int i0 = 0;
        while (mt[i][i0] == 0)
            ++i0;
        assert(i0 != n * 3);
        int res = mt[i][n * 3];
        for (int j = i0 + 1; j < n * 3; ++j)
            if (mt[i][j])
                res ^= val[j];
        val[i0] = res;
    }

    for (int i = 0; i < mt.size(); ++i) {
        int res = 0;
        for (int j = 0; j < n * 3; ++j)
            if (mt[i][j])
                res ^= val[j];
        assert(res == mt[i][n * 3]);
    }

    string ans;
    for (int i = 0; i < n; ++i) {
        string tmp;
        tmp.pb('0' + val[i * 3]);
        tmp.pb('0' + val[i * 3 + 1]);
        tmp.pb('0' + val[i * 3 + 2]);
        if (tmp == "000")
            ans.pb('.');
        else if (tmp == "011")
            ans.pb('R');
        else if (tmp == "101")
            ans.pb('Y');
        else if (tmp == "110")
            ans.pb('B');
        else
            assert(false);
        show(tmp);
    }

    cout << "YES\n";
    cout << ans << '\n';

    return 0;
}
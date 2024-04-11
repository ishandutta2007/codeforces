/*
    author:  Maksim1744
    created: 22.07.2019 18:51:19
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

const int N = 64;
const ll mod = 998244353;
const ll mod2 = mod * mod;

struct Mat {
    array<array<ll, N>, N> data;

    Mat(int k = 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                data[i][j] = 0;
            }
        }
        for (int i = 0; i < N; ++i) {
            data[i][i] = k;
        }
    }

    auto& operator[] (int i) const {
        return data[i];
    }

    auto& operator[] (int i) {
        return data[i];
    }

    Mat operator * (const Mat& other) const {
        Mat res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    res[i][j] += data[i][k] * other[k][j];
                    if (res[i][j] >= mod2)
                        res[i][j] -= mod2;
                    // assert(res[i][j] >= 0);
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (res[i][j] >= mod)
                    res[i][j] %= mod;
            }
        }
        return res;
    }

    array<ll, N> operator * (const array<ll, N>& other) {
        array<ll, N> res;
        res.fill(0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res[i] += data[i][j] * other[j];
                if (res[i] >= mod2)
                    res[i] -= mod2;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (res[i] >= mod)
                res[i] %= mod;
        }
        return res;
    }
};
Mat def;
array<Mat, 35> p2;

void mult(array<ll, N>& vect, long long p) {
    assert(p >= 0);
    if (p == 0)
        return;
    int ind = 0;
    while (p) {
        if (p & 1) vect = p2[ind] * vect;
        ++ind;
        p >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<Mat> known(3);
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    int m;
    cin >> m;
    vector<vector<pair<ll, int>>> col(n);
    for (int i = 0; i < m; ++i) {
        ll x, y, c;
        cin >> x >> y >> c;
        --x;
        --c;
        col[x].eb(y, c);
    }
    for (int i = 0; i < n; ++i) {
        col[i].eb(0, 0);
        sort(col[i].begin(), col[i].end());
    }
    vector<vector<int>> f(3, vector<int>(3));
    cin >> f;
    vector<int> prev;
    vector<bool> s(4, false);
    for (int i = 0; i < 64; ++i) {
        prev.clear();
        int x = i;
        for (int j = 0; j < 3; ++j) {
            prev.pb(x % 4);
            x /= 4;
        }
        reverse(prev.begin(), prev.end());
        for (int j = 0; j < 3; ++j) {
            s.assign(4, false);
            for (int k = 0; k < 3; ++k) {
                if (f[j][k])
                    s[prev[2 - k]] = true;
            }
            int mx = 0;
            while (s[mx])
                ++mx;
            // showt(i, prev, j, f[j], mx);
            // assert(0 <= mx && mx <= 3);
            int i2 = prev[1] * 16 + prev[2] * 4 + mx;
            def[i2][i]++;
            known[j][i2][i]++;
        }
    }
    p2[0] = def;
    for (int i = 1; i < p2.size(); ++i)
        p2[i] = p2[i - 1] * p2[i - 1];
    vector<vector<ll>> res(n, vector<ll>(4, 0));
    show(col[0]);
    for (int i = 0; i < n; ++i) {
        array<ll, N> vect;
        vect.fill(0);
        vect[N - 1] = 1;
        for (int j = 1; j < col[i].size(); ++j) {
            mult(vect, col[i][j].first - col[i][j - 1].first - 1);
            vect = known[col[i][j].second] * vect;
        }
        mult(vect, a[i] - col[i].back().first);
        for (int j = 0; j < 64; ++j) {
            res[i][j % 4] += vect[j];
        }
        for (int j = 0; j < 4; ++j) {
            res[i][j] %= mod;
        }
    }
    show(res);
    vector<ll> gl(4, 0);
    gl[0] = 1;
    vector<ll> gl1(4, 0);
    for (auto& a : res) {
        gl1.assign(4, 0);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                gl1[i ^ j] += gl[i] * a[j] % mod;
            }
        }
        for (int i = 0; i < 4; ++i) {
            gl1[i] %= mod;
        }
        swap(gl, gl1);
    }
    cout << gl[0] << '\n';
    return 0;
}
/*
    author:  Maksim1744
    created: 18.08.2019 17:21:27
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int n;
vector<vector<int>> m;

bool ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    int res;
    cin >> res;
    assert(res != -1);
    return res;
}
void out() {
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j];
            assert(m[i][j] == 0 || m[i][j] == 1);
        }
        cout << endl;
    }
};

int main() {
    cin >> n;
    m.assign(n, vector<int>(n, 5));
    m[0][0] = 1;
    m[n - 1][n - 1] = 0;
    for (int i = 2; i < n; i += 2) {
        if (ask(0, i - 2, 0, i)) {
            m[0][i] = m[0][i - 2];
        } else {
            m[0][i] = 1 - m[0][i - 2];
        }
    }
    for (int i = 2; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            if (i == n - 1 && j == n - 1) 
                continue;
            if (ask(i - 2, j, i, j)) {
                m[i][j] = m[i - 2][j];
            } else {
                m[i][j] = 1 - m[i - 2][j];
            }
        }
    }
    for (int i = 1; i < n; i += 2) {
        for (int j = 1; j < n; j += 2) {
            if (ask(i - 1, j - 1, i, j)) {
                m[i][j] = m[i - 1][j - 1];
            } else {
                m[i][j] = 1 - m[i - 1][j - 1];
            }
        }
    }
    // printMatrix(m);
    m[0][1] = 1;
    for (int i = 3; i < n; i += 2) {
        if (ask(0, i - 2, 0, i)) {
            m[0][i] = m[0][i - 2];
        } else {
            m[0][i] = 1 - m[0][i - 2];
        }
    }
    // printMatrix(m);
    for (int i = 2; i < n; i += 2) {
        for (int j = 1; j < n; j += 2) {
            if (i == n - 1 && j == n - 1) 
                continue;
            if (ask(i - 2, j, i, j)) {
                m[i][j] = m[i - 2][j];
            } else {
                m[i][j] = 1 - m[i - 2][j];
            }
        }
    }
    // printMatrix(m);
    // printMatrix(m);
    if (ask(1, 0, 2, 1)) {
        m[1][0] = m[2][1];
    } else {
        m[1][0] = 1 - m[2][1];
    }
    // printMatrix(m);
    for (int i = 2; i < n; i += 2) {
        if (ask(1, i - 2, 1, i)) {
            m[1][i] = m[1][i - 2];
        } else {
            m[1][i] = 1 - m[1][i - 2];
        }
    }
    // printMatrix(m);
    for (int i = 3; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            if (i == n - 1 && j == n - 1) 
                continue;
            if (ask(i - 2, j, i, j)) {
                m[i][j] = m[i - 2][j];
            } else {
                m[i][j] = 1 - m[i - 2][j];
            }
        }
    }
    auto change = [&]() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2 == 1) {
                    m[i][j] = 1 - m[i][j];
                }
            }
        }
    };
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (m[i][j - 1] != m[i - 1][j]) {
                if (j != 1) {
                    bool ans = ask(i - 1, j - 2, i, j);
                    if (ans) {
                        if (m[i - 1][j - 2] != m[i][j])
                            change();
                    } else {
                        if (m[i - 1][j - 2] == m[i][j])
                            change();
                    }
                } else {
                    bool ans = ask(i - 1, j - 1, i, j + 1);
                    if (ans) {
                        if (m[i - 1][j - 1] != m[i][j + 1])
                            change();
                    } else {
                        if (m[i - 1][j - 1] == m[i][j + 1])
                            change();
                    }
                }
                out();
                return 0;
            }
        }
    }
    vector<int> v1(n * 2 - 1), v2(n * 2 - 1);
    vector<pair<int, int>> co(n * 2 - 1);
    for (int i = 0; i < n; ++i) {
        v1[i * 2] = m[i][i];
        v2[i * 2] = m[i][i];
        co[i * 2] = mp(i, i);
    }
    for (int i = 0; i < n - 1; ++i) {
        v1[i * 2 + 1] = m[i][i + 1];
        v2[i * 2 + 1] = 1 - m[i][i + 1];
        co[i * 2 + 1] = mp(i, i + 1);
    }
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = i + 2; j < v1.size(); ++j) {
            bool b1 = true, b2 = true;
            for (int k = 0; k < j - i + 1; ++k) {
                if (v1[i + k] != v1[j - k]) {
                    b1 = false;
                    break;
                }
            }
            for (int k = 0; k < j - i + 1; ++k) {
                if (v2[i + k] != v2[j - k]) {
                    b2 = false;
                    break;
                }
            }
            if (b1 != b2) {
                bool b = ask(co[i].first, co[i].second, co[j].first, co[j].second);
                if (b != b1)
                    change();
                out();
                return 0;
            }
        }
    }
    assert(false);
    return 0;
}
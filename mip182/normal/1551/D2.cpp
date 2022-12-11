#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i : v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i : v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v) os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }

template<typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 1;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    bool ok = false;
    if (n % 2 == 1) {
        swap(n, m);
        k = n * m / 2 - k;
        ok = true;
    }
    vector<vector<int>> ans(n, vi(m, -1));
//    cout << n << " " << m << " " << k << '\n';
    int cur = 0;
    if (m % 2 == 0) {
        if (k % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i + 1 < m; i += 2) {
                for (int j = 0; j + 1 < n; j += 2) {
                    if (k == 0)
                        break;
                    ans[j][i] = cur;
                    ans[j][i + 1] = cur++;
                    ans[j + 1][i] = cur;
                    ans[j + 1][i + 1] = cur++;
                    k -= 2;
                }
            }
            for (int j = 0; j < m; j++) {
                for (int i = 0; i + 1 < n; i++) {
                    if (ans[i][j] != -1)
                        continue;
                    ans[i][j] = cur;
                    ans[i + 1][j] = cur++;
                }
            }
        } else {
            cout << "NO\n";
            return;
        }
    } else {
        int prod = n * (m - 1);
        if (k % 2 == 0 && k <= prod / 2) {
            cout << "YES\n";
            for (int i = 0; i + 1 < m; i += 2) {
                for (int j = 0; j + 1 < n; j += 2) {
                    if (k == 0)
                        break;
                    ans[j][i] = cur;
                    ans[j][i + 1] = cur++;
                    ans[j + 1][i] = cur;
                    ans[j + 1][i + 1] = cur++;
                    k -= 2;
                }
            }
            for (int j = 0; j < m; j++) {
                for (int i = 0; i + 1 < n; i++) {
                    if (ans[i][j] != -1)
                        continue;
                    ans[i][j] = cur;
                    ans[i + 1][j] = cur++;
                }
            }
        } else {
            cout << "NO\n";
            return;
        }
    }
    if (ok) {
        vector<vector<int>> anss(m, vi(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                anss[j][i] = ans[i][j];
        }
        swap(ans, anss);
    }
    n = ans.size();
    m = ans[0].size();
//    for (int i = 0; i < n; i++) {
//        cout << ans[i] << '\n';
//    }
    vector<vector<int>> anss(n, vector<int>(m, -1));
    vector<int> xx = {1, -1, 0, 0};
    vector<int> yy = {0, 0, 1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (anss[i][j] != -1)
                continue;
            int xes = -1, yes = -1;
            vector<bool> can(26, true);
            for (int f = 0; f < 4; f++) {
                int x = i + xx[f];
                int y = j + yy[f];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (ans[x][y] == ans[i][j]) {
                        xes = x;
                        yes = y;
                    } else if (anss[x][y] != -1) {
                        can[anss[x][y]] = false;
                    }
                }
            }
            assert(xes != -1);
            for (int f = 0; f < 4; f++) {
                int x = xes + xx[f];
                int y = yes + yy[f];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (ans[x][y] == ans[i][j]) {
                    } else if (anss[x][y] != -1) {
                        can[anss[x][y]] = false;
                    }
                }
            }
            int ind = 0;
            while (!can[ind])
                ind++;
            anss[i][j] = ind;
            anss[xes][yes] = ind;
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto to:anss[i])
            cout << (char) (to + 'a');
        cout << '\n';
    }
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}
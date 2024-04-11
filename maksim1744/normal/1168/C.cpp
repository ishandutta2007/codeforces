/*
    author:  Maksim1744
    created: 26.06.2019 22:10:04
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

#ifdef HOMEn
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int nax = 10;
const int kx = 5;
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
const int nax = 300005;
const int kx = 19;
#endif

array<array<int, kx>, nax> near;
array<array<int, kx>, nax> bn;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < kx; ++j) {
            bn[i][j] = ((a[i] >> j) & 1);
        }
    }
    show(bn);
    vector<int> last(kx, n);
    for (int i = 0; i < kx; ++i) {
        near[n][i] = n;
        bn[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        showt(i, last);
        for (int j = 0; j < kx; ++j) {
            near[i][j] = n;
        }
        for (int j = 0; j < kx; ++j) {
            if (bn[i][j]) {
                near[i][j] = min(near[i][j], i);
                for (int k = 0; k < kx; ++k) {
                    near[i][k] = min(near[i][k], near[last[j]][k]);
                }
            }
        }
        for (int j = 0; j < kx; ++j) {
            if (bn[i][j]) {
                last[j] = i;
            }
        }
    }
    show(near);
    for (int iii = 0; iii < q; ++iii) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        bool ok = false;
        for (int i = 0; i < kx; ++i) {
            if (bn[y][i] && near[x][i] <= y) {
                ok = true;
                break;
            }
        }
        if (ok)
            cout << "Shi\n";
        else
            cout << "Fou\n";
    }
    return 0;
}
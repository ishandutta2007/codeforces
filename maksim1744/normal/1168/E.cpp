/*
    author:  Maksim1744
    created: 26.06.2019 22:37:43
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

int main() {
    int k;
    cin >> k;
    int n = 1 << k;
    vector<int> a(n);
    cin >> a;
    vector<int> p, q;
    vector<int> ind;
    int u = 0;
    for (int i = 0; i < n; ++i) {
        u ^= a[i];
        p.pb(i);
        q.pb(i);
        ind.pb(i);
    }
    if (u != 0) {
        cout << "Fou\n";
        return 0;
    }
    cout << "Shi\n";
    vector<int> b(n, 0);
    function<void(int, int)> fix = [&](int i, int j) {
        show(i, j, p, q, b);
        if (b[i] == (p[i] ^ q[i])) {
            return;
        }
        if (b[i] == (p[i] ^ q[j])) {
            swap(q[i], q[j]);
            return;
        }
        if (b[i] == (p[j] ^ q[i])) {
            swap(ind[p[i]], ind[p[j]]);
            swap(p[i], p[j]);
            return;
        }
        if (b[i] == (p[j] ^ q[j])) {
            swap(q[i], q[j]);
            swap(p[i], p[j]);
            swap(ind[p[i]], ind[p[j]]);
            return;
        }
        int t = ind[b[i] ^ q[i]];
        swap(ind[p[i]], ind[p[t]]);
        swap(p[i], p[t]);
        swap(q[t], q[j]);
        fix(t, j);
    };
    for (int i = 0; i < n - 1; ++i) {
        showl;
        int d = (a[i] ^ b[i]);
        b[i] ^= d;
        b[i + 1] ^= d;
        fix(i, i + 1);
    }
    cout << p << '\n';
    cout << q << '\n';
    return 0;
}
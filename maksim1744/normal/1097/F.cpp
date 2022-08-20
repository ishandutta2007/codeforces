/*
    author:  Maksim1744
    created: 02.05.2019 00:10:31
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int N = 20;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int N = 7005;
#endif

using SET = bitset<N>;

bool check(int n) {
    int p = 2;
    while (p * p <= n) {
        if (n % p == 0) {
            n /= p;
            if (n % p == 0)
                return false;
        }
        ++p;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<SET> d(N, 0);
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            if (check(j / i))
                d[i][j] = 1;
    vector<SET> g(N, 0);
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            g[j][i] = 1;
    vector<SET> id(N, 0);
    for (int i = 0; i < N; ++i)
        id[i][i] = 1;
    // show(g);
    int n, q;
    cin >> n >> q;
    vector<SET> v(n + 1, 0);
    for (int i = 0; i < q; ++i) {
        #ifdef TAG_LENGTH
        // cout << '\n';
        // for (int j = 1; j <= n; ++j) {
        //     cout << j << ": " << to_string(v[j]) << '\n';
        // }
        // cout << '\n';
        #endif
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            v[x] = g[y];
        } else if (t == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x] = v[y] ^ v[z];
        } else if (t == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x] = v[y] & v[z];
        } else if (t == 4) {
            int x, y;
            cin >> x >> y;
            cout << ((v[x] & (d[y])).count() & 1);
        }
    }
    return 0;
}
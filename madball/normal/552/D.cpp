// by ReTlaCe
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,fma,popcnt,tune=native")

#ifdef Debugg
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>
#include <complex>
#include <cstdio>
#include <deque>
#include <cmath>
#include <bitset>
#include <set>
#include <cassert>
#include <map>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define se second
#define fi first
#define forn(i,n) for(int i = 0; i < (n); i++)
#define read(a) for(int i = 0; i < a.size(); i++){cin >> a[i];}
#define all(a) a.begin(), a.end()
#define make_unique(a) sort(all(a)); a.resize(unique(a.begin(),a.end())-a.begin());
const int mod = 1e9 + 7;
#define int long long

using ld = long long;
struct Vec {
    ld x, y;
    Vec() {}

    Vec(ld x1, ld y1) {
        x = x1;
        y = y1;
    }
};

Vec operator+(Vec a, Vec b) {
    return Vec(a.x + b.x, a.y + b.y);
}

Vec operator-(Vec a, Vec b) {
    return Vec(a.x - b.x, a.y - b.y);
}

Vec operator*(Vec a, ld k) {
    return Vec(a.x * k, a.y * k);
}

Vec operator*(ld k, Vec a) {
    return Vec(a.x * k, a.y * k);
}

Vec operator/(Vec a, ld k) {
    return Vec(a.x / k, a.y / k);
}

bool operator==(Vec a, Vec b) {
    return (a.x == b.x) && (a.y == b.y);
}

ld scal(Vec a, Vec b) {
    return a.x * b.x + b.y * a.y;
}

long double dist(Vec a) {
    return sqrtl((long double)a.x * a.x + (long double)a.y * a.y);
}

ld mul(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

istream& operator >>(istream& in, Vec& ve_) {
    in >> ve_.x >> ve_.y;
    return in;
}

int sign(ld a) {
    if (a == 0) return 0;
    if (a < 0) return -1;
    return 1;
}

int gcd(int a, int b) {
    return !a ? b : gcd(b % a, a);
}


bool pinseg(pair<double, double> p, Vec a, Vec b) {
    Vec bma = b - a;
    if (abs((p.first - a.x) * bma.y - (p.second - a.y) * bma.x) < 1e-8 && ((a.x - p.first) * (b.x - p.first) + (a.y - p.second) * (b.y - p.second)) <= 1e-8) {
        return true;
    }
    return false;
}

tuple<int, int, int> norm(int A, int B, int C) {
    if (A < 0) {
        A *= -1;
        B *= -1;
        C *= -1;
    }
    int g = gcd(gcd(A, B), C);
    A /= g;
    B /= g;
    C /= g;
    return {A, B, C};
}

void solve() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0;
        return;
    }
    map<tuple<int, int, int>, int> ma;
    set<tuple<int, int, int>> se;
    vector<Vec> a(n);
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        se.clear();
        for (int j = 0; j < i; ++j) {
            Vec po = a[j];
            Vec ij = a[j] - a[i];
            Vec vec = {-ij.y, ij.x};
            int A = vec.x;
            int B = vec.y;
            int C = -vec.x * po.x - vec.y * po.y;
            tuple<int, int, int> nor = norm(A, B, C);
            if (se.find(nor) == se.end()) {
                se.insert(nor);
                if (ma.find(nor) == ma.end()) {
                    ma[nor] = 2;
                } else {
                    ++ma[nor];
                }
            }
        }
    }
    for (auto i : ma) {
        int nw = i.second;
        ans -= nw * (nw - 1) * (nw - 2) / 6;
    }
    //x = n * (n - 1) / 2;
    //0 = n ^ 2 - n - 2x;

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef Debugg
    freopen(R"(C:\Users\ds\CLionProjects\untitled3\ain.txt)", "r", stdin);
    freopen(R"(C:\Users\ds\CLionProjects\untitled3\aout.txt)", "w", stdout);
#endif
    solve();
#ifdef Debugg
    cout << '\n' << (double) clock() / CLOCKS_PER_SEC;
#endif
}